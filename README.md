# FISH Forth for NXP LPC812 (GNU Arm build)

A standalone GNU Arm Embedded build of **FISH** — a 32-bit flash-resident
Forth for ARM Cortex-M — for the NXP LPC812 (Cortex-M0+), 24 MHz,
16 KB flash, 4 KB RAM. Default target: `NXP_81x_PubRel` word set.

FISH is an F83-derived Forth by Clyde W. Phillips Jr. and A-TEAM FORTH.
See the FISH Reference Model glossary for the word set.

## Build

Requires `arm-none-eabi-gcc`, `arm-none-eabi-objcopy`, `arm-none-eabi-nm`,
GNU Make:

```bash
make clean all
make size
```

Artifacts are written to `build/gcc/`: `fish.elf`, `fish.hex` (flash this),
`fish.sym`, `fish.map`. Links with `lpc812_gnu.ld`; the FISH memory map and
C stack fit the 4 KB RAM layout.

## Console

Serial terminal: 9600 bps 8n1 by default, XON/XOFF flow control.
Boot prints the FISH signon; `WORDS` lists the dictionary by WORDCAT
category.

## Layout

- `FISH_NXP_M0_Forth_GNU.S` — Forth engine and dictionary (GNU syntax)
- `FISH_NXP_M0_COLD.s` / `startup_lpc812_gnu.S` — cold start / vectors
- `FISH_NXP_M0_FLASH.s` — FLASH_SAVE / FLASH_FORGET
- `FISH_NXP_M0_812_SOC_INIT.s`, `FISH_NXP_M0_812_UART0_INIT.s` — SoC/UART init
- `FISH_*.h`, `FISH_*_*.s` — translated assembler include fragments
- `core_cm0.h`, `LPC11xx.h` — CMSIS/device headers

## Notes

- Dictionary-header cells and headerless Forth tokens are `.balign 4`-
  aligned; the M0 inner interpreter (`LDM w!, {x}` in `NEXT1`) requires
  exact word alignment. Do not remove the `.balign 4, 255` lines.
- Config defines live in `FISH_RM_CONFIG_#DEFINES.h`.
