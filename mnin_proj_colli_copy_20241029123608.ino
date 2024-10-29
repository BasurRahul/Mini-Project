// Intializing Pins
// Sensor Pins - Trigger to 3 and Echo to 2
const int trigPin = 3;
const int echoPin = 2;
// Buzzer to 13 pin
int buzz = 13;
// the setup function runs once when you press reset or
// power the board
// Defing global variables
long duration;
int distance;
// the setup function runs once when you press reset or
// power the board
void setup()
{
    // initialize pins as output for Sensor
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    // intialize pins as output for LEDs
    pinMode(12, OUTPUT);
    pinMode(8, OUTPUT);
    Serial.begin(9600);
}
// the loop function runs over and over again forever
void loop()
{
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time
    // in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    distance = duration * 0.034 / 2;
  	if ( distance >20) {
        digitalWrite(12, HIGH);
        // turn the LED on (HIGH is the voltage level)
    }
    else {
        digitalWrite(12, LOW); 
      // turn the LED off by making the voltage LOW
      // wait for a second
    }
    if (distance <= 20) {
        digitalWrite(8, HIGH);
      	tone(buzz, 2000);
        delay(100);
        noTone(buzz);
        delay(100);
        tone(buzz, 2000);
        delay(100);
        noTone(buzz);
        delay(100);
        tone(buzz, 2000);
        delay(100);
        noTone(buzz);
        tone(buzz, 2000);
        delay(100);
        noTone(buzz);
        delay(100);
    }
    else {
        digitalWrite(8, LOW); 
      // turn the LED off by making the voltage LOW
      // wait for a second
    }
    Serial.print("Distance in cms: ");
  Serial.println(distance);
  delay(100);
}