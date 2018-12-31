#define SOUND_SPEED 0.034
#define TRIG 9
#define ECHO 10

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(9600);
}

void loop() {
  // Clears the TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Sets the TRIG on HIGH for 10 microseconds
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Reads the TRIG, returns the sound wave travel time in microseconds
  duration = pulseIn(ECHO, HIGH);

  // Calculating the distance
  distance = duration * SOUND_SPEED/2;

  // Prints command in Serial Monitor
  if (distance <= 5) {
    Serial.println("Stop"); 
  }
  else if (distance > 5 && distance <= 10) {
    Serial.println("Left");
  }
  else if (distance >= 30 && distance <= 40) {
    Serial.println("Right");
  }
  else if (distance > 10 && distance < 30) {
    Serial.println("Play");
  }
  delay(500);
}
