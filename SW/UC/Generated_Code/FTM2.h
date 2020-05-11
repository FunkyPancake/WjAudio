/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : FTM2.h
**     Project     : WjAudio
**     Processor   : MKE04Z8VWJ4
**     Component   : Init_FTM
**     Version     : Component 01.009, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-05-07, 05:28, # CodeGen: 19
**     Abstract    :
**          This file implements the FTM (FTM2) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**     Settings    :
**          Component name                                 : FTM2
**          Device                                         : FTM2
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Clock settings                               : 
**              Clock source                               : System clock
**              Prescaler                                  : divide by 32
**              Counter init                               : 0
**              Modulo counter                             : 32768
**              Period                                     : 51.202 ms
**              Deadtime                                   : 
**                Deadtime prescaler                       : divide by 1
**                Deadtime value                           : 0
**                Deadtime delay                           : DISABLED
**              Num of timer overflows                     : 0
**            FTM mode                                     : Enabled
**            BDM mode                                     : FTM counter functional; channels outputs functional
**            Global time base                             : Disabled
**            Global time base output                      : Disabled
**            Write protection                             : Disabled
**            Combined channels                            : 
**              Channels 0 and 1                           : 
**                Complementary mode                       : Disabled
**                Fault control                            : Disabled
**                Synchronization                          : Disabled
**                Deadtime                                 : Disabled
**                Inverting                                : Disabled
**              Channels 2 and 3                           : 
**                Complementary mode                       : Disabled
**                Fault control                            : Disabled
**                Synchronization                          : Disabled
**                Deadtime                                 : Disabled
**                Inverting                                : Disabled
**              Channels 4 and 5                           : 
**                Complementary mode                       : Disabled
**                Fault control                            : Disabled
**                Synchronization                          : Disabled
**                Deadtime                                 : Disabled
**                Inverting                                : Disabled
**            Synchronization                              : 
**              Synchronization mode                       : Disabled
**                Counter reinitialization                 : Disabled
**              HW trigger mode                            : Enabled
**              CNTIN synchronization                      : Disabled
**              INVCTRL synchronization                    : Disabled
**              SWOCTRL synchronization                    : Disabled
**              Software Trigger                           : Disabled
**              OUTMASK synchronization                    : Disabled
**              Minimum loading point                      : Disabled
**              Maximum loading point                      : Disabled
**            External triggers                            : 
**              Counter init trigger                       : Disabled
**              Channel 0 trigger                          : Disabled
**              Channel 1 trigger                          : Disabled
**              Channel 2 trigger                          : Disabled
**              Channel 3 trigger                          : Disabled
**              Channel 4 trigger                          : Disabled
**              Channel 5 trigger                          : Disabled
**            Fault control settings                       : 
**              Fault control mode                         : Disabled
**              Fault input filter value                   : Disabled
**          Channels                                       : 
**            Channel 0                                    : Enabled
**              Channel mode                               : Input capture
**                Edge control                             : Rising or falling
**              Input capture filter                       : 1
**              Software output control                    : Disabled
**              Pin                                        : Enabled
**                Pin                                      : PTC0/KBI1_P2/FTM2_CH0/ADC0_SE8
**                Pin signal                               : 
**              Interrupt/DMA                              : 
**                Interrupt                                : INT_FTM2
**                Channel interrupt                        : Enabled
**            Channel 1                                    : Enabled
**              Channel mode                               : Output compare
**                Output action                            : Toggle output
**                Channel value register                   : 60000
**              Input capture filter                       : Disabled
**              Software output control                    : Disabled
**              Pin                                        : Enabled
**                Pin                                      : PTC1/KBI1_P3/FTM2_CH1/ADC0_SE9
**                Pin signal                               : 
**              Interrupt/DMA                              : 
**                Interrupt                                : INT_FTM2
**                Channel interrupt                        : Enabled
**            Channel 2                                    : Enabled
**              Channel mode                               : Output compare
**                Output action                            : Disconnected
**                Channel value register                   : 65000
**              Input capture filter                       : Disabled
**              Software output control                    : Disabled
**              Pin                                        : Disabled
**              Interrupt/DMA                              : 
**                Interrupt                                : INT_FTM2
**                Channel interrupt                        : Enabled
**            Channel 3                                    : Disabled
**            Channel 4                                    : Disabled
**            Channel 5                                    : Disabled
**          Pins                                           : 
**            Fault pins                                   : 
**            External clock pin                           : Disabled
**            HW Synchronization triggers                  : 
**          Interrupts                                     : 
**            Channels / Timer overflow / Fault            : 
**              Interrupt                                  : INT_FTM2
**              Interrupt request                          : Enabled
**              Interrupt priority                         : 1
**              ISR Name                                   : FTM_Isr
**              Channels interrupt/DMA                     : See the respective Channel settings
**              Timer overflow interrupt                   : Disabled
**              Fault interrupt                            : Disabled
**          Initialization                                 : 
**            Initialize the Channels Output               : yes
**            Load enable                                  : yes
**            Channel 0 load select                        : yes
**            Channel 1 load select                        : yes
**            Channel 2 load select                        : no
**            Channel 3 load select                        : no
**            Channel 4 load select                        : no
**            Channel 5 load select                        : no
**            Call Init method                             : yes
**     Contents    :
**         Init - void FTM2_Init(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file FTM2.h
** @version 01.09
** @brief
**          This file implements the FTM (FTM2) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
*/         
/*!
**  @addtogroup FTM2_module FTM2 module documentation
**  @{
*/         

#ifndef FTM2_H_
#define FTM2_H_

/* MODULE FTM2. */

/* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"

/* Peripheral base address parameter */
#define FTM2_DEVICE FTM2_BASE_PTR


/*
** ===================================================================
**     Method      :  FTM2_Init (component Init_FTM)
**     Description :
**         This method initializes registers of the FTM module
**         according to the Peripheral Initialization settings.
**         Call this method in user code to initialize the module. By
**         default, the method is called by PE automatically; see "Call
**         Init method" property of the component for more details.
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
void FTM2_Init(void);
/*
** ===================================================================
** The interrupt service routine must be implemented by user in one
** of the user modules (see FTM2.c file for more information).
** ===================================================================
*/
PE_ISR(FTM_Isr);


/* END FTM2. */
#endif /* #ifndef __FTM2_H_ */
/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
