int bPin = 10;
int fPin = 13;
int lPin = 9;
int rPin = 8;
int drive = 0;

void setup() {
  pinMode(fPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(lPin, OUTPUT);
  pinMode(rPin, OUTPUT);
  digitalWrite(lPin, HIGH);
  digitalWrite(rPin, HIGH);
  digitalWrite(bPin, HIGH);
  digitalWrite(fPin, HIGH);
  Serial.begin(115200);
}

void loop() {
  if (drive) {
    digitalWrite(fPin, LOW);
    delay(600);
    digitalWrite(fPin, HIGH);
    delay(600);
  }
  if (Serial.available()) {
    char r = Serial.read();
    if (r == 'L') {
      digitalWrite(rPin, HIGH);
      digitalWrite(lPin, LOW);
    } else if (r == 'R') {
      digitalWrite(lPin, HIGH);
      digitalWrite(rPin, LOW);
    } else if (r == 'S') {
      drive = 0;
    } else if (r == 'F') {
      drive = 1;
    } 
  }
}
