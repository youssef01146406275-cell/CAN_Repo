// Motor A Pins
int motorA_Enable = 1;
int motorA_Pin1 = 3;
int motorA_Pin2 = 2;

// Motor B Pins
int motorB_Enable = 6;
int motorB_Pin1 = 5;
int motorB_Pin2 = 4;

// Ultrasonic Sensor Pins
#define TRIG 8
#define ECHO 9

void setup() {


pinMode(motorA_Enable, OUTPUT);
pinMode(motorA_Pin1, OUTPUT);
pinMode(motorA_Pin2, OUTPUT);

pinMode(motorB_Enable, OUTPUT);
pinMode(motorB_Pin1, OUTPUT);
pinMode(motorB_Pin2, OUTPUT);

pinMode(TRIG, OUTPUT);
pinMode(ECHO, INPUT);
}

void loop() {

moveRobot();
avoidObstacle();
}

// Motor Control Functions
void moveMotorAForward() {
digitalWrite(motorA_Pin1, HIGH);
digitalWrite(motorA_Pin2, LOW);
}

void moveMotorBForward() {
digitalWrite(motorB_Pin1, LOW);
digitalWrite(motorB_Pin2, HIGH);
}

void moveMotorABackward() {
digitalWrite(motorA_Pin1, LOW);
digitalWrite(motorA_Pin2, HIGH);
}

void moveMotorBBackward() {
digitalWrite(motorB_Pin1, HIGH);
digitalWrite(motorB_Pin2, LOW);
}

void stopMotorA() {
digitalWrite(motorA_Pin1, HIGH);
digitalWrite(motorA_Pin2, HIGH);
}

void stopMotorB() {
digitalWrite(motorB_Pin1, HIGH);
digitalWrite(motorB_Pin2, HIGH);
}

void enableAllMotors() {
digitalWrite(motorA_Enable, HIGH);
digitalWrite(motorB_Enable, HIGH);
}

// Robot Movement Functions
void goForward(int timeDelay) {
moveMotorAForward();
moveMotorBForward();
delay(timeDelay);
}

void goBackward(int timeDelay) {
moveMotorABackward();
moveMotorBBackward();
delay(timeDelay);
}

void turnRight(int timeDelay) {
moveMotorABackward();
moveMotorBForward();
delay(timeDelay);
}

void stopRobot(int timeDelay) {
stopMotorA();
stopMotorB();
delay(timeDelay);
}

// Distance Measurement
int getDistance() {

int pulseDuration;
int measuredDistance;

digitalWrite(TRIG, HIGH);
delayMicroseconds(1000);
digitalWrite(TRIG, LOW);

pulseDuration = pulseIn(ECHO, HIGH);

measuredDistance = (pulseDuration / 2) / 29.1;

return measuredDistance;
}

// Main Robot Function
void moveRobot() {

int frontDistance = getDistance();

while(frontDistance > 15) {

```
enableAllMotors();
goForward(1);

frontDistance = getDistance();
```

}

stopRobot(0);
}

// Obstacle Avoidance Function
void avoidObstacle() {

goBackward(500);
turnRight(360);
}
