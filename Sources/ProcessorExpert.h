/*
 * ProcessorExpert.h
 *
 *  Created on: Jan 24, 2018
 *      Author: Diego
 */

#ifndef PROCESSOREXPERT_H_
#define PROCESSOREXPERT_H_

//Constantes
#define NRO_CANALES 0x02
#define NROCANALES 2

//Constantes para la maquina de estados
#define ESPERAR 0
#define MEDIR 	1
#define ENVIAR 	2
#define RECIBIR 3


//Variables para la maquina de estados
extern unsigned char estado;




#endif /* PROCESSOREXPERT_H_ */
