/*----------------------------------------------------------------------------
 * CMSIS-RTOS 'main' function template
 *---------------------------------------------------------------------------*/


#include "LPC17xx.h"                    		// Device header
#include "cmsis_os.h"                       // CMSIS RTOS header file
#include "rl_net.h"
#include "Board_GLCD.h"                 // ::Board Support:Graphic LCD
#include "GLCD_Config.h"                // Keil.MCB1700::Board Support:Graphic LCD

extern GLCD_FONT GLCD_Font_6x8;
extern GLCD_FONT GLCD_Font_16x24;

int32_t udp_sock;                       // UDP socket handle
void send_udp_data (void) ; 

char direction;

extern int Init_Thread_train1(void);

// fonction callback sur réception trame UDP port 2000
uint32_t udp_cb_func (int32_t socket, const  NET_ADDR *addr, const uint8_t *buf, uint32_t len) {
 
	int i;
	
	// on va récupérer les éléments de direction du train
//	for (i=0;i<len;i++)	data_recue[i]=buf[i];		// récupération data recues
//	longueur = len;		// recup taille
//	addrIP_client=*addr;		// récupération info client
//	send_udp_data();		// on lance fonction d'envoi
	switch (buf[0]) {
		
		case 0x01:	direction = 1;			// avant
								break;
		
		case 0x02:	direction = 2;			// arriere
								break;
		
		case 0x03:	direction = 3;			// arret
								break;
		
		default : break;
	}
	
  return (0);
}

/*
 * main: initialize and start the system
 */
int main (void)
{
	
	direction = 0;
  osKernelInitialize ();                    // initialize CMSIS-RTOS

	// validation IT EINT3
	NVIC_EnableIRQ(EINT3_IRQn);
	
  // initialize peripherals here
	GLCD_Initialize();
	GLCD_ClearScreen();
	GLCD_SetFont(&GLCD_Font_16x24);
	 netInitialize ();
 
  // Initialize UDP socket and open port 2000
  udp_sock = netUDP_GetSocket (udp_cb_func);
  if (udp_sock > 0) {
    netUDP_Open (udp_sock, 2000);
  }	
	
	//Création de la tâche de gestion du train1
	Init_Thread_train1();

  osKernelStart ();                         // start thread execution 
}
