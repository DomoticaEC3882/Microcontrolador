/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : Vectors.c
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Version     : Component 01.003, Driver 01.40, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-04-06, 10:39, # CodeGen: 125
**     Abstract    :
**         This component "MC9S08QE128_80" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
**     Settings    :
**
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file Vectors.c                                                  
** @version 01.40
** @brief
**         This component "MC9S08QE128_80" contains initialization 
**         of the CPU and provides basic methods and events for 
**         CPU core settings.
*/         
/*!
**  @addtogroup Vectors_module Vectors module documentation
**  @{
*/         


#include "Cpu.h"
#include "AS1.h"
#include "ADC.h"
#include "TI1.h"
#include "Hall.h"
#include "PWM1.h"
#include "Cap1.h"
#include "Iluminacion.h"
#include "Ventilacion.h"

/*lint -save  -e950 Disable MISRA rule (1.1) checking. */
static void (* near const _vect[])(void) @0xFFC0 = { /* Interrupt vector table */
/*lint -restore Enable MISRA rule (1.1) checking. */
         PWM1_Interrupt,               /* Int.no. 31 Vtpm3ovf (at FFC0)              Used */
         Cpu_Interrupt,                /* Int.no. 30 Vtpm3ch5 (at FFC2)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 29 Vtpm3ch4 (at FFC4)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 28 Vtpm3ch3 (at FFC6)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 27 Vtpm3ch2 (at FFC8)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 26 Vtpm3ch1 (at FFCA)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 25 Vtpm3ch0 (at FFCC)              Unassigned */
         TI1_Interrupt,                /* Int.no. 24 Vrtc (at FFCE)                  Used */
         Cpu_Interrupt,                /* Int.no. 23 Vsci2tx (at FFD0)               Unassigned */
         Cpu_Interrupt,                /* Int.no. 22 Vsci2rx (at FFD2)               Unassigned */
         Cpu_Interrupt,                /* Int.no. 21 Vsci2err (at FFD4)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 20 Vacmpx (at FFD6)                Unassigned */
         ADC_Interrupt,                /* Int.no. 19 Vadc (at FFD8)                  Used */
         Cpu_Interrupt,                /* Int.no. 18 Vkeyboard (at FFDA)             Unassigned */
         Cpu_Interrupt,                /* Int.no. 17 Viicx (at FFDC)                 Unassigned */
         AS1_InterruptTx,              /* Int.no. 16 Vsci1tx (at FFDE)               Used */
         AS1_InterruptRx,              /* Int.no. 15 Vsci1rx (at FFE0)               Used */
         AS1_InterruptError,           /* Int.no. 14 Vsci1err (at FFE2)              Used */
         Cpu_Interrupt,                /* Int.no. 13 Vspi1 (at FFE4)                 Unassigned */
         Cpu_Interrupt,                /* Int.no. 12 Vspi2 (at FFE6)                 Unassigned */
         Cpu_Interrupt,                /* Int.no. 11 Vtpm2ovf (at FFE8)              Unassigned */
         Cpu_Interrupt,                /* Int.no. 10 Vtpm2ch2 (at FFEA)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  9 Vtpm2ch1 (at FFEC)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  8 Vtpm2ch0 (at FFEE)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  7 Vtpm1ovf (at FFF0)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  6 Vtpm1ch2 (at FFF2)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  5 Vtpm1ch1 (at FFF4)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  4 Vtpm1ch0 (at FFF6)              Unassigned */
         Cpu_Interrupt,                /* Int.no.  3 Vlvd (at FFF8)                  Unassigned */
         Cpu_Interrupt,                /* Int.no.  2 Virq (at FFFA)                  Unassigned */
         Cpu_SWIInterrupt,             /* Int.no.  1 Vswi (at FFFC)                  Used */
         _EntryPoint                   /* Int.no.  0 Vreset (at FFFE)                Reset vector */
};
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

