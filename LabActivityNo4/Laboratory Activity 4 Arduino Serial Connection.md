# Laboratory Activity #4: Arduino Serial Connection

### Overview: The "Sticky" Alarm
This project introduces a system that doesn't just run on its own—it needs you. Unlike previous projects that did their job automatically, this one requires a human to type a command to reset it. It demonstrates how to control hardware in real-time using your computer keyboard.

### What This Project Does
The system acts like a security alarm that "locks" itself on.

The Watchman: A light sensor continuously measures how bright the room is.

The Trigger: If the light gets too bright (crossing a specific limit), the alarm goes off and an LED starts flashing.

The "Latch": This is the important part—once the alarm starts, it stays on, even if the lights go back down. The system "remembers" that the limit was crossed.

The Reset: The alarm will blink forever until you physically type the word "stop" into your computer to shut it off.

### How It Works
The system relies on a partnership between the sensor and your keyboard.

Input (Hardware): A light sensor (photoresistor) watches the physical world.

Input (Software): The Arduino listens to the USB cable, waiting for text messages from you.

The Trap: When the light hits the limit, the code enters a specific mode (a loop) where the only thing it does is blink the LED and listen for the password. It stops checking the light sensor entirely.

The Escape: When it hears the correct password ("stop"), it breaks out of the loop and goes back to normal monitoring.

### Code Explanation
The code uses a few tricks to handle text and logic states.

Number Conversion: The sensor gives a wide range of numbers (0-1023). The code shrinks this down to a standard scale (0-255) to make it easier to judge brightness.

The "Trap" Loop: The code uses a specific logic structure (a while loop) to create the alarm. Think of this like a locked room: once the code enters this room, it cannot leave until the specific condition (typing "stop") unlocks the door.

Text Reader: The code includes a text reader that captures what you type. It also uses a "Lowercase" tool, so it understands you whether you type "STOP," "Stop," or "stop."

### Key Concepts Learned
Serial Chat: Using the USB cable to send text commands to a device, rather than just uploading code.

Latching (State Retention): Building a system that stays in a specific mode (like "Danger Mode") until a human acknowledges it. This is common in industrial safety machines.

Text Processing: Teaching a machine to read words and ignore capitalization differences (Case Insensitivity).

Blocking Code: A style of programming where the code pauses all other tasks (like sensing light) to focus entirely on one thing (blinking the alarm). text data (converting to lowercase) to make user interfaces more robust and user-friendly.
    
Blocking vs. Non-Blocking: This code uses a "blocking" `while` loop for the alarm, meaning the sensor stops reading new data while the alarm is active.
