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
#include "ADC.h"
#include "TI1.h"
#include "Hall.h"
#include "PWM1.h"
#include "Cap1.h"
#include "Iluminacion.h"
#include "Ventilacion.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/* User includes (#include below this line is not maintained by Processor Expert) */
#include "Events.h"
#include "ProcessorExpert.h"

/*Constantes*/
#define ACELEROMETRO 0
#define TEMPERATURA 1

#define RANGO_ULTRASONIDO 8000 //valor por experimentacion

/*Inicializacion de la maquina de estados*/
unsigned char estado = ESPERAR;

//variables para el protocolo de comunicacion
unsigned int acelerometro;
unsigned int temperatura;
unsigned int ultrasonido;
bool digitalUno;
bool digitalDos;
unsigned char error;
unsigned int bytesEnviados;
unsigned char mensaje[5];
unsigned char recibe;


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
	  		  //do nothing
	  		  break;
	  	  
	  	  case MEDIR:
	  		  error = ADC_MeasureChan(TRUE,ACELEROMETRO);
	  		  error = ADC_GetChanValue(ACELEROMETRO,&acelerometro);
	  		  error = ADC_MeasureChan(TRUE,TEMPERATURA);
	  		  error = ADC_GetChanValue(TEMPERATURA,&temperatura);
	  		  
	  		  digitalUno = Hall_GetVal();
	  				 
	  		  estado = ENVIAR;
	  		  break;
	  	  
	  	  case ENVIAR:
	  		  /*FORMACION DE TRAMA*/
	  		  mensaje[0] = 0xF0+NRO_CANALES;  //Byte que dice la cantidad de canales
	  		  mensaje[1] = (acelerometro>>7) & 0x1F;
	  		  mensaje[2] = (acelerometro) & 0x7F;
	  		  mensaje[3] = (temperatura>>7) & 0x1F;
	  		  mensaje[4] = (temperatura) & 0x7F;
	  		  
	  		  //Trama para los sensores digitales
	  		  if (digitalUno == FALSE){
	  			  mensaje[1] = mensaje[1] & 0x3F;
	  		  }else
	  		  	  mensaje[1] = mensaje[1] | 0x40; 
	  		  if (digitalDos == FALSE){
	  			  mensaje[1] = mensaje[1] & 0x5F;
	  		  }else{
	  			  mensaje[1] = mensaje[1] | 0x20;
	  			 
	  		  }
	  		  //Envio de la trama
	  		  error = AS1_SendBlock(mensaje,1+2*NROCANALES,&bytesEnviados);
	  		  /*WRAP TRAMA*/
	  		  estado = ESPERAR;
	  		  break;
	  	  
	  	  case RECIBIR:
	  		  error = AS1_RecvChar(&recibe); //Recibe en ASCII se convierte a binario
	  		  recibe = recibe - 48;
	  		  
	  		  switch (recibe){
	  		  	  case 0:
	  		  		Iluminacion_PutVal(1);
	  		  		Ventilacion_PutVal(1);
	  		  		break;
	  		  	  case 1:
	  		  		Iluminacion_PutVal(0);
	  		  		Ventilacion_PutVal(1);
	  		  		break;
	  		  	  case 2:
	  		  		Iluminacion_PutVal(1);
	  		  		Ventilacion_PutVal(0);
	  		  		break;
	  		  	  case 3:
	  		  		Iluminacion_PutVal(0);
	  		  		Ventilacion_PutVal(0);
	  		  		break;
	  		  	  default:
	  		  		  break;
	  		  }
	  		  estado = ESPERAR;
	  		  break;
	  	  
	  	  case CAPTURAR:
	  		  error = Cap1_GetCaptureValue(&ultrasonido);
	  		  
	  		  if(ultrasonido<RANGO_ULTRASONIDO){
	  			  digitalDos=TRUE; //bandera que indica que el sensor detecto algun movimiento
	  		  }
	  		  else
	  			  digitalDos=FALSE;
	  		  
	  		  estado = MEDIR;
	  	  
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
