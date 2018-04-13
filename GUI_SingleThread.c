#define osObjectsPublic
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
#include "osObjects.h"
#include "string.h"
#include "stdlib.h"


extern const GUI_BITMAP * apbmloco_petit[1];
extern const unsigned     aDelayloco_petit[1];

int32_t udp_sock;                       // UDP socket handle
int position_train;
extern ARM_DRIVER_USART Driver_USART6;					//déclaration de la structure pour l'USART2

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
void ThreadT (void const *argument);
void ThreadR (void const *argument);
osThreadId tid_GUIThread;                           // thread id
osThreadId tid_ThreadT;
osThreadId tid_ThreadR;
osThreadDef (GUIThread, osPriorityIdle, 1, 2048);   // thread object
osThreadDef (ThreadT, osPriorityNormal, 1, 800);
osThreadDef (ThreadR, osPriorityNormal, 1, 800);
void sendCommand(char * command, int tempo_ms);
void Init_WiFi(void);

int etat;
char RxBuf[200];

int Init_GUIThread (void) {

  tid_GUIThread = osThreadCreate (osThread(GUIThread), NULL);
	tid_ThreadT = osThreadCreate (osThread(ThreadT), NULL);
	tid_ThreadR = osThreadCreate (osThread(ThreadR), NULL);
  if (!tid_GUIThread) return(-1);
  if (!tid_ThreadT) etat=0; else etat=1;
	if (!tid_ThreadR) etat=0; else etat=1;

  return(0);
}

// Notify the user application about UDP socket events : affichage des places de parking dispo ou restantes avec des cercles rouges et verts

void event_UART(uint32_t event)
{
	switch (event) {
		case ARM_USART_EVENT_RECEIVE_COMPLETE : 	osSignalSet(tid_ThreadR, 0x01);
																							break;
		
		
		case ARM_USART_EVENT_SEND_COMPLETE  : 	osSignalSet(tid_ThreadT, 0x02);
																							break;
		
		default : break;
	}
}

