# Laboratory Activity #7: Web-Controlled IoT System with FastAPI

### Overview

This project represents a complete "Full Stack" IoT implementation. It evolves beyond simple direct communication (like typing in a serial monitor) to a modern **Web-Based Control System**. By integrating an Arduino with a Python-based Web API (**FastAPI**), this activity demonstrates the architecture behind smart home devices, where a user controls physical hardware (lights) through a graphical interface on their screen.

### What This Project Does

The system creates a local web server that acts as a remote control for the Arduino circuit.

- **The Interface:** A styled HTML web page features buttons for controlling Red, Green, and Blue LEDs, plus master "All On" and "All Off" switches.
    
- **The Bridge:** A Python server listens for clicks from the web page and translates them into commands the Arduino understands.
    
- **The Hardware:** The Arduino receives these commands instantly and toggles the LEDs connected to pins 5, 6, and 7.
    

### How the System Works

The project utilizes a **Three-Tier Architecture** commonly found in commercial IoT products:

1. **Presentation Layer (Frontend):** The user interacts with `web.html`. When a button is clicked (e.g., "R"), a JavaScript function sends an **HTTP Request** to the local server.
    
2. **Application Layer (Backend):** A Python script using the **FastAPI** framework receives the HTTP request (e.g., `/led/red`). It translates this human-readable request into a specific single-byte command (e.g., sending the character `'1'` for red) and transmits it via the USB Serial port.
    
3. **Physical Layer (Hardware):** The Arduino runs a sketch that constantly listens to the Serial port. When it receives the character `'1'`, it triggers the function to toggle the Red LED.
    

### Code Explanation

The codebase is modular, separating the user interface, server logic, and hardware control.

- **The Frontend (`web.html`):** This file provides the UI. It uses the JavaScript `fetch()` API to asynchronously send commands to the Python server without reloading the page. It features CSS styling for a modern "Dark Mode" dashboard look.
    
- **The Backend API (`main.py`):** This script replaces the manual user input from previous activities.
    
    - **FastAPI:** Defines specific "routes" or endpoints (like `/led/on`) that the web page can call.
        
    - **Serial Management:** Automatically connects to the Arduino on startup (e.g., `COM7`) and manages the data flow.
        
    - **CORS Middleware:** configured to allow the browser (Frontend) to talk to the server (Backend) securely.
        
- **The Firmware (`LabAct7.ino` & `Lab_Act7.h`):**
    
    - **Header File (`.h`):** Stores pin definitions and setup logic to keep the main code clean. It defines `PIN_RED` as 7, `PIN_GREEN` as 6, and `PIN_BLUE` as 5.
        
    - **Command Parsing:** The main loop reads the incoming character and uses a `switch` statement to decide the action: `'1'`, `'2'`, `'3'` for individual toggles, and `'9'`/`'0'` for mass control.
        

### IoT Concepts Applied

- **REST API:** Creating standardized endpoints (URLs) to control resources (hardware) over a network.
    
- **HTTP Protocol:** Using standard web request methods (GET) to trigger actions.
    
- **Asynchronous JavaScript:** allowing the user interface to remain responsive while communicating with the server.
    
- **Middleware:** The Python script acts as "Middleware," translating between the high-level web protocol (HTTP) and the low-level hardware protocol (Serial/UART).