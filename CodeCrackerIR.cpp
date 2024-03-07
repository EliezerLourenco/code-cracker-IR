// C++ code
// Author: Eliezer Lourenco Filho
// Project: IR Remote Controlled Number Guessing Game
// Date: 2022/12/14

#include <LiquidCrystal.h>
#include <IRremote.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int RECV_PIN = 10;
IRrecv irrecv(RECV_PIN);
decode_results results;

int randomNumber; // The random number to be guessed
int inputNumber; // The number input by the user via IR remote
int numberAttempts; // The number of attempts made by the user

// Use a specific IR code from your remote to reset the game
const unsigned long RESET_CODE = 12495; // Replace with your actual reset code

void setup() {
  lcd.begin(16, 2);
  irrecv.enableIRIn(); // Start the receiver
  Serial.begin(9600); // Start serial communication for debugging
  startNewGame(); // Initialize a new game
}

void startNewGame() {
  randomNumber = random(0, 10); // Generate a random number between 0 and 9
  numberAttempts = 0;
  lcd.clear();
  lcd.print("Guess number 0-9");
}

void loop() {
  if (irrecv.decode(&results)) {
    // Print the IR code to serial for debugging
    Serial.println(results.value, HEX);

    // Check if the reset button was pressed
    if (results.value == RESET_CODE) {
      startNewGame();
    } else {
      // Process the input number based on the IR code received
      inputNumber = getNumberFromIRCode(results.value);

      lcd.clear();
      if (inputNumber < randomNumber) {
        lcd.print("Higher");
      } else if (inputNumber > randomNumber) {
        lcd.print("Lower");
      } else {
        lcd.print("Correct!");
        delay(3000); // Delay to show the correct answer
        startNewGame(); // Start a new game after a correct guess
      }
      numberAttempts++;
      if (numberAttempts > 5) {
        lcd.clear();
        lcd.print("Game Over. Reset?");
        while (true) {
          if (irrecv.decode(&results) && results.value == RESET_CODE) {
            startNewGame();
            break;
          }
          irrecv.resume(); // Receive the next value
        }
      }
    }
    irrecv.resume(); // Prepare for the next value
  }
}

int getNumberFromIRCode(unsigned long code) {
  // This function should return a number 0-9 based on the IR code received
  // Maps the IR code received from the remote to the corresponding number
  switch (code) {
    case 12495: return 0;
    case 2295: return 1;
    case -30601: return 2;
    case 18615: return 3;
    case 10455: return 4;
    case -22441: return 5;
    case 26775: return 6;
    case 6375: return 7;
    case -26521: return 8;
    case 22695: return 9;
    default: return -1; // Invalid code
  }
}
