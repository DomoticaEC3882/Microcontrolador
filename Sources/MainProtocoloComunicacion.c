/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-01-29, 09:39, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file ProcessorExpert.c
** @version 01.12
** @brief
**         Main module.
**         This module contains user's application code.
*/         
/*!
**  @addtogroup ProcessorExpert_module ProcessorExpert module documentation
**  @{
*/         
/* MODULE ProcessorExpert */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "TI1.h"
#include "Bit1.h"
#include "AS1.h"
#include "AD1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/*Inicializacion de la maquina de estados*/
unsigned char estado = ESPERAR;

/*Para el Protocolo de Comunicacion*/
extern unsigned char arreglo[3]={0xF2,0x00,0x00}; //Declaracion del arreglo de 3 elementos (El primer elemento es 0xF2 porque son dos canales mixtos)
extern unsigned int enviado = 3; //Declaracion de enviado para hacer el SendBlock (Se coloco int=3 porque son 3 bytes que vamos a mandar en el arreglo)


/* User includes (#include below this line is not maintained by Processor Expert) */

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;) {
  	  switch (estado){
  	  	  case ESPERAR:
  	  		  break;
  	  	  case MEDIR:
  	  		  banderaError = AD1_Measure(TRUE);
  	  		  banderaError = AD1_GetValue16(&valorADC);
  	  		  arreglo[1] = (valorADC>>7) & 0x1F; //Este es el arreglo b, que contiene 0D1D2A1A1A1A1A1. Es decir, 1 bit del sensor Binario 1; 1 bit del Sensor Binario 2 y 5 del sensor Analogico 1
  	  		  arreglo[2] = (valorADC) & 0x7F;
  	  		  //banderaError = AD1_GetValue16(&valorADC);
  	  		  //valorCharPotenciometro[0] = (valorADC>>8) & (0xFF);
  	  		  //valorCharPotenciometro[1] = (valorADC) & (0xFF);
  	  		  estado = ENVIAR;
  	  		  break;
  	  	  case ENVIAR:
  	  		  //AS1_SendBlock(valorCharPotenciometro,1,&enviado1);
  	  		  //AS1_SendChar(valorCharPotenciometro[0]);
  	  		  //AS1_SendBlock(valorCharPotenciometro,1,&enviado1);
  	  		  AS1_SendBlock(arreglo,3,&enviado);
  	  		  estado = ESPERAR;
  	  		  break;
  	  	  default:
  	  		  break;
  	  }
    }
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.08]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
