#include "LPC17xx.h"                    		// Device header
#include "cmsis_os.h"                       // CMSIS RTOS header file

extern osThreadId tid_train1_envoiUDP;

char position;
extern char direction;

void EINT3_IRQHandler(void)
{
	
	//test si IRQ déclenché par front montant du bouton B1
	if ((LPC_GPIOINT->IO0IntStatR & 1<<17)==(1<<17))
	{
		//baisse le drapeau correspondant
		LPC_GPIOINT->IO0IntClr = 1<<17;

		position = 'B';
	}
	
	//+gestion des autres capteurs...
	//test si IRQ déclenché par front montant du bouton A1
	if ((LPC_GPIOINT->IO0IntStatR & 1<<18)==(1<<18))
	{
		//baisse le drapeau correspondant
		LPC_GPIOINT->IO0IntClr = 1<<18;
		direction = 1;
		position = 'A';
	
	}
	
	//test si IRQ déclenché par front montant du bouton Sg 1-4
	if ((LPC_GPIOINT->IO0IntStatR & 1<<11)==(1<<11))
	{
		//baisse le drapeau correspondant
		LPC_GPIOINT->IO0IntClr = 1<<11;
		direction = 2;
		position = 'C';
	}
	
	// on réveille la tache en sommeil sur attente capteur
	osSignalSet(tid_train1_envoiUDP,1<<1);
	
	
}