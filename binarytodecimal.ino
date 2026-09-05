const int a = 13;  
const int b = 12;  
const int c = 11;  
const int d = 10;  
const int e = 9; 
const int f = 8;  
const int g = 7;  

const int buttonPins[] = {3, 4, 5, 6}; 
const int ledPins[] = {A0, A1, A2, A3}; 

bool lastButtonState[4] = {HIGH, HIGH, HIGH}; 

void setup() {
  pinMode(a, OUTPUT);  
  pinMode(b, OUTPUT);  
  pinMode(c, OUTPUT);  
  pinMode(d, OUTPUT);  
  pinMode(e, OUTPUT);  
  pinMode(f, OUTPUT);  
  pinMode(g, OUTPUT);  

  for (int i = 0; i < 4; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP); 
    pinMode(ledPins[i], OUTPUT); 
    digitalWrite(ledPins[i], LOW); 
  }

  displayDigit(0); 
}

void loop() {
  static int binaryValue = 0; 
  bool buttonPressed = false; 

  for (int i = 0; i < 4; i++) {
    bool currentState = digitalRead(buttonPins[i]); 
    
    if (currentState == LOW && lastButtonState[i] == HIGH) { 
      binaryValue ^= (8 >> i); 
      buttonPressed = true; 
    }
    lastButtonState[i] = currentState; 

    digitalWrite(ledPins[i], (binaryValue & (8 >> i)) ? HIGH : LOW); 
  }

  if (buttonPressed && binaryValue >= 0 && binaryValue <= 9) {
    turnOff(); 
    displayDigit(binaryValue); 
  } else if (!buttonPressed) {
    displayDigit(binaryValue); 
  }
}

void displayDigit(int digit) {
  turnOff(); 
  switch (digit) {
    case 0: displayZero(); break; 
    case 1: digitalWrite(b, HIGH); digitalWrite(c, HIGH); break; 
    case 2: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(g, HIGH); digitalWrite(e, HIGH); digitalWrite(d, HIGH); break; 
    case 3: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(g, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); break; 
    case 4: digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); break; 
    case 5: digitalWrite(a, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); break; 
    case 6: digitalWrite(a, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); break; 
    case 7: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); break; 
    case 8: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break; 
    case 9: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break; 
  }
}

void turnOff() {
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void displayZero() {
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
