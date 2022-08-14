#include <SoftwareSerial.h>

SoftwareSerial mySerial(10, 11); // RX, TX

#define Lmotor1 3
#define Lmotor2 5

#define Rmotor1 6
#define Rmotor2 9

String data = "a";

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);

  // set the data rate for the SoftwareSerial port
  mySerial.begin(9600);

  pinMode(Lmotor1, OUTPUT);
  pinMode(Lmotor2, OUTPUT);

  pinMode(Rmotor1, OUTPUT);
  pinMode(Rmotor2, OUTPUT);
  
  Stop();
}

void loop() { // run over and over
  if (mySerial.available()) {
    data = mySerial.readString();
  }
  if (data == "forward") {
    forward();
    Serial.println("forward");
    delay(1500);
    Stop();
    data = "a";
  }
  else if (data == "backward") {
    backward();
    Serial.println("backward");
    delay(1500);
    Stop();
    data = "a";
  }
  else if (data == "stop") {
    Stop();
    Serial.println("Stop");
  }
  else if (data == "left") {
    left();
    Serial.println("left");
    delay(1000);
    Stop();
    data = "a";
  }
  else if (data == "right") {
    right();
    Serial.println("right");
    delay(1000);
    Stop();
    data = "a";
  }
  else {
    data = data;
  }
  Serial.print("data is: ");
  Serial.println(data);
}

void forward() {
  analogWrite(Lmotor1, 80);
  analogWrite(Lmotor2, 0);

  analogWrite(Rmotor1, 80);
  analogWrite(Rmotor2, 0);
}

void backward() {
  analogWrite(Lmotor1, 0);
  analogWrite(Lmotor2, 80);

  analogWrite(Rmotor1, 0);
  analogWrite(Rmotor2, 80);
}

void Stop() {
  analogWrite(Lmotor1, 0);
  analogWrite(Lmotor2, 0);

  analogWrite(Rmotor1, 0);
  analogWrite(Rmotor2, 0);
}

void left() {
  analogWrite(Lmotor1, 0);
  analogWrite(Lmotor2, 0);

  analogWrite(Rmotor1, 150);
  analogWrite(Rmotor2, 0);
}

void right() {
  analogWrite(Lmotor1, 150);
  analogWrite(Lmotor2, 0);

  analogWrite(Rmotor1, 0);
  analogWrite(Rmotor2, 0);
}
