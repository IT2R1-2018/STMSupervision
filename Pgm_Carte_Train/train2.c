/*----------------------------------------------------------------------------
 *      Librairie Multi-tâche pour le train 2
 *			v1.0 - mars 2016
 *			RC
 *---------------------------------------------------------------------------*/
#include "LPC17xx.h"                    												// Device header
#include "cmsis_os.h"                                           // CMSIS RTOS header file

//define pour récupérer les entrées M2, A2, B2 et C2
#define capteurs_train2 (LPC_GPIO0->FIOPIN & ((1<<20)|(1<<21)|(1<<22)|(1<<23)))
 
void train2 (void const *argument);                             // thread function
osThreadId tid_train2;                                          // thread id
osThreadDef (train2, osPriorityNormal, 1, 0);                   // thread object

int Init_Thread_train2 (void)
{
  tid_train2 = osThreadCreate (osThread(train2), NULL);
  if (!tid_train2) return(-1);
  
  return(0);
}

void Init_GPIO_train2(void)
{
	/*
	entrées:
		M2 --> P0.23
		A2 --> P0.22
		B2 --> P0.21
		C2 --> P0.20
	
		Sd2_4 --> P0.10
		Sg2_4 --> P0.15
	
	sorties:
		ON2 	--> P1.28
		AVAR2 --> P1.29
	*/
	
	//désactive les R internes de P0.10 et P0.15
	LPC_PINCON->PINMODE0 |= (2<<20) | 0x80000000;
	
	//désactive les R internes de P0.20, P0.21, P0.22 et P0.23
	LPC_PINCON->PINMODE1 |= (2<<8) | (2<<10) | (2<<12) | (2<<14);
	
	//désactive les R internes de P1.28 et P1.29
	LPC_PINCON->PINMODE3 |= (2<<24) | (2<<26);
	
	//P1.28 et P1.29 en sorties
	LPC_GPIO1->FIODIR |= (1<<28) | (1<<29);
	
	//active les IRQ sur front montant pour P0.10, P0.15, P0.20, P0.21, P0.22 et P0.23
	//LPC_GPIOINT->IO0IntEnR |= (1<<10) | (1<<15) | (1<<20) | (1<<21) | (1<<22) | (1<<23);
}

void Arret_train2(void)
{
	//ON2 et AVAR2 mis à 0
	LPC_GPIO1->FIOCLR = (1<<28) | (1<<29);
}

void Avant_train2(void)
{
	//ON2 mis à 1
	//AVAR2 mis à 0
	LPC_GPIO1->FIOCLR = (1<<29);
	LPC_GPIO1->FIOSET = (1<<28);
}

void Arriere_train2(void)
{
	//ON2 et AVAR2 mis à 1
	LPC_GPIO1->FIOSET = (1<<28) | (1<<29);
}


void train2 (void const *argument)
{
	Init_GPIO_train2();
	
  while (1)
	{
    //code pour gérer le fonctionnement du train
		
  }
}
