#include <SoftwareSerial.h>
SoftwareSerial bluetooth(3, 4); // RXD, TXD
char command;

// motor one
int PWM_right = 10;
int motor_RB = 9;
int motor_RF = 8;

// motor two
int PWM_left = 5;
int motor_LB = 7;
int motor_LF = 6;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(motor_RF, OUTPUT);
  pinMode(motor_RB, OUTPUT);
  pinMode(motor_LF, OUTPUT);
  pinMode(motor_LB, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    command = bluetooth.read();
    Serial.print("Command: ");
    Serial.println(command);

    switch (command) {
      case 'F':
        go_forward();
        break;
      case 'B':
        go_back();
        break;
      case 'L':
        go_left();
        break;
      case 'R':
        go_right();
        break;

      case 'G':
        go_forwardleft();
        break;
      case 'I':
        go_forwardright();
        break;
      case 'H':
        go_backleft();
        break;
      case 'J':
        go_backright();
        break;

      case 'S':
        stop();
        break;
    }
  }
}


void stop() {
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, LOW);

  analogWrite(PWM_right, 0);
  analogWrite(PWM_left, 0);
}

void go_forward() {
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  analogWrite(PWM_right, 220);
  analogWrite(PWM_left, 220);
}

void go_back() {
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);

  analogWrite(PWM_right, 220);
  analogWrite(PWM_left, 220);
}

void go_left() {
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);

  analogWrite(PWM_right, 225);
  analogWrite(PWM_left, 225);
}

void go_right() {
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  analogWrite(PWM_right, 225);
  analogWrite(PWM_left, 225);
}

void go_forwardleft() {
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  analogWrite(PWM_right, 255);
  analogWrite(PWM_left, 0);
}

void go_forwardright() {
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);

  analogWrite(PWM_right, 0);
  analogWrite(PWM_left, 255);
}

void go_backleft() {
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);

  analogWrite(PWM_right, 255);
  analogWrite(PWM_left, 0);
}

void go_backright() {
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);

  analogWrite(PWM_right, 0);
  analogWrite(PWM_left, 255);
}