uint32_t udp_cb_func (int32_t socket, const  NET_ADDR *addr, const uint8_t *buf, uint32_t len) {
 char c[5];
  switch(buf[0]) {
		case 0xBA :
										GUI_SetFont(&GUI_Font10_1);
										GUI_SetColor(GUI_BLACK);
										GUI_SetTextMode(GUI_TM_NORMAL);
									if((buf[1] & 0x01) ==0x00){
									GUI_DispStringAt("0", 5, 5);
									}
									
									if ((buf[1] & 0x01)==0x01){
									GUI_DispStringAt("1", 5, 5);}
									
									if((buf[1] & 0x10) ==0x00){
									 GUI_DispStringAt("0", 5, 15);}
									 
									if ((buf[1] & 0x10)==0x10){
									 GUI_DispStringAt("1", 5, 15);}
									break;
									
		case 0xCC :
									  GUI_SetFont(&GUI_Font10_1);
										GUI_SetColor(GUI_BLACK);
										GUI_SetTextMode(GUI_TM_NORMAL);
									//sprintf(c,buf[1]);
									//GUI_DispStringAt(buf, 5, 5);
								
									break;
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
	
	Driver_USART6.Initialize(event_UART);
	Driver_USART6.PowerControl(ARM_POWER_FULL);
	Driver_USART6.Control(	ARM_USART_MODE_ASYNCHRONOUS |
							ARM_USART_DATA_BITS_8		|
							ARM_USART_STOP_BITS_1		|
							ARM_USART_PARITY_NONE		|
							ARM_USART_FLOW_CONTROL_NONE,
							115200);
	Driver_USART6.Control(ARM_USART_CONTROL_TX,1);
	Driver_USART6.Control(ARM_USART_CONTROL_RX,1);
}

void Init_WiFi(void){
	
	// reset module
	sendCommand("AT+RST\r\n",7000); 
	
	// disconnect from any Access Point
	sendCommand("AT+CWQAP\r\n",2000); 
	
	sendCommand("AT+CWMODE=3\r\n",2000);
	
  // configure as Station 
	sendCommand("AT+CWJAP=\"it2r1\",\"testit2r\"\r\n",7000);
	
	sendCommand("AT+CIFSR\r\n",2000);
	
	//Connect to YOUR Access Point
	sendCommand("AT+CIPSTART=\"TCP\",\"192.168.0.100\",333\n\r",7000);	
}

void sendCommand(char * command, int tempo_ms)
{
	int len;
	len = strlen (command);
	Driver_USART6.Send(command,len); // send the read character to the esp8266
	osSignalWait(0x02, osWaitForever);		// sommeil fin emission
	osDelay(tempo_ms);		// attente traitement retour
}

void GUIThread (void const *argument) {
	WM_HWIN hDlg;
  int X=20, Tx, Ty, val =0;
	
	GUI_Init();
	Touch_Initialize();
	hDlg = CreateWindow();
	
  /* Add GUI setup code here */
//void Timer1_Callback (void const *arg) {
  GUI_SetFont(&GUI_Font16_1);
	GUI_SetColor(GUI_BLACK);
	GUI_SetTextMode(GUI_TM_NORMAL);
		GUI_DispStringAt("test", 100, 5);
	// Affichage texte
	

  while (1) {
		
		//GUI_Delay(100);		// si pas d'image statique - utilise pour animation
		val=Buttons_GetState();
		Tx = GUI_TOUCH_GetxPhys();
		Ty = GUI_TOUCH_GetyPhys();
		 GUI_SetFont(&GUI_Font16_1);
	GUI_SetColor(GUI_BLACK);
	GUI_SetTextMode(GUI_TM_NORMAL);
		GUI_DispStringAt("test", 100, 5);
		
		
if(val==1)
{
		if (udp_sock > 0) 
					{
    //Envoi UDP
    // IPv4 address: 192.168.0.7
    NET_ADDR addr = { NET_ADDR_IP4, 2000 , 192, 168, 0, 7 };

    uint8_t *sendbuf;	
		
    sendbuf = netUDP_GetBuffer (2);
    sendbuf[0] = 0xBA;
 
    netUDP_Send (udp_sock, &addr, sendbuf, 2); 

					}
		//osDelay(1000);
		
			}
		GUI_Exec();
		osDelay(100);
	}
	

}

void ThreadT (void const* argument)
{
	//char TXchar=0x55;
	
	//while(1)
	//{
	//	while(Driver_USART6.GetStatus().tx_busy == 1); // attente buffer TX vide
	//	Driver_USART6.Send(&TXchar,1);
	//	osDelay(10);
	//}
		
	//char Cmd[30];
	//char ReqHTTP[90];
	Init_WiFi();
	while(1)
	{	osDelay(100);
	}
}


void ThreadR (void const* argument)
{
	
	while(1)
	{
		char RxChar;
	int ligne;
	int i=0;	// i pour position colonne caractère
	
	
  while (1) {
		Driver_USART6.Receive(&RxChar,1);		// A mettre ds boucle pour recevoir 
		osSignalWait(0x01, osWaitForever);	// sommeil attente reception
		
		RxBuf[i]=RxChar;
		i++;
		//Suivant le caractère récupéré
		switch(RxChar)
		{
			case 0x0D: 		//Un retour chariot? On ne le conserve pas...
				i--;
				break;
			case 0x0A:										//Un saut de ligne?
				RxBuf[i-1]=0;											//=> Fin de ligne, donc, on "cloture" la chaine de caractères
				
	//			GLCD_DrawString(1,ligne,RxBuf);	//On l'affiche (peut etre trop long, donc perte des caractères suivants??)
				ligne+=10;										//On "saute" une ligne de l'afficheur LCD
			osDelay(100);
			  if(ligne>240)
				{
					ligne=1;
	//				GLCD_ClearScreen();
					osDelay(2000);
				}
				i=0;													//On se remet au début du buffer de réception pour la prochaine ligne à recevoir
				break;
		}
  }
	}
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

	HAL_Init();                               /* Initialize the HAL Library     */
  BSP_SDRAM_Init();                         /* Initialize BSP SDRAM           */
  SystemClock_Config();                     /* Configure the System Clock     */
	Buttons_Initialize();
	LED_Initialize();
	Touch_Initialize();
  // initialize peripherals here
	netInitialize ();
	Init_UART();
	NVIC_SetPriority(USART6_IRQn,0);

 
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

