const int a = 13;  
const int b = 12;  
const int c = 11;  
const int d = 10;  
const int e = 9; 
const int f = 8;  
const int g = 7;  

const int buttonPins[] = {3, 4, 5}; 
const int ledPins[] = {A1, A2, A3}; 

void setup() {
  pinMode(a, OUTPUT);  
  pinMode(b, OUTPUT);  
  pinMode(c, OUTPUT);  
  pinMode(d, OUTPUT);  
  pinMode(e, OUTPUT);  
  pinMode(f, OUTPUT);  
  pinMode(g, OUTPUT);  

  for (int i = 0; i < 3; i++) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  int binaryInput = 0;

  for (int i = 0; i < 3; i++) {
    if (digitalRead(buttonPins[i]) == LOW) {
      binaryInput |= (1 << i);
    }
  }

  int reversedInput = 7 - binaryInput;

  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[i], (reversedInput & (1 << i)) ? HIGH : LOW);
  }

  displayNumber(reversedInput);
}

void displayNumber(int number) {
  bool patterns[8][7] = {
    {1, 1, 1, 1, 1, 1, 0}, 
    {0, 1, 1, 0, 0, 0, 0}, 
    {1, 1, 0, 1, 1, 0, 1}, 
    {1, 1, 1, 1, 0, 0, 1}, 
    {0, 1, 1, 0, 0, 1, 1}, 
    {1, 0, 1, 1, 0, 1, 1}, 
    {1, 0, 1, 1, 1, 1, 1}, 
    {1, 1, 1, 0, 0, 0, 0}  
  };

  digitalWrite(a, patterns[number][0]);
  digitalWrite(b, patterns[number][1]);
  digitalWrite(c, patterns[number][2]);
  digitalWrite(d, patterns[number][3]);
  digitalWrite(e, patterns[number][4]);
  digitalWrite(f, patterns[number][5]);
  digitalWrite(g, patterns[number][6]);
}
