/*----------------------------------------------------------------------------
 *      Librairie Multi-tâche pour le train 4
 *			v1.0 - mars 2016
 *			RC
 *---------------------------------------------------------------------------*/
#include "LPC17xx.h"                    												// Device header
#include "cmsis_os.h"                                           // CMSIS RTOS header file

//define pour récupérer les entrées M4, A4, B4 et C4
#define capteurs_train4 (LPC_GPIO0->FIOPIN & ((1<<20)|(1<<21)|(1<<22)|(1<<23)))

void train4 (void const *argument);                             // thread function
osThreadId tid_train4;                                          // thread id
osThreadDef (train4, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread_train4 (void) {

  tid_train4 = osThreadCreate (osThread(train4), NULL);
  if (!tid_train4) return(-1);
  
  return(0);
}

void Init_GPIO_train4(void)
{
	/*
	entrées:
		M4 --> P0.23
		A4 --> P0.22
		B4 --> P0.21
		C4 --> P0.20
	
		S4_3 		--> =B4 --> P2.11		
		S4_3_2 	--> P0.24								
		S4_2_1	--> P0.26									(penser à enlever le jumper SPK) 
		S4_1		--> P0.25 								(penser à enlever le jumper du potentiomètre)
	
	sorties:
		ON4 	--> P1.31						
		AVAR4 --> P2.2
	*/
	
	//desactive les R internes de P0.26
	LPC_PINCON->PINMODE1 |= (2<<20);
	
	//desactive les R internes de P0.24 et P0.25
	LPC_PINCON->PINMODE1 |= (2<<16) | (2<<18);
	
	//desactive les R internes de P0.20 à P0.23
	LPC_PINCON->PINMODE1 |= (2<<8) | (2<<10) | (2<<12) | (2<<14);
	
	//desactive les R internes de P1.31 et P2.2
	LPC_PINCON->PINMODE3 |= 0x80000000;
	LPC_PINCON->PINMODE4 |= (2<<4);
	
	//P1.31 et P2.2 en sorties
	LPC_GPIO1->FIODIR |= 0x80000000;
	LPC_GPIO2->FIODIR |= (1<<2);
	
	//active les IRQ sur front montant pour P0.20 à P0.23 et P0.25 et P0.26
	LPC_GPIOINT->IO0IntEnR |= (1<20) | (1<<21) | (1<<22) | (1<<23) | (1<<25) | (1<<26);
}

void Arret_train4(void)
{
	//ON4 mis à 0
	//AVAR4 mis à 0
	LPC_GPIO1->FIOCLR = 0x80000000;
	LPC_GPIO2->FIOCLR = (1<<2);
}

void Avance_train4(void)
{
	//ON4 mis à 1
	//AVAR4 mis à 0
	LPC_GPIO1->FIOSET = 0x80000000;
	LPC_GPIO2->FIOCLR = (1<<2);
}

void Recule_train4(void)
{
	//ON4 mis à 1
	//AVAR4 mis à 1
	LPC_GPIO1->FIOSET = 0x80000000;
	LPC_GPIO2->FIOSET = (1<<2);
}


void train4 (void const *argument) {

	char etat4 = 0;
	Init_GPIO_train4();
	
  while (1) {
    //code pour gérer le fonctionnement du train 4
		
		//exemple non adapté pour un RTOS
		//méthode MAE
		switch (etat4){
			
			case 0: //train arrêté: attente d'appui sur M4 et train en A4
							Arret_train4() ;
							if (capteurs_train4 == ((1<<23)|(1<<22))) {etat4 = 1;}
							break;
							
			case 1: //train avance: attente arrivée en B4
							Avance_train4() ;
							if ((capteurs_train4 & (1<<21)) == (1<<21)) {etat4 = 2;}
							break;				
			
			case 2: //train recule: attente arrivée en A4
							Recule_train4() ;
							if ((capteurs_train4 & (1<<22)) == (1<<22)) {etat4 = 3;}
							break;			
			
			case 3: //train avance: attente arrivée en C4
							Avance_train4() ;
							if ((capteurs_train4 & (1<<20)) == (1<<20)) {etat4 = 4;}
							break;	
			
			case 4: //train recule: attente arrivée en A4
							Recule_train4() ;
							if ((capteurs_train4 & (1<<22)) == (1<<22)) {etat4 = 0;}
							break;
			
			default: break;
		}
  }
}
