int myInt = 10;

void setup() {
  // Begin the Serial at 9600 Baud
  Serial.begin(9600);
}

void loop() {
  Serial.write(myInt); //Write the serial data
  delay(1000);
}
