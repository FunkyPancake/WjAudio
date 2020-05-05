/* ###################################################################
**     This component module is generated by Processor Expert. Do not modify it.
**     Filename    : FTM2.c
**     Project     : WjAudio
**     Processor   : MKE04Z8VWJ4
**     Component   : Init_FTM
**     Version     : Component 01.009, Driver 01.09, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-05-05, 19:50, # CodeGen: 16
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
** @file FTM2.c
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

/* MODULE FTM2. */

#include "FTM2.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


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
void FTM2_Init(void)
{
  /* SIM_SCGC: FTM2=1 */
  SIM_SCGC |= SIM_SCGC_FTM2_MASK;
  (void)(FTM2_SC == 0U);               /* Dummy read of the FTM2_SC register to clear the interrupt flag */
  /* FTM2_SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,TOF=0,TOIE=0,CPWMS=0,CLKS=0,PS=0 */
  FTM2_SC = (FTM_SC_CLKS(0x00) | FTM_SC_PS(0x00)); /* Stop the counter */
    (void)(FTM2_C0SC == 0U);           /* Dummy read of the FTM2_C0SC register to clear the interrupt flag */
    (void)(FTM2_C1SC == 0U);           /* Dummy read of the FTM2_C1SC register to clear the interrupt flag */
    (void)(FTM2_C2SC == 0U);           /* Dummy read of the FTM2_C2SC register to clear the interrupt flag */
  /* FTM2_MODE: WPDIS=1 */
  FTM2_MODE |= FTM_MODE_WPDIS_MASK;    /* Disable write protection */
  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C0SC = 0x00U;
  /* FTM2_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C1SC = 0x00U;
  /* FTM2_C2SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C2SC = 0x00U;
  /* FTM2_C3SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C3SC = 0x00U;
  /* FTM2_C4SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C4SC = 0x00U;
  /* FTM2_C5SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0,??=0 */
  FTM2_C5SC = 0x00U;
  /* FTM2_SC: TOF=0,CPWMS=0 */
  FTM2_SC &= (uint32_t)~(uint32_t)((FTM_SC_TOF_MASK | FTM_SC_CPWMS_MASK));
  /* FTM2_MODE: FTMEN=1 */
  FTM2_MODE |= FTM_MODE_FTMEN_MASK;
  /* FTM2_COMBINE: FAULTEN2=0,SYNCEN2=0,DTEN2=0,COMP2=0,FAULTEN1=0,SYNCEN1=0,DTEN1=0,DECAPEN1=0,COMP1=0,COMBINE1=0,FAULTEN0=0,SYNCEN0=0,DTEN0=0,DECAPEN0=0,COMP0=0,COMBINE0=0 */
  FTM2_COMBINE &= (uint32_t)~(uint32_t)(
                   FTM_COMBINE_FAULTEN2_MASK |
                   FTM_COMBINE_SYNCEN2_MASK |
                   FTM_COMBINE_DTEN2_MASK |
                   FTM_COMBINE_COMP2_MASK |
                   FTM_COMBINE_FAULTEN1_MASK |
                   FTM_COMBINE_SYNCEN1_MASK |
                   FTM_COMBINE_DTEN1_MASK |
                   FTM_COMBINE_DECAPEN1_MASK |
                   FTM_COMBINE_COMP1_MASK |
                   FTM_COMBINE_COMBINE1_MASK |
                   FTM_COMBINE_FAULTEN0_MASK |
                   FTM_COMBINE_SYNCEN0_MASK |
                   FTM_COMBINE_DTEN0_MASK |
                   FTM_COMBINE_DECAPEN0_MASK |
                   FTM_COMBINE_COMP0_MASK |
                   FTM_COMBINE_COMBINE0_MASK
                  );
  /* FTM2_INVCTRL: INV2EN=0,INV1EN=0,INV0EN=0 */
  FTM2_INVCTRL &= (uint32_t)~(uint32_t)(
                   FTM_INVCTRL_INV2EN_MASK |
                   FTM_INVCTRL_INV1EN_MASK |
                   FTM_INVCTRL_INV0EN_MASK
                  );
  /* FTM2_C0SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=1,MSB=0,MSA=0,ELSB=1,ELSA=1,??=0 */
  FTM2_C0SC = (uint32_t)((FTM2_C0SC & (uint32_t)~(uint32_t)(
               FTM_CnSC_CHF_MASK |
               FTM_CnSC_MSB_MASK |
               FTM_CnSC_MSA_MASK |
               0xFFFFFF02U
              )) | (uint32_t)(
               FTM_CnSC_CHIE_MASK |
               FTM_CnSC_ELSB_MASK |
               FTM_CnSC_ELSA_MASK
              ));
  /* FTM2_C1SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=1,MSB=0,MSA=1,ELSB=0,ELSA=1,??=0 */
  FTM2_C1SC = (uint32_t)((FTM2_C1SC & (uint32_t)~(uint32_t)(
               FTM_CnSC_CHF_MASK |
               FTM_CnSC_MSB_MASK |
               FTM_CnSC_ELSB_MASK |
               0xFFFFFF02U
              )) | (uint32_t)(
               FTM_CnSC_CHIE_MASK |
               FTM_CnSC_MSA_MASK |
               FTM_CnSC_ELSA_MASK
              ));
  /* FTM2_C2SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,CHIE=1,MSB=0,MSA=1,ELSB=0,ELSA=0,??=0 */
  FTM2_C2SC = (uint32_t)((FTM2_C2SC & (uint32_t)~(uint32_t)(
               FTM_CnSC_CHF_MASK |
               FTM_CnSC_MSB_MASK |
               FTM_CnSC_ELSB_MASK |
               FTM_CnSC_ELSA_MASK |
               0xFFFFFF02U
              )) | (uint32_t)(
               FTM_CnSC_CHIE_MASK |
               FTM_CnSC_MSA_MASK
              ));
  /* FTM2_C3SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0 */
  FTM2_C3SC &= (uint32_t)~(uint32_t)(
                FTM_CnSC_CHF_MASK |
                FTM_CnSC_MSB_MASK |
                FTM_CnSC_MSA_MASK |
                FTM_CnSC_ELSB_MASK |
                FTM_CnSC_ELSA_MASK |
                0xFFFFFF02U
               );
  /* FTM2_C4SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0 */
  FTM2_C4SC &= (uint32_t)~(uint32_t)(
                FTM_CnSC_CHF_MASK |
                FTM_CnSC_MSB_MASK |
                FTM_CnSC_MSA_MASK |
                FTM_CnSC_ELSB_MASK |
                FTM_CnSC_ELSA_MASK |
                0xFFFFFF02U
               );
  /* FTM2_C5SC: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,CHF=0,MSB=0,MSA=0,ELSB=0,ELSA=0,??=0 */
  FTM2_C5SC &= (uint32_t)~(uint32_t)(
                FTM_CnSC_CHF_MASK |
                FTM_CnSC_MSB_MASK |
                FTM_CnSC_MSA_MASK |
                FTM_CnSC_ELSB_MASK |
                FTM_CnSC_ELSA_MASK |
                0xFFFFFF02U
               );
  /* FTM2_C0V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  FTM2_C0V &= (uint32_t)~(uint32_t)(0xFFFF0000U);
  /* FTM2_C1V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0xEA60 */
  FTM2_C1V = FTM_CnV_VAL(0xEA60);
  /* FTM2_C2V: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,VAL=0xFDE8 */
  FTM2_C2V = FTM_CnV_VAL(0xFDE8);
  /* FTM2_FILTER: CH2FVAL=0,CH1FVAL=0,CH0FVAL=1 */
  FTM2_FILTER = (uint32_t)((FTM2_FILTER & (uint32_t)~(uint32_t)(
                 FTM_FILTER_CH2FVAL(0x0F) |
                 FTM_FILTER_CH1FVAL(0x0F) |
                 FTM_FILTER_CH0FVAL(0x0E)
                )) | (uint32_t)(
                 FTM_FILTER_CH0FVAL(0x01)
                ));
  /* FTM2_OUTINIT: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0 */
  FTM2_OUTINIT &= (uint32_t)~(uint32_t)(0xFFFFFF00U);
  /* FTM2_SYNC: SWSYNC=0,SYNCHOM=0,REINIT=0,CNTMAX=0,CNTMIN=0 */
  FTM2_SYNC &= (uint32_t)~(uint32_t)(
                FTM_SYNC_SWSYNC_MASK |
                FTM_SYNC_SYNCHOM_MASK |
                FTM_SYNC_REINIT_MASK |
                FTM_SYNC_CNTMAX_MASK |
                FTM_SYNC_CNTMIN_MASK
               );
  /* FTM2_EXTTRIG: TRIGF=0,INITTRIGEN=0,CH1TRIG=0,CH0TRIG=0,CH5TRIG=0,CH4TRIG=0,CH3TRIG=0,CH2TRIG=0 */
  FTM2_EXTTRIG &= (uint32_t)~(uint32_t)(
                   FTM_EXTTRIG_TRIGF_MASK |
                   FTM_EXTTRIG_INITTRIGEN_MASK |
                   FTM_EXTTRIG_CH1TRIG_MASK |
                   FTM_EXTTRIG_CH0TRIG_MASK |
                   FTM_EXTTRIG_CH5TRIG_MASK |
                   FTM_EXTTRIG_CH4TRIG_MASK |
                   FTM_EXTTRIG_CH3TRIG_MASK |
                   FTM_EXTTRIG_CH2TRIG_MASK
                  );
  /* FTM2_MOD: MOD=0x8000 */
  FTM2_MOD = (uint32_t)((FTM2_MOD & (uint32_t)~(uint32_t)(
              FTM_MOD_MOD(0x7FFF)
             )) | (uint32_t)(
              FTM_MOD_MOD(0x8000)
             ));
  /* FTM2_CNTIN: INIT=0 */
  FTM2_CNTIN &= (uint32_t)~(uint32_t)(FTM_CNTIN_INIT(0xFFFF));
  /* FTM2_DEADTIME: DTPS=0,DTVAL=0 */
  FTM2_DEADTIME &= (uint32_t)~(uint32_t)(
                    FTM_DEADTIME_DTPS(0x03) |
                    FTM_DEADTIME_DTVAL(0x3F)
                   );
  /* FTM2_CNT: COUNT=0 */
  FTM2_CNT &= (uint32_t)~(uint32_t)(FTM_CNT_COUNT(0xFFFF));
  /* FTM2_MODE: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,FAULTIE=0,FAULTM=0,PWMSYNC=0,INIT=1,FTMEN=1 */
  FTM2_MODE = (uint32_t)((FTM2_MODE & (uint32_t)~(uint32_t)(
               FTM_MODE_FAULTIE_MASK |
               FTM_MODE_FAULTM(0x03) |
               FTM_MODE_PWMSYNC_MASK |
               0xFFFFFF00U
              )) | (uint32_t)(
               FTM_MODE_INIT_MASK |
               FTM_MODE_FTMEN_MASK
              ));
  /* FTM2_SYNCONF: ??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,??=0,SYNCMODE=0,??=0,SWOC=0,INVC=0,??=0,CNTINC=0,??=0,HWTRIGMODE=0 */
  FTM2_SYNCONF &= (uint32_t)~(uint32_t)(
                   FTM_SYNCONF_SYNCMODE_MASK |
                   FTM_SYNCONF_SWOC_MASK |
                   FTM_SYNCONF_INVC_MASK |
                   FTM_SYNCONF_CNTINC_MASK |
                   FTM_SYNCONF_HWTRIGMODE_MASK |
                   0xFFE0E04AU
                  );
  /* FTM2_SC: TOF=0,TOIE=0,CPWMS=0,CLKS=1,PS=5 */
  FTM2_SC = (uint32_t)((FTM2_SC & (uint32_t)~(uint32_t)(
             FTM_SC_TOF_MASK |
             FTM_SC_TOIE_MASK |
             FTM_SC_CPWMS_MASK |
             FTM_SC_CLKS(0x02) |
             FTM_SC_PS(0x02)
            )) | (uint32_t)(
             FTM_SC_CLKS(0x01) |
             FTM_SC_PS(0x05)
            ));
  /* FTM2_FMS: FAULTF=0,WPEN=0,FAULTF3=0,FAULTF2=0,FAULTF1=0,FAULTF0=0 */
  FTM2_FMS &= (uint32_t)~(uint32_t)(
               FTM_FMS_FAULTF_MASK |
               FTM_FMS_WPEN_MASK |
               FTM_FMS_FAULTF3_MASK |
               FTM_FMS_FAULTF2_MASK |
               FTM_FMS_FAULTF1_MASK |
               FTM_FMS_FAULTF0_MASK
              );
  /* FTM2_SWOCTRL: CH2OC=0,CH1OC=0,CH0OC=0 */
  FTM2_SWOCTRL &= (uint32_t)~(uint32_t)(
                   FTM_SWOCTRL_CH2OC_MASK |
                   FTM_SWOCTRL_CH1OC_MASK |
                   FTM_SWOCTRL_CH0OC_MASK
                  );
  /* FTM2_CONF: GTBEOUT=0,GTBEEN=0,BDMMODE=3,NUMTOF=0 */
  FTM2_CONF = (uint32_t)((FTM2_CONF & (uint32_t)~(uint32_t)(
               FTM_CONF_GTBEOUT_MASK |
               FTM_CONF_GTBEEN_MASK |
               FTM_CONF_NUMTOF(0x1F)
              )) | (uint32_t)(
               FTM_CONF_BDMMODE(0x03)
              ));
  /* FTM2_PWMLOAD: LDOK=1,CH5SEL=0,CH4SEL=0,CH3SEL=0,CH2SEL=0,CH1SEL=1,CH0SEL=1 */
  FTM2_PWMLOAD = (uint32_t)((FTM2_PWMLOAD & (uint32_t)~(uint32_t)(
                  FTM_PWMLOAD_CH5SEL_MASK |
                  FTM_PWMLOAD_CH4SEL_MASK |
                  FTM_PWMLOAD_CH3SEL_MASK |
                  FTM_PWMLOAD_CH2SEL_MASK
                 )) | (uint32_t)(
                  FTM_PWMLOAD_LDOK_MASK |
                  FTM_PWMLOAD_CH1SEL_MASK |
                  FTM_PWMLOAD_CH0SEL_MASK
                 ));
}

/*
** ###################################################################
**
**  The interrupt service routine(s) must be implemented
**  by user in one of the following user modules.
**
**  If the "Generate ISR" option is enabled, Processor Expert generates
**  ISR templates in the CPU event module.
**
**  User modules:
**      main.c
**      Events.c
**
** ###################################################################
PE_ISR(FTM_Isr)
{
// NOTE: The routine should include actions to clear the appropriate
//       interrupt flags.
//
}
*/


/* END FTM2. */
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