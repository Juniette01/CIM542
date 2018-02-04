#### Spaceship Interface

In this project I connected the LEDs to pins 3, 4, and 5, and used 220-ohm resistors. I connected the button to pin 2 and used a 10k-ohm resistor.

In the setup() function, the pins for the LEDs (3,4,5) were listed as OUTPUT and the pin for the button (2) as INPUT. I then wrote an if() statement which caused the green LED to start as on and the two red LEDs to be off. When the button is pressed, the green LED turns off and the two red LEDs will flash in alternating order. The time between flashes is .25 seconds. Because this part of the code is in a loop, the alternating flashes will continue until the button is released.

Video: https://youtu.be/KTOi8ruRODM

Image:
![spaceship](https://raw.githubusercontent.com/Juniette01/CIM542/master/hw/week3/20180204_165222.jpg)
