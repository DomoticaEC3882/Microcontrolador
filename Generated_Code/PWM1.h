/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : PWM1.h
**     Project     : ProcessorExpert
**     Processor   : MC9S08QE128CLK
**     Component   : PWM
**     Version     : Component 02.240, Driver 01.28, CPU db: 3.00.067
**     Compiler    : CodeWarrior HCS08 C Compiler
**     Date/Time   : 2018-02-28, 15:01, # CodeGen: 73
**     Abstract    :
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
**     Settings    :
**         Used output pin             : 
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       33            |  PTC1_TPM3CH1
**             ----------------------------------------------------
**
**         Timer name                  : TPM3 [16-bit]
**         Counter                     : TPM3CNT   [$0061]
**         Mode register               : TPM3SC    [$0060]
**         Run register                : TPM3SC    [$0060]
**         Prescaler                   : TPM3SC    [$0060]
**         Compare register            : TPM3C1V   [$0069]
**         Flip-flop register          : TPM3C1SC  [$0068]
**
**         User handling procedure     : not specified
**
**         Port name                   : PTC
**         Bit number (in port)        : 1
**         Bit mask of the port        : $0002
**         Port data register          : PTCD      [$0004]
**         Port control register       : PTCDD     [$0005]
**
**         Initialization:
**              Output level           : low
**              Timer                  : Enabled
**              Event                  : Enabled
**         High speed mode
**             Prescaler               : divide-by-16
**             Clock                   : 1048576 Hz
**           Initial value of            period     pulse width
**             Xtal ticks              : 1311       1310
**             microseconds            : 40000      39990
**             milliseconds            : 40         40
**             seconds (real)          : 0.039999961853 0.03999042511
**
**     Contents    :
**         Enable     - byte PWM1_Enable(void);
**         SetRatio16 - byte PWM1_SetRatio16(word Ratio);
**         SetDutyUS  - byte PWM1_SetDutyUS(word Time);
**         SetDutyMS  - byte PWM1_SetDutyMS(word Time);
**
**     Copyright : 1997 - 2013 Freescale Semiconductor, Inc. All Rights Reserved.
**     SOURCE DISTRIBUTION PERMISSIBLE as directed in End User License Agreement.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/
/*!
** @file PWM1.h
** @version 01.28
** @brief
**         This component implements a pulse-width modulation generator
**         that generates signal with variable duty and fixed cycle. 
*/         
/*!
**  @addtogroup PWM1_module PWM1 module documentation
**  @{
*/         

#ifndef __PWM1
#define __PWM1

/* MODULE PWM1. */

/*Include shared modules, which are used for whole project*/
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "PE_Timer.h"
#include "Cpu.h"

#define PWM1_PERIOD_VALUE              0xA3D6U /* Initial period value in ticks of the timer in high speed mode */
#define PWM1_PERIOD_VALUE_HIGH         0xA3D6U /* Period value in ticks of the timer in high speed mode */


byte PWM1_Enable(void);
/*
** ===================================================================
**     Method      :  PWM1_Enable (component PWM)
**     Description :
**         This method enables the component - it starts the signal
**         generation. Events may be generated (<DisableEvent>
**         /<EnableEvent>).
**     Parameters  : None
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte PWM1_SetRatio16(word Ratio);
/*
** ===================================================================
**     Method      :  PWM1_SetRatio16 (component PWM)
**     Description :
**         This method sets a new duty-cycle ratio. Ratio is expressed
**         as a 16-bit unsigned integer number. 0 - FFFF value is
**         proportional to ratio 0 - 100%. The method is available
**         only if it is not selected list of predefined values in
**         <Starting pulse width> property. 
**         Note: Calculated duty depends on the timer possibilities and
**         on the selected period.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Ratio           - Ratio to set. 0 - 65535 value is
**                           proportional to ratio 0 - 100%
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
** ===================================================================
*/

byte PWM1_SetDutyUS(word Time);
/*
** ===================================================================
**     Method      :  PWM1_SetDutyUS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in microseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in microseconds]
**                      (0 to 40000 us in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

byte PWM1_SetDutyMS(word Time);
/*
** ===================================================================
**     Method      :  PWM1_SetDutyMS (component PWM)
**     Description :
**         This method sets the new duty value of the output signal.
**         The duty is expressed in milliseconds as a 16-bit
**         unsigned integer number.
**     Parameters  :
**         NAME            - DESCRIPTION
**         Time            - Duty to set [in milliseconds]
**                      (0 to 40 ms in high speed mode)
**     Returns     :
**         ---             - Error code, possible codes:
**                           ERR_OK - OK
**                           ERR_SPEED - This device does not work in
**                           the active speed mode
**                           ERR_MATH - Overflow during evaluation
**                           ERR_RANGE - Parameter out of range
** ===================================================================
*/

void PWM1_Init(void);
/*
** ===================================================================
**     Method      :  PWM1_Init (component PWM)
**
**     Description :
**         Initializes the associated peripheral(s) and the components 
**         internal variables. The method is called automatically as a 
**         part of the application initialization code.
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/


/* END PWM1. */

#endif /* ifndef __PWM1 */
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
