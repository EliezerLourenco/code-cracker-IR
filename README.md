# code-cracker-IR

## Introduction
This project is a fun and interactive number guessing game controlled using an IR (Infrared) remote. It's built with a C++ program, utilizing hardware components like an Arduino, an IR receiver, and an LCD display. Players try to guess a randomly generated number within a certain range, receiving hints via the LCD display based on their input.

![Screenshot 2024-03-06 174233](https://github.com/EliezerLourenco/code-cracker-IR/assets/112527826/b356d8b5-4ab5-489f-8d56-c8e93c9ce193)


## Features
- **IR Remote Control**: Play the game comfortably from a distance using any IR remote.
- **LCD Feedback**: Immediate feedback on guesses with instructions on whether to guess higher or lower.
- **Limited Attempts**: Adds a layer of challenge with a limited number of attempts to guess the right number.
- **Easy Reset**: Start a new game anytime by pressing a specific button on the IR remote.

## Hardware Requirements
- Arduino Uno (or similar Arduino board)
- IR receiver module
- LiquidCrystal display (16x2 or similar)
- Breadboard and jumper wires
- Any compatible IR remote control

## Software Requirements
- Arduino IDE
- IRremote library for Arduino
- LiquidCrystal library (usually included with the Arduino IDE)

## Setup Instructions
1. **Assemble the Hardware**: Connect the IR receiver and LCD display to your Arduino according to the provided schematic diagram.
2. **Install Libraries**: Ensure the `IRremote` and `LiquidCrystal` libraries are installed in your Arduino IDE.
3. **Load the Program**: Open `IRNumberGuessGame.cpp` in the Arduino IDE, adjust the pin assignments as necessary, and upload the code to your Arduino board.
4. **Start Playing**: Power up your Arduino, and you're ready to play. Use the IR remote to make guesses and reset the game.

## How to Play
1. The game starts by displaying "Guess number 0-9" on the LCD screen.
2. Use the number buttons on your IR remote to input your guess.
3. The LCD will provide feedback:
   - **Higher**: Guess a higher number
   - **Lower**: Guess a lower number
   - **Correct!**: You've guessed the number. The game will automatically reset after a short delay.
4. If you fail to guess the number within the allowed attempts, the display will show "Game Over. Reset?" Press the specific reset button on your IR remote to start a new game.

## Customization
Feel free to adjust the range of numbers, the number of attempts, or the IR codes based on your remote model by modifying the constants and functions within the code.

## Contributing
Your contributions are welcome! If you have suggestions for improvements or bug fixes, please feel free to fork the repository and submit a pull request.

## License
[MIT License](LICENSE.md)

## Author
Eliezer Lourenco Filho

Enjoy the game, and happy coding!
