

I created an interactive small bird for my midterm project (Ardumini). It was inspired by recent video about owls that led me to explore how to make moveable wings. The bird I created is about three inches tall and has a body made out of craft wire. The craft wire allows its entire body to be a touch sensor. However, it has paper feathers so it will only work if you touch the bird on the exposed area on its head. Once the bird reads your touch, it flaps both wings at the same time using two servo motors (one motor per wing). There is a wire that connects the breadboard to the craft wire body. The servo motors are connected to the wings using invisible thread. What needs work is better attachment of the thread to the wings. If I had more time I would have liked the bird to respond to touch with sound as well.

### Components:
- Arduino Uno
- Breadboard
- Wires
- Resistor (1m ohm)
- Craft Wire
- 2 Servo motors
- Invisible Thread
- Paper for feathers

### Progress images and video

![Progress photo](https://github.com/Juniette01/CIM542-642/blob/master/hw/week11%20-%20midterm/arduino-progress-pic.jpg)

Video of testing the motors: https://youtu.be/4vTSmJdxNsI
In this video I was testing if I could connect two servo motors. After this, I tested if I could run them at the same time.

### Final image and video

![Final image of setup](https://github.com/Juniette01/CIM542-642/blob/master/hw/week11%20-%20midterm/arduino-final-board.jpg)

Video of bird put together and functioning: https://youtu.be/Iqo4ipzuKJ0

### Code explanation

My code uses the libraries for capactive sensing and servo. When you touch the bird's head, the servo motors move 100 degrees and give the look of flapping wings. It has a delay of 5ms. This movement only works when the sensor is being touched and will continue until the sensor is released.

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
  myservo2.attach(3); // attaches the servo on pin 3 to the servo object

}

void loop() {
  // put your main code here, to run repeatedly:
  long sensor1 = capSensor.capacitiveSensor(50);

   Serial.println(sensor1);  // print sensor output
   if(sensor1 >= 1000)
   {
    digitalWrite(2, HIGH);

    for (pos = 0; pos <= 100; pos += 1) { // degrees that servo turns

    myservo.write(pos);              
     myservo2.write(pos);
    delay(5);                       // waits 5 for the servo to reach the position
  }
  for (pos = 100; pos >= 0; pos -= 1) {
    myservo.write(pos);              
     myservo2.write(pos);
    delay(5);                       
  }



   }
   else {
    digitalWrite(2,LOW);
   }


}
