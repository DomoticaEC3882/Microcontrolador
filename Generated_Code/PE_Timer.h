/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PE_Timer.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : PE_Timer
**     Version     : Driver 01.04
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-02-28, 14:21, # CodeGen: 68
**     Abstract    :
**         This module "PE_Timer" implements internal methods and definitions
**         used by components working with timers.
**     Settings    :
**     Contents    :
**         No public methods
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PE_Timer.h
** @version 01.04
** @brief
**         This module "PE_Timer" implements internal methods and definitions
**         used by components working with timers.
*/         
/*!
**  @addtogroup PE_Timer_module PE_Timer module documentation
**  @{
*/         
#ifndef __PE_Timer
#define __PE_Timer
/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Const.h"

/* MODULE PE_Timer. */

void PE_Timer_LngMul(dword va1, dword va2, dlong *var);
/*
** ===================================================================
**     Method      :  PE_Timer_LngMul (component PE_Timer)
**
**     Description :
**         The method multiplies two 32 bit values and returns pointer to 
**         64 bit result.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool PE_Timer_LngHi2(dword High, dword Low, word *Out);
/*
** ===================================================================
**     Method      :  PE_Timer_LngHi2 (component PE_Timer)
**
**     Description :
**         The method transfers 64 bit result to 16 bit ratio value and 
**         returns overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/

bool PE_Timer_LngHi3(dword High, dword Low, word *Out);
/*
** ===================================================================
**     Method      :  PE_Timer_LngHi3 (component PE_Timer)
**
**     Description :
**         The method transfers 64 bit result to 16 bit ratio value and 
**         returns overflow flag.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


#endif /* END PE_Timer. */
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
