

For my final project, I created a small interactive bird based on the Bachman’s wood warbler, which is an endangered bird species in Florida. The bird's body is made out of cardboard is craft wire. The craftwire serves as a capacitive touch sensor and is connected to a wire on the Arduino breadboard. The feathers are made out of paper. Once the bird reads your touch, it flaps both wings at the same time using one servo motor and moves its head with a second servo motor. The motors move at a different pace from the midterm project. Originally, I planned to add a sound function using the Arduino soundboard, but was not able to get it working. If I could improve on this project it would be to successfully add the corresponding bird sound upon touch.

### Components:
- Arduino Uno
- Breadboard
- Wires
- Resistor (1m ohm)
- Craft Wire
- Cardboard
- 2 Servo motors
- Invisible Thread
- Paper for feathers

### Progress images and video

![Progress photo](https://github.com/Juniette01/CIM542-642/blob/master/hw/week12%20-%20final/final_progress_photo.jpg)



### Final image and video

![Final image of setup](https://github.com/Juniette01/CIM542-642/blob/master/hw/week12%20-%20final/final_photo.jpg)

![Final image of setup](https://raw.githubusercontent.com/Juniette01/CIM542-642/master/hw/week11%20-%20midterm/arduino-final-board.jpg)

Video of bird put together and functioning: https://youtu.be/JTwzLEGfs1I

### Code explanation

My code uses the libraries for capactive sensing and servo. When you touch the bird's base, the servo motors move 80 degrees and give the look of flapping wings as well as a moving head. It has a delay of 12ms. This movement only works when the sensor is being touched and will continue until the sensor is released.

### Code

#include <CapacitiveSensor.h>
#include <Servo.h>

CapacitiveSensor capSensor = CapacitiveSensor(4,2);

Servo myservo;
Servo myservo2;

int pos = 0;    // variable to store the servo position

void setup() {
  // put your setup code here, to run once:
capSensor.set_CS_AutocaL_Millis(0xFFFFFFFF);
 Serial.begin(9600);
 pinMode(2,OUTPUT);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(3);

}

void loop() {
  // put your main code here, to run repeatedly:
  long sensor1 = capSensor.capacitiveSensor(50);

   Serial.println(sensor1);  // print sensor output
   if(sensor1 >= 1000)
   {
    digitalWrite(2, HIGH);

    for (pos = 0; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
     myservo2.write(pos);
    delay(12);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 80; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
     myservo2.write(pos);
    delay(12);                       // waits 15ms for the servo to reach the position
  }




   }
   else {
    digitalWrite(2,LOW);
   }


}
