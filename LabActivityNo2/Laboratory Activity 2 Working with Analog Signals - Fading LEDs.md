# Laboratory Activity #2: Working with Analog Signals - Fading LEDs

### Overview

This project advances from simple on/off switching to simulating analog signals using a digital microcontroller. While digital signals are binary (0 or 1), real-world applications often require variable output, such as dimming a light or controlling motor speed. This activity demonstrates how to control LED brightness using **Pulse Width Modulation (PWM)** via the `analogWrite()` function.

### What This Project Does

Building on the "running light" logic from the previous activity, this system creates a smooth fading animation across five LEDs. * **Fade In Sequence:** The LEDs light up one by one, from pin 12 to pin 8. Instead of snapping on instantly, each LED gradually brightens from off to full intensity.

- **Fade Out Sequence:** Once the sequence is complete, the LEDs turn off one by one in the same order, gradually fading from full brightness down to zero.
    
- **Pacing:** The fade effect is controlled by a rapid loop, while a 1-second delay holds the state between each LED transition.
    
    +1
    

### How the System Works

The hardware setup remains identical to the previous activity, but the software approach changes significantly to handle "analog" behavior.

- **Hardware:** An Arduino Uno is connected to a breadboard with five LEDs wired to digital pins 12, 11, 10, 9, and 8.
    
- **Signal Processing (PWM):** The Arduino simulates an analog voltage by switching the digital pins on and off so fast that the human eye perceives it as a varying voltage level. This is known as Pulse Width Modulation (PWM).
    
- **Outputs:** The `analogWrite()` function accepts a value between 0 (always off) and 255 (always on). A value of 127, for example, would result in 50% brightness.
    

### Code Explanation

The code introduces `while` loops and the `analogWrite` command to manage the fading logic.

- **Initialization (`setup`):** The program uses a `while` loop to iterate through the `ledPins` array, configuring each pin as an `OUTPUT`.
    
- **Fading In (Nested Loops):** Inside the main `loop`, the code iterates through each LED. For every LED, an inner `while` loop increases a `power` variable from 0 to 255.
    
    - `analogWrite(ledPins[i], power)` applies the current brightness level.
        
    - `delay(1)` creates a tiny pause, making the brightening effect visible to the human eye rather than instantaneous.
        
- **Fading Out:** After the "fade-in" sequence completes, the code resets the counter (using logic `j=i-5`) and runs a second set of loops.
    
    - The inner loop decreases the `power` variable from 255 down to 0, creating the dimming effect.
        

### IoT Concepts Applied

- **Analog vs. Digital Output:** Understanding that while the Arduino is a digital device, it can simulate analog outputs using PWM.
    
- **Pulse Width Modulation (PWM):** Learning how varying the "duty cycle" of a signal controls power delivery to components like LEDs or motors.
    
- **Nested Control Structures:** Using loops inside of loops to handle two dimensions of time: the duration of the fade (inner loop) and the sequence of the LEDs (outer loop).
    
- **Variable State Control:** Using variables (like `power`) to dynamically adjust hardware states in real-time, rather than hard-coding static values.