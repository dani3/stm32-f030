# STM32F030

This is a small project where I'm implementing a bare-metal operating system for the STM32F030.

## Getting started

### Project setup

1. Create a uVision project.
2. In the project options, configure the following things:
   1. Select __STM32F030__ in the `Device` tab.
   2. Set the ARM compiler to __V5.06__.
   3. Set the Start and Size of the flash and RAM areas.
   4. Select __ST-Link Debugger__ in the `Debug` tab. Check that there's a flash algorithm selected in the `Settings` window.
3. Create the startup file. I took as a reference one from [here](https://www.keil.com/pack/doc/CMSIS/Core/html/startup_c_pg.html).
4. Create the scatter file and select it in the `Linker` tab.
5. Add the `--entry=name` option in the `Misc Controls` box inside the `Linker` tab.
