// Pin definitions
#define LCS A1
#define CS A2
#define RCS A3
#define LEFT_MOTOR 5
#define RIGHT_MOTOR 9

// Sensor threshold values (Bhai ye adjust krna pdega)
#define THRESH 500

// Motor speed ki value
#define BASE_SPEED 70
#define TURN_SPEED 50

void setup() {
// Set pin modes for sensors and motors
  pinMode(LCS, INPUT);
  pinMode(CS, INPUT);
  pinMode(RCS, INPUT);
  pinMode(LEFT_MOTOR, OUTPUT);
  pinMode(RIGHT_MOTOR, OUTPUT);
}

void loop() {

  int left_center = analogRead(LCS);
  int center = analogRead(CS);
  int right_center = analogRead(RCS);
  
  // Check if all sensors are reading black
  if (left_center > THRESH && center > THRESH && right_center > THRESH) {
    // Reached the end of the maze, stop the motors
    digitalWrite(LEFT_MOTOR, LOW);
    digitalWrite(RIGHT_MOTOR, LOW);
  }
  
  // Determine which direction to turn based on the sensor readings
  else if (left_center < THRESH && center > THRESH && right_center < THRESH) {

    // On a straight line, go straight

    analogWrite(LEFT_MOTOR, BASE_SPEED);
    analogWrite(RIGHT_MOTOR, BASE_SPEED);
  }

  else if (left_center > THRESH) {

    // Turn slightly left

    digitalWrite(LEFT_MOTOR, LOW);
    analogWrite(RIGHT_MOTOR, BASE_SPEED);
  }

  else if (right_center > THRESH) {

    // Turn slightly right
    
    analogWrite(LEFT_MOTOR, BASE_SPEED);
    digitalWrite(RIGHT_MOTOR, LOW);
  }
}
