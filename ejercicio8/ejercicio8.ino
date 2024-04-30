#include <LiquidCrystal.h>

// Define the pins for LCD
#define LCD_RS 13
#define LCD_EN 12
#define LCD_D4 11
#define LCD_D5 10
#define LCD_D6 9
#define LCD_D7 8

// Define the pins for buttons
#define ALPHA_BUTTON 4
#define NUM_BUTTON 5
#define CLEAR_BUTTON 6
#define ENTER_BUTTON 7
#define RIGHT_BUTTON 2

// Define the number of users
#define NUM_USERS 3

// Define the usernames and passwords
String usernames[NUM_USERS] = {"User1", "User2", "User3"};
String passwords[NUM_USERS] = {"123abc", "456def", "789ghi"};

// Variables to store user input
String userInput = "";

// Initialize the LCD library
LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup() {
  // Set up the LCD's number of columns and rows
  lcd.begin(16, 2);

  // Set up button pins as inputs
  pinMode(ALPHA_BUTTON, INPUT_PULLUP);
  pinMode(NUM_BUTTON, INPUT_PULLUP);
  pinMode(CLEAR_BUTTON, INPUT_PULLUP);
  pinMode(ENTER_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Check for button presses
  if (digitalRead(ALPHA_BUTTON) == LOW) {
    // Handle alpha button press
    char nextChar = userInput.length() == 0 ? 'a' : ((userInput[userInput.length() - 1] - 'a' + 1) % 26) + 'a';
    userInput = userInput.substring(0, userInput.length() - 1) + nextChar;
    updateDisplay();
    delay(200);
  } else if (digitalRead(NUM_BUTTON) == LOW) {
    // Handle num button press
    char nextNum = userInput.length() == 0 ? '0' : ((userInput[userInput.length() - 1] - '0' + 1) % 10) + '0';
    userInput = userInput.substring(0, userInput.length() - 1) + nextNum;
    updateDisplay();
    delay(200);
  } else if (digitalRead(CLEAR_BUTTON) == LOW) {
    // Handle clear button press
    userInput = "";
    updateDisplay();
    delay(200);
  } else if (digitalRead(ENTER_BUTTON) == LOW) {
    // Handle enter button press
    checkPassword(userInput);
    userInput = "";
    updateDisplay();
    delay(200);
  } else if (digitalRead(RIGHT_BUTTON) == LOW) {
    // Handle right button press
    if (userInput.length() > 0) {
      char lastChar = userInput[userInput.length() - 1];
      userInput = lastChar + userInput.substring(0, userInput.length() - 1);
      updateDisplay();
      delay(200);
    }
  }
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Password: ");
  lcd.setCursor(0, 1);
  lcd.print(userInput);
}

void checkPassword(String input) {
  for (int i = 0; i < NUM_USERS; i++) {
    if (input.equals(passwords[i])) {
      Serial.print("BIENVENIDO ");
      Serial.println(usernames[i]);
      return;
    }
  }
  Serial.println("Acceso denegado");
}

