/*
  NOTE:
  - APP USED: Bluetooth RC Controller
  - SETTINGS: Please select data stream frequency >> On change/touch >> OK
*/

#include <SoftwareSerial.h>
SoftwareSerial bluetooth(3, 2); // RXD, TXD
char command;

// Initialize motors
#define motor_RF 8  // right front
#define motor_RB 9  // right back
#define motor_LF 10  // left front
#define motor_LB 11  // left back

// Initialize head light
#define head_light 13

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  pinMode(motor_RF, OUTPUT);
  pinMode(motor_RB, OUTPUT);
  pinMode(motor_LF, OUTPUT);
  pinMode(motor_LB, OUTPUT);
  pinMode(head_light, OUTPUT);
}

void loop() {
  if (bluetooth.available() > 0) {
    command = bluetooth.read();
    Serial.print("Command: ");
    Serial.println(command);

    switch (command) {
      // Commands for moving
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

      // Commands for the headlight
      case 'W':  // light on
        digitalWrite(head_light, HIGH);
        break;
      case 'w':  // light off
        digitalWrite(head_light, LOW);
        break;
    }
  }
}

void go_forward() {
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);
}

void go_back() {
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);
}

void go_left() {
  digitalWrite(motor_RF, HIGH);
  digitalWrite(motor_RB, LOW);
  digitalWrite(motor_LF, LOW);
  digitalWrite(motor_LB, HIGH);
}

void go_right() {
  digitalWrite(motor_RF, LOW);
  digitalWrite(motor_RB, HIGH);
  digitalWrite(motor_LF, HIGH);
  digitalWrite(motor_LB, LOW);
}
