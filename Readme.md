# PIC16F877A Projects

A collection of embedded systems projects developed for the PIC16F877A microcontroller, written in both C and Assembly. Each project includes the source code and the Proteus simulation file.

## 🛠️ Technologies Utilized

* **Microcontroller:** PIC16F877A
* **Languages:** C, Assembly (PIC)
* **IDE:** MPLAB X IDE
* **Compiler:** XC8 (for C projects)
* **Simulation:** Proteus 8

## 🎮 Included Projects

### 1. Binary Counter LEDs (`binary-counter-leds`)

Increments PORTB every 500ms, counting in binary across the output pins using LEDs.

* Configures PORTB as output.
* Uses the `__delay_ms()` function with a 4MHz clock.
* Written in **C**.

### 2. Hydraulic Press Controller (`hydraulic-press`)

Simulates an industrial hydraulic press safety system.

* Requires two buttons pressed simultaneously to lower the piston for 2 seconds, then raise it for 2 seconds.
* Includes an emergency button wired to an external interrupt (RB0) that immediately raises the piston.
* Written in **Assembly**.

### 3. Timer0 LED Blink (`timer-led`)

Alternates two LEDs every 500ms using the Timer0 peripheral with interrupts.

* Configures Timer0 with a prescaler to generate periodic interrupts.
* Uses context saving/restoring inside the interrupt service routine.
* Written in **Assembly**.

### 4. Button LED Control (`button-led-control`)

Reads a button state on PORTD and controls an LED on PORTB accordingly.

* Configures PORTB as output and PORTD as input.
* Turns the LED on when the button is pressed, off when released.
* Written in **C**.

### 5. ADC Voltmeter with Multiplexed 7-Segment Display (`adc-multiplexed-display`)

Reads an analog voltage via the ADC (channel AN4) and displays the result on a 4-digit multiplexed 7-segment display.

* Configures the ADC in 10-bit mode with interrupt-driven conversion (ADIE).
* Scales the raw ADC result to millivolts and decomposes the value into individual digits.
* Drives four display digits sequentially (EN1–EN4 on PORTC) using time-division multiplexing.
* Written in **C**.

## 🖥️ How to Simulate

Each project folder contains a `.pdsprj` (Proteus project) and a `.hex` (compiled firmware) file.

1. Open the `.pdsprj` file in Proteus 8.
2. The `.hex` file should already be loaded into the PIC16F877A component. If not, double-click the microcontroller in the schematic, navigate to *Program File*, and select the `.hex` file from the project folder.
3. Run the simulation.

## ⚙️ How to Recompile (Optional)

If you want to recompile the source code:

1. Install [MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide) and the [XC8 Compiler](https://www.microchip.com/en-us/tools-resources/develop/mplab-xc-compilers).
2. Create a new standalone project in MPLAB X targeting the **PIC16F877A**.
3. Add the `.c` or `.asm` source file to the project.
4. Build the project. The generated `.hex` file will be located in the `dist/default/production/` folder.

## 📚 Context

Developed for the Microcontroladores e Microprocessadores (Microcontrollers and Microprocessors) course at UFSC (Universidade Federal de Santa Catarina) in 2023.

**Collaborators:**

* [Eduardo Zambotto da Silva](https://github.com/Edu17z)
* [Júlio Amaral Pereira](https://github.com/JulioAmaral007)
* João Pedro Blanco