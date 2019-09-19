# General

We use CubeMX to generate the code.
You can choose whether to use Keil or GNU Tools chain.

The code consists of the [FreeRTOS](https://www.freertos.org/). Some cmsis_os API is implemented.

Current board information:  
stm32f410RB   
flash size: 128k  
clock freqz: 96MHz  

# Prerequisite

## Software

For [Keil](https://www.keil.com/download/):

- Keil Project is at *MDK-ARM/* dir

For open source software:

- Compiler: [GNU Tools Chain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)

- Adapter to board: [OpenOCD](https://sourceforge.net/projects/openocd/files/openocd/0.10.0/)

- Editor: [VS code](https://code.visualstudio.com/Download)(recommend) or [Eclipse](https://www.eclipse.org/downloads/anything) or anything you like(e.g. notepad 😄)

**NOTE**   
under the dir *\Middlewares\Third_Party\FreeRTOS\Source\portable* the *GCC/* dir is for GNU Tools, the *RVDS/* dir is for Keil. Make sure the file exist before you compile the code. The CubeMX may delete one of them when generating the code for another tool chains. A backup of *GCC* dir is at the root dir.

## Environment setup

Add the `OpenOCD` to you environment variable `PATH`.

Add the `arm-none-eabi-gcc` to your environment variable `PATH`.

Install extension `Cortex-Debug` in VS Code.

# Workflow in VS Code

## Build

There are two ways to build the project:

- type `make` in the terminal

- run task *Build* in VS code

## Upload

To upload the project. Also two ways to do it

- type `make upload` in the terminal
- run task *Upload Program* in VS code

## Debug

Debug-> Start Debug(Press F5) to start debugging.

# Other references

[Cortex-Debug: a VS code extension](https://marketplace.visualstudio.com/items?itemName=marus25.cortex-debug)

[Debug with Eclipse](https://mcuoneclipse.com/2016/04/09/freertos-thread-debugging-with-eclipse-and-openocd/)
