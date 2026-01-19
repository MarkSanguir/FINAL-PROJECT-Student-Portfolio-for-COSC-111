# Laboratory Activity #6: Bi-Directional Serial Communication

### Overview

This project represents a significant milestone in IoT system design: **Bi-directional Communication**. While previous activities focused on one-way control (either controlling the Arduino from Python or visualizing Arduino data on a PC), this activity creates a "closed-loop" system. It establishes a two-way conversation where the Arduino and a Python script constantly exchange data, acting as both sender and receiver simultaneously.

### What This Project Does

The system creates a "Round Trip" interaction loop between the physical world and the digital world.

- **The Trigger:** A user presses a physical button on the breadboard.
    
- **The Uplink:** The Arduino detects this press and sends a code (e.g., 'R') to the computer.
    
- **The Logic:** A Python script running on the computer receives the code, processes it, and decides what to do (e.g., "User pressed Button 1, so I should request the Red LED to toggle").
    
- **The Downlink:** Python sends a command back to the Arduino (e.g., '1').
    
- **The Action:** The Arduino receives the command and physically toggles the corresponding LED.
    

This seemingly simple loop mimics the architecture of complex cloud-IoT systems, where a device sends telemetry to a server, and the server responds with control commands.

### How the System Works

The project utilizes a split-logic approach, dividing tasks between the microcontroller and the PC.

- **Hardware Setup:**
    
    - **Inputs:** Three push buttons connected to pins 12, 11, and 10.
        
    - **Outputs:** Three LEDs (Red, Green, Blue) connected to pins 7, 6, and 5.
        
- **Signal Flow:**
    
    1. User presses **Button 1**.
        
    2. Arduino sends character **'R'** via USB.
        
    3. Python reads 'R', prints a confirmation, and sends back the character **'1'**.
        
    4. Arduino reads '1' and executes `toggleRed()`, turning the Red LED on or off.
        

### Code Explanation

The code is distributed across three files to maintain organization and modularity.

**1. The "Backend" Logic (Python Script)** The `lab_activity6.py` file acts as the decision-maker.

- **Listening Loop:** It runs an infinite `while True` loop, constantly checking `arduino.in_waiting` to see if the Arduino has sent data.
    
- **Automated Response:** Unlike the previous activity where the user typed commands manually, this script is automated. It uses conditional logic: `if data == 'R': ... send_command('1')`. It instantly responds to hardware events without human typing.
    

**2. The Hardware Manager (Arduino Sketch)** The `laboratory_activity_6.ino` file handles two parallel tasks:

- **Inbound Task (Listener):** It checks the Serial buffer. If it receives '1', '2', or '3', it calls the corresponding toggle function.
    
- **Outbound Task (Reporter):** It monitors the buttons. Crucially, it uses **State Change Detection** (Edge Detection). Instead of constantly spamming "RRRRR" while the button is held down, it only sends a signal once _at the exact moment_ the button state changes from HIGH to LOW.
    

**3. The Configuration Header (`myFunctions.h`)** This file abstracts the hardware details.

- **Internal Pull-Ups:** It configures the buttons using `pinMode(BTN_1, INPUT_PULLUP)`. This eliminates the need for external resistors in the circuit, as it uses the Arduino's built-in resistors to ensure a stable signal.
    

### IoT Concepts Applied

- **Full-Duplex Communication:** The ability for two devices to send and receive data simultaneously.
    
- **Edge Detection:** A programming technique used to trigger an event only on the transition of a signal (e.g., the "falling edge" when a button is pressed) rather than the steady state.
    
- **Latency:** The delay between the button press and the light turning on. This project demonstrates the speed of Serial communication, as the signal travels to the PC and back in milliseconds.
    
- **Input Pull-up Resistors:** Using internal microcontroller features to simplify circuit wiring and prevent "floating" signals.