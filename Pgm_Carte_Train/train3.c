/*----------------------------------------------------------------------------
 *      Librairie Multi-tâche pour le train 3
 *			v1.0 - mars 2016
 *			RC
 *---------------------------------------------------------------------------*/
#include "LPC17xx.h"                    												// Device header
#include "cmsis_os.h"                                           // CMSIS RTOS header file

//define pour récupérer les entrées M3, A3, B3 et C3
#define capteurs_train3 (LPC_GPIO1->FIOPIN & ((1<<10)|(1<<11)|(1<<12)|(1<<13)))

void train3 (void const *argument);                             // thread function
osThreadId tid_train3;                                          // thread id
osThreadDef (train3, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread_train3 (void) {

  tid_train3 = osThreadCreate (osThread(train3), NULL);
  if (!tid_train3) return(-1);
  
  return(0);
}

void Init_GPIO_train3(void)
{
	/*
	entrées:
		M3 --> P1.26
		A3 --> P1.25
		B3 --> P1.24
		C3 --> P1.23
	
		Sd3_4 --> P1.21
		Sg3_4 --> P1.20
	
	sorties:
		ON3	  --> P2.3
		AVAR3 --> P2.4
	*/
	
	//desactive les R internes de P1.20, P1.21, P1.23, P1.24, P1.25 et P1.26
	LPC_PINCON->PINMODE3 |= (2<<20) | (2<<22) | (2<<24) | (2<<26);
	
	//desactive les R internes de P2.3 et P2.4
	LPC_PINCON->PINMODE4 |= (2<<6) | (2<<8);
	
	//P2.3 et P2.4 en sorties
	LPC_GPIO2->FIODIR |= (1<<3) | (1<<4);
	
	//pas d'IRQ pour GPIO1
}

void Arret_train3(void)
{
	//ON3 et AVAR3 mis à 0
	LPC_GPIO2->FIOCLR = (1<<3) | (1<<4);
}

void Avant_train3(void)
{
	//ON3 mis à 1
	//AVAR3 mis à 0
	LPC_GPIO2->FIOSET = (1<<3);
	LPC_GPIO2->FIOCLR = (1<<4);
}

void Arriere_train3(void)
{
	//ON3 et AVAR3 mis à 1
	LPC_GPIO2->FIOSET = (1<<3) | (1<<4);
}


void train3 (void const *argument) {

	Init_GPIO_train34();
	
  while (1) {
    //code pour gérer le fonctionnement du train
  }
}
