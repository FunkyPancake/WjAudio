/* ###################################################################
**     Filename    : main.c
**     Project     : WjAudio
**     Processor   : MKE04Z8VFK4
**     Version     : Driver 01.01
**     Compiler    : GNU C Compiler
**     Date/Time   : 2020-04-13, 05:58, # CodeGen: 0
**     Abstract    :
**         Main module.
**         This module contains user's application code.
**     Settings    :
**     Contents    :
**         No public methods
**
** ###################################################################*/
/*!
** @file main.c
** @version 01.01
** @brief
**         Main module.
**         This module contains user's application code.
*/
/*!
**  @addtogroup main_module main module documentation
**  @{
*/
/* MODULE main */

/* Including needed modules to compile this module/procedure */
#include "BtRst.h"
#include "Cpu.h"
#include "DownButton.h"
#include "Events.h"
#include "FTM2.h"
#include "PlayButton.h"
#include "SysTick.h"
#include "UpButton.h"

/* Including shared modules, which are used for whole project */
#include "IO_Map.h"
#include "PE_Const.h"
#include "PE_Error.h"
#include "PE_Types.h"


/* User includes (#include below this line is not maintained by Processor Expert) */
#include "CDChanger.h"
#include "J1850VPW.h"


PE_ISR(SysTickIsr)
{
    CDChanger_1ms();
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
    /* Write your local variable definition here */

    /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
    PE_low_level_init();
    /*** End of Processor Expert internal initialization.                    ***/

    /* Write your code here */
    /* For example: for(;;) { } */
    J1850Init();
    InitBtResetTimer(((SIM_SRSID & SIM_SRSID_POR_MASK) == SIM_SRSID_POR_MASK) &&
                     ((SIM_SRSID & SIM_SRSID_LVD_MASK) == SIM_SRSID_LVD_MASK));
    for(;;)
    {
        CDChanger_Polling();
    }
    /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** RTOS startup code. Macro PEX_RTOS_START is defined by the RTOS component. DON'T MODIFY THIS CODE!!! ***/
  #ifdef PEX_RTOS_START
    PEX_RTOS_START();                  /* Startup of the selected RTOS. Macro is defined by the RTOS component. */
  #endif
  /*** End of RTOS startup code.  ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
} /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/

/* END main */
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
