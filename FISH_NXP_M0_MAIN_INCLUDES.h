 //------------------------------------------------------------------------------
 // This include begins the .sym file
#include "FISH_AUTHOR.h"
 // This include is for generic IAR stuff
 //------------------------------------------------------------------------------
 // Include FISH SYSTEM, REGISTERS, STACK MACRO's and MESSAGES
#include "io_NXP_M0+_header.h"
 // IAR C:\Program Files\IAR Systems\Embedded Workbench 7.1\arm\inc\NXP
 //------------------------------------------------------------------------------
#include "FISH_ARM_CORTEX_M_REGS.h"
#include "FISH_NXP_M0_MACROS.h"
 //------------------------------------------------------------------------------
 // #defines for XON, -1 TRUE, IO2TP, etc.
 // COPY OF Assembler Preproccesor Defined Symbols for each configuration
#include "FISH_RM_CONFIG_#DEFINES.h"
 //------------------------------------------------------------------------------
 // NXP M0 FLASH, RAM, CLOCK Configurations:
 // Placed in each configurations ( Debug, etc )'s
#include "FISH_M0_EQUATES.h"
 //$FISH_M0_MEMMAP.s  // SYSTEM AND USER MEMORY MAPPING
 //------------------------------------------------------------------------------
 // Place (select?) :NONAME's before dynamic content to make CFA addresses static.
#include "FISH_NXP_M0_SLIB.s"
 // Main Include
#include "FISH_NXP_M0_COLD.s"
#include "FISH_NXP_M0_MEMMAP.s"
