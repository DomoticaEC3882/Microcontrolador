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
#include "Bit1.h"
#include "Bit2.h"
#include "PWM1.h"
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
bool digitalUno;
bool digitalDos;
unsigned char error;
unsigned int bytesEnviados = 5;
unsigned char mensaje[5];


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
	  		  digitalUno = Bit1_GetVal();
	  		  digitalDos = Bit2_GetVal();
	  		  estado = ENVIAR;
	  		  break;
	  	  case ENVIAR:
	  		  /*FORMACION DE TRAMA*/
	  		  mensaje[0] = 0xF0+NRO_CANALES;  //Byte que dice la cantidad de canales
	  		  mensaje[1] = (valorADC>>7) & 0x1F;
	  		  mensaje[2] = (valorADC) & 0x7F;
	  		  mensaje[3] = (valorADC>>7) & 0x1F;
	  		  mensaje[4] = (valorADC) & 0x7F;
	  		  
	  		  //Trama para los sensores digitales
	  		  if (digitalUno == FALSE){
	  			  mensaje[1] = mensaje[1] | 0x40; 
	  		  }else
	  			  mensaje[1] = mensaje[1] & 0x3F;
	  		  if (digitalDos == FALSE){
	  			  mensaje[1] = mensaje[1] | 0x20; 
	  		  }else{
	  			  mensaje[1] = mensaje[1] & 0x5F;
	  		  }
	  		  //Envio de la trama
	  		  error = AS1_SendBlock(mensaje,1+2*NROCANALES,&bytesEnviados);
	  		  /*WRAP TRAMA*/
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
