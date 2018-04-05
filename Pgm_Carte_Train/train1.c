/*----------------------------------------------------------------------------
 *      Librairie Multi-t�che pour le train 1
 *			v1.0 - mars 2016
 *			RC
 *---------------------------------------------------------------------------*/
#include "LPC17xx.h"                    												// Device header
#include "cmsis_os.h"                                           // CMSIS RTOS header file

//define pour r�cup�rer les entr�es M1, A1, B1 et C1
#define capteurs_train1 (LPC_GPIO0->FIOPIN & ((1<<16)|(1<<17)|(1<<18)|(1<<19)))
 
void train1 (void const *argument);                             // thread function
osThreadId tid_train1;                                          // thread id
osThreadDef (train1, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread_train1 (void)
{
  tid_train1 = osThreadCreate (osThread(train1), NULL);
  if (!tid_train1) return(-1);
  
  return(0);
}

void Init_GPIO_train1(void)
{
	/*
	entr�es:
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
	
	//d�sactive les R internes de P0.11
	LPC_PINCON->PINMODE0 |= (2<<22);
	
	//d�sactive les R internes de P0.16, P0.17, P0.18 et P0.19
	LPC_PINCON->PINMODE1 |= (2<<0) | (2<<2) | (2<<4) | (2<<6);
	
	//d�sactive les R internes de P2.5 et P2.6
	LPC_PINCON->PINMODE4 |= (2<<10) | (2<<12);
	
	//P2.5 et P2.6 en sorties
	LPC_GPIO2->FIODIR |= (1<<5) | (1<<6);
	
	//active les IRQ sur front montant pour P0.11, P0.16, P0.17, P0.18 et P0.19
	LPC_GPIOINT->IO0IntEnR |= (1<<11) | (1<<16) | (1<<17) | (1<<18) | (1<<19);
}

void Arret_train1(void)
{
	//ON1 et AVAR1 mis � 0
	LPC_GPIO2->FIOCLR = (1<<5) | (1<<6);
}

void Avance_train1(void)
{
	//ON1 mis � 1
	//AVAR1 mis � 0
	LPC_GPIO2->FIOCLR = (1<<6);
	LPC_GPIO2->FIOSET = (1<<5);
}

void Recule_train1(void)
{
	//ON1 et AVAR1 mis � 1
	LPC_GPIO2->FIOSET = (1<<5) | (1<<6);
}


void train1 (void const *argument)
{
	char etat1 = 0;
	Init_GPIO_train1();
	
  while (1)
	{
    //code pour g�rer le fonctionnement du train 1
		
		//exemple non adapt� pour un RTOS
		//m�thode MAE
		switch (etat1){
			
			case 0: //train arr�t�: attente d'appui sur M1 et train en A1
							Arret_train1() ;
							if (capteurs_train1 == ((1<<18)|(1<<19))) {etat1 = 1;}
							break;
							
			case 1: //train avance: attente arriv�e en B1
							Avance_train1() ;
							if ((capteurs_train1 & (1<<17)) == (1<<17)) {etat1 = 2;}
							break;				
			
			case 2: //train recule: attente arriv�e en A1
							Recule_train1() ;
							if ((capteurs_train1 & (1<<18)) == (1<<18)) {etat1 = 3;}
							break;			
			
			case 3: //train avance: attente arriv�e en C1
							Avance_train1() ;
							if ((capteurs_train1 & (1<<16)) == (1<<16)) {etat1 = 4;}
							break;	
			
			case 4: //train recule: attente arriv�e en A1
							Recule_train1() ;
							if ((capteurs_train1 & (1<<18)) == (1<<18)) {etat1 = 0;}
							break;
			
			default: break;
		}
  }
}
