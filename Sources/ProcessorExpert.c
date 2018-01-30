/* ###################################################################
**     Filename    : ProcessorExpert.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Version     : Driver 01.12
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-01-24, 12:18, # CodeGen: 0
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
#include "AS1.h"
#include "AD1.h"
#include "TI1.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Events.h"
#include "ProcessorExpert.h"

/*Inicializacion de la maquina de estados*/
unsigned char estado = ESPERAR;

//variables para el protocolo de comunicacion
unsigned int valorADC;
unsigned char error;
unsigned int bytesEnviados = 3;
unsigned char mensaje[3];


void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  for(;;) { 
	  switch(estado){
	  	  case ESPERAR:
	  		  break;
	  	  case MEDIR:
	  		  AD1_Measure(TRUE);
	  		  error = AD1_GetValue(&valorADC);
	  		  estado = ENVIAR;
	  		  break;
	  	  case ENVIAR:
	  		  mensaje[0] = 0xF1;
	  		  mensaje[1] = (valorADC>>7) & 0x1F;
	  		  mensaje[2] = (valorADC) & 0x7F;
	  		  error = AS1_SendBlock(mensaje,3,&bytesEnviados);
	  		  estado = ESPERAR;
	  		  break;
	  	  default:
	  		  break;
	  }
  }

  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END ProcessorExpert */
/*!
** @}
*/
