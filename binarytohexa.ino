const int a = 13;  
const int b = 12;  
const int c = 11;  
const int d = 10;  
const int e = 9; 
const int f = 8;  
const int g = 7;  

const int buttonPins[] = {3, 4, 5, 6}; 
const int ledPins[] = {A0, A1, A2, A3}; 

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
    digitalWrite(ledPins[i], HIGH); 
  }

  segmentDigit(15); 
}

void loop() {
  int binaryValue = 15; 
  bool buttonPressed = false; 

  for (int i = 0; i < 4; i++) {
    if (digitalRead(buttonPins[i]) == LOW) { 
      binaryValue &= ~(1 << i); 
      digitalWrite(ledPins[i], LOW); 
      buttonPressed = true; 
    } else {
      digitalWrite(ledPins[i], HIGH); 
    }
  }

  if (buttonPressed) {
    turnOff(); 
    segmentDigit(binaryValue); 
  } else {
    segmentDigit(15); 
  }
}

void segmentDigit(int digit) {
  switch (digit) {
    case 15: digitalWrite(a, HIGH); digitalWrite(b, LOW); digitalWrite(c, LOW); digitalWrite(d, LOW); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break; 
    case 14: digitalWrite(a, HIGH); digitalWrite(f, HIGH); digitalWrite(e, HIGH); digitalWrite(d, HIGH); digitalWrite(g, HIGH); break; 
    case 13: digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(g, HIGH); break; 
    case 12: digitalWrite(a, HIGH); digitalWrite(f, HIGH); digitalWrite(e, HIGH); digitalWrite(d, HIGH); break; 
    case 11: digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break; 
    case 10: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break; 
    case 9: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break; 
    case 8: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); break; 
    case 7: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); break; 
    case 6: digitalWrite(a, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); digitalWrite(e, HIGH); break; 
    case 5: digitalWrite(a, HIGH); digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); break; 
    case 4: digitalWrite(f, HIGH); digitalWrite(g, HIGH); digitalWrite(b, HIGH); digitalWrite(c, HIGH); break; 
    case 3: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(g, HIGH); digitalWrite(c, HIGH); digitalWrite(d, HIGH); break; 
    case 2: digitalWrite(a, HIGH); digitalWrite(b, HIGH); digitalWrite(g, HIGH); digitalWrite(e, HIGH); digitalWrite(d, HIGH); break; 
    case 1: digitalWrite(b, HIGH); digitalWrite(c, HIGH); break; 
    case 0: displayZero(); break; 
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
