/*----------------------------------------------------------------------------
 *      Librairie Multi-tâche pour le train 1
 *			v1.0 - mars 2017
 *			RC/XM
 *---------------------------------------------------------------------------*/
#include "LPC17xx.h"                    												// Device header
#include "cmsis_os.h"                                           // CMSIS RTOS header file
#include "rl_net.h"

#include "Board_GLCD.h"                 // ::Board Support:Graphic LCD
#include "GLCD_Config.h"                // Keil.MCB1700::Board Support:Graphic LCD
#include "stdio.h"

extern GLCD_FONT GLCD_Font_6x8;
extern GLCD_FONT GLCD_Font_16x24;

//define pour récupérer les entrées M1, A1, B1 et C1
#define capteurs_train1 (LPC_GPIO0->FIOPIN & ((1<<16)|(1<<17)|(1<<18)|(1<<19)))

extern char direction;
extern char position;
extern int32_t udp_sock;                       // UDP socket handle
 
void train1 (void const *argument);                             // thread function
osThreadId tid_train1;                                          // thread id
osThreadDef (train1, osPriorityNormal, 1, 0);                   // thread object

void train1_envoiUDP (void const *argument);                             // thread function
osThreadId tid_train1_envoiUDP;                                          // thread id
osThreadDef (train1_envoiUDP, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread_train1 (void)
{
  tid_train1 = osThreadCreate (osThread(train1), NULL);
  if (!tid_train1) return(-1);
	
	tid_train1_envoiUDP = osThreadCreate (osThread(train1_envoiUDP), NULL);
  if (!tid_train1_envoiUDP) return(-1);
  
  return(0);
}

void Init_GPIO_train1(void)
{
	/*
	entrées:
		M1 --> P0.19
		A1 --> P0.18
		B1 --> P0.17
		C1 --> P0.16
	
		Sd1_4 --> =B1 --> P0.17
		Sg1_4 --> P0.11
	
	sorties:
		ON1 	--> P2.5
		AVAR1 --> P2.6
	*/
	
	//désactive les R internes de P0.11
	LPC_PINCON->PINMODE0 |= (2<<22);
	
	//désactive les R internes de P0.16, P0.17, P0.18 et P0.19
	LPC_PINCON->PINMODE1 |= (2<<0) | (2<<2) | (2<<4) | (2<<6);
	
	//désactive les R internes de P2.5 et P2.6
	LPC_PINCON->PINMODE4 |= (2<<10) | (2<<12);
	
	//P2.5 et P2.6 en sorties
	LPC_GPIO2->FIODIR |= (1<<5) | (1<<6);
	
	//active les IRQ sur front montant pour P0.11, P0.16, P0.17, P0.18 et P0.19
	LPC_GPIOINT->IO0IntEnR |= (1<<11) | (1<<16) | (1<<17) | (1<<18) | (1<<19);
}

void Arret_train1(void)
{
	//ON1 et AVAR1 mis à 0
	LPC_GPIO2->FIOCLR = (1<<5) | (1<<6);
}

void Avance_train1(void)
{
	//ON1 mis à 1
	//AVAR1 mis à 0
	LPC_GPIO2->FIOCLR = (1<<6);
	LPC_GPIO2->FIOSET = (1<<5);
}

void Recule_train1(void)
{
	//ON1 et AVAR1 mis à 1
	LPC_GPIO2->FIOSET = (1<<5) | (1<<6);
}

// tache pilotage de train
void train1 (void const *argument)
{
	char texte[20];
	Init_GPIO_train1();
	
  while (1)
	{
    //code pour gérer le fonctionnement du train 1
		
		switch (direction){
			
			
			case 1: //train avance
							Avance_train1();
							sprintf(texte,"avance");
							break;				
			
			case 2: //train recule
							Recule_train1() ;
							sprintf(texte,"recule");
							break;			
			
			case 3: //train arret
							Arret_train1() ;
							sprintf(texte,"arret   ");
							break;	

			default: break;
		}
		
		GLCD_DrawString(1,1,texte);
		osDelay(100);
  }
}

// tache pilotage de train
void train1_envoiUDP (void const *argument)
{
	 NET_ADDR addr = { NET_ADDR_IP4, 2000, 192, 168, 0, 110 };
	 uint8_t *sendbuf;
	 char texte[20];
	 int i;
	 
	 while (1){
	 
	osSignalWait(0x02,osWaitForever);		// sommeil attente capteur
//		 sprintf(texte,"capteur !");
//		 GLCD_DrawString(1,50,texte);
	// envoi UDP
	if (udp_sock > 0) {

    sendbuf = netUDP_GetBuffer (1);
		sendbuf[0]=position;
 
    netUDP_Send (udp_sock, &addr, sendbuf, 1);	
  }
	osDelay(1000);
	
}
	
}
