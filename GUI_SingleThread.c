
#include "stm32f7xx_hal.h"
#include "stm32746g_discovery_sdram.h"
#include "RTE_Components.h"
#include "cmsis_os.h"                   // ARM::CMSIS:RTOS:Keil RTX
#include "Board_Touch.h"                // ::Board Support:Touchscreen
#include "GUI.h"
#include "stdio.h"
#include "rl_net.h"
#include "DIALOG.h"
#include "Driver_USART.h"               // ::CMSIS Driver:USART
#include "Board_Buttons.h"              // ::Board Support:Buttons
#include "Board_LED.h"                  // ::Board Support:LED


extern const GUI_BITMAP * apbmloco_petit[1];
extern const unsigned     aDelayloco_petit[1];

int32_t udp_sock;                       // UDP socket handle
int position_train;
extern ARM_DRIVER_USART Driver_USART4;					//déclaration de la structure pour l'USART4

#ifdef RTE_CMSIS_RTOS_RTX
extern uint32_t os_time;

uint32_t HAL_GetTick(void) { 
  return os_time; 
}
#endif

/*----------------------------------------------------------------------------
 *      GUIThread: GUI Thread for Single-Task Execution Model
 *---------------------------------------------------------------------------*/
 
WM_HWIN CreateWindow(void);
void GUIThread (void const *argument);              // thread function
osThreadId tid_GUIThread;                           // thread id
osThreadId ID_EnvoiBT;

osThreadDef (GUIThread, osPriorityIdle, 1, 2048);   // thread object
osThreadDef (EnvoiBT, osPriorityNormal, 1, 0);

int Init_GUIThread (void) {

  tid_GUIThread = osThreadCreate (osThread(GUIThread), NULL);
  if (!tid_GUIThread) return(-1);
  
  return(0);
}


// Notify the user application about UDP socket events.

uint32_t udp_cb_func (int32_t socket, const  NET_ADDR *addr, const uint8_t *buf, uint32_t len) {
 
  switch(buf[0]) 
		{

		case 0xBA :
			
									if((buf[1] & 0x01) ==0x00){
									GUI_SetColor(GUI_RED);
									GUI_FillRect(0,218,70,320);}
									
									if ((buf[1] & 0x01)==0x01){
									GUI_SetColor(GUI_GREEN);
									GUI_FillRect(0,218,70,320);}
									
									if((buf[1] & 0x10) ==0x00){
									GUI_SetColor(GUI_RED);
									GUI_FillRect(70,218,140,320); }
									 
									if ((buf[1] & 0x10)==0x10){
									GUI_SetColor(GUI_GREEN);
									GUI_FillRect(70,218,140,320); }
		}

  return (0);
}


/**
  * System Clock Configuration
  *   System Clock source            = PLL (HSE)
  *   SYSCLK(Hz)                     = 200000000
  *   HCLK(Hz)                       = 200000000
  *   AHB Prescaler                  = 1
  *   APB1 Prescaler                 = 4
  *   APB2 Prescaler                 = 2
  *   HSE Frequency(Hz)              = 25000000
  *   PLL_M                          = 25
  *   PLL_N                          = 400
  *   PLL_P                          = 2
  *   PLL_Q                          = 8
  *   VDD(V)                         = 3.3
  *   Main regulator output voltage  = Scale1 mode
  *   Flash Latency(WS)              = 6
  */
static void SystemClock_Config (void) {
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  HAL_RCC_OscConfig(&RCC_OscInitStruct);

  /* Activate the OverDrive to reach the 200 MHz Frequency */
  HAL_PWREx_EnableOverDrive();
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;  
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;  
  HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6);
}



/**
  * Configure the MPU attributes
  */
static void MPU_Config (void) {
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes for SDRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xC0200000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_2MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_DISABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}


/**
  * CPU L1-Cache enable
  */
static void CPU_CACHE_Enable (void) {

  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

void Init_UART(void){
	
	Driver_USART4.Initialize(NULL);
	Driver_USART4.PowerControl(ARM_POWER_FULL);
	Driver_USART4.Control(	ARM_USART_MODE_ASYNCHRONOUS |
							ARM_USART_DATA_BITS_8		|
							ARM_USART_STOP_BITS_1		|
							ARM_USART_PARITY_NONE		|
							ARM_USART_FLOW_CONTROL_NONE,
							9600);
	Driver_USART4.Control(ARM_USART_CONTROL_TX,1);
	Driver_USART4.Control(ARM_USART_CONTROL_RX,1);
}


void GUIThread (void const *argument) {

	WM_HWIN hDlg;
  int X=20, Tx, Ty, val =0, i=0;				//initialisations pour envoi Bluetooth
	char RxBt, delimFin, *ptab;
	
	GUI_Init();
	Touch_Initialize();
	hDlg = CreateWindow();

	//On remplit le tableau avec les caractères qui suivent...

  /* Add GUI setup code here */
//void Timer1_Callback (void const *arg) { 

  while (1) {
		
		//GUI_Delay(100);		// si pas d'image statique - utilise pour animation
		val=Buttons_GetState();
		Tx = GUI_TOUCH_GetxPhys();
		Ty = GUI_TOUCH_GetyPhys();
				
if(val==1)
{
		if (udp_sock > 0) 
					{
     
    // IPv4 address: 192.168.0.7
    NET_ADDR addr = { NET_ADDR_IP4, 2000 , 192, 168, 0, 7 };

    uint8_t *sendbuf;	
		
    sendbuf = netUDP_GetBuffer (2);
    sendbuf[0] = 0xBA;
 
    netUDP_Send (udp_sock, &addr, sendbuf, 2); 

					}
		//osDelay(1000);
		
			}
		GUI_Exec();}
}

/*********************************************************************
*
*       Main
*/
int main (void) {
	position_train = 10;
	
	MPU_Config ();
	CPU_CACHE_Enable();                       /* Enable the CPU Cache           */
  
	osKernelInitialize ();                    // initialize CMSIS-RTOS
	
	ID_EnvoiBT=osThreadCreate(osThreadCreate(EnvoiBT),NULL);					//création tâche envoi Bluetooth

	HAL_Init();                               /* Initialize the HAL Library     */
  BSP_SDRAM_Init();                         /* Initialize BSP SDRAM           */
  SystemClock_Config();                     /* Configure the System Clock     */
	Buttons_Initialize();
	LED_Initialize();
  // initialize peripherals here
	netInitialize ();
	Init_UART();

 
  // Initialize UDP socket and open port 2000
  udp_sock = netUDP_GetSocket (udp_cb_func);
  if (udp_sock > 0) {
    netUDP_Open (udp_sock, 2000);
  }

  // create 'thread' functions that start executing,
  Init_GUIThread();

  osKernelStart ();                         // start thread execution 
	
  osDelay(osWaitForever);
}

/*************************** End of file ****************************/

