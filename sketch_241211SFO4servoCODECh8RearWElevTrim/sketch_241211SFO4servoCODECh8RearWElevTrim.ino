//231011 version3 for ZIP added Rear wing Aileron same move 221208 Version2 added ch7 RearWingTrim　210916 15-4th Code 4servo Rudder ElevatorUP FlapAmpUP not delaytime control PPMRX Ch1-4 writeMicroseconds(1000-2000uS) use 5V3A  FrontServoLate RearServo Ailron act only Front servo dt and elapsed time by K.Kakuta
//241211 Ch8 rearWElevtrim
#include <Servo.h>
#include "src/PPMReader/PPMReader.h"// <PPMReader.h>
//#include <InterruptHandler.h>// 2022/01/27 Delete for more good move

//#define DOPRINTS // if you print on PC screen Data, delete”//” 
// In use of Flap system,cut "Serial.print "(put ”//”)  
//and write code to Arduino board.
int interruptPin = 2;
int channelAmount = 8;
PPMReader ppm(interruptPin, channelAmount);

int servo_right_pin = 5;
int servo_left_pin = 6;
int servo_right2_pin = 8;
int servo_left2_pin = 9;

volatile int elevator = 0;
volatile int flapamp = 0;
volatile int rearwingtrim =0;
volatile int rearWElevtrim =0;

volatile float delaytime = 100;// Servo speed low-increase Servo speed high-decrease this.
                          // unit: micro second
volatile float delaytime2 = 100;
volatile float delaytime3=100; // Servo speed low-increase Servo speed high-decrease this.
                          // unit: micro second
volatile float delaytime4 = 100;

float elapsed_time = 0;
float dt;
unsigned long current_time, prev_time;

volatile int ch3value = 1000;//Ch3
volatile int ch1value = 1500;//Ch1
volatile int ch2value = 1500;//Ch2
volatile int ch4value = 1500;//Ch4
volatile int ch5value = 1500;//Ch5
volatile int ch6value = 1500;//Ch6 Right LeverSwitch
volatile int ch7value = 1500;//Ch7 rear wing ailron trim
volatile int ch8value = 1500;//Ch8 rear wing elevator trim

static int servo_comm1 = 0;// Left or Right Servo high point and low point
static int servo_comm2 = 0; // Left or Right Servo high point and low point
static int servo_comm3 = 0;// Left or Right Servo high point and low point no rudder
static int servo_comm4 = 0; // Left or Right Servo high point and low point no rudder

volatile int rudder = 0;
float glide_deg = 0; // Gliding angle 0=0 degree 500=90degree
static float servo_zero1 = 0;//flap angle adjust
static float servo_zero2 = 0; //flap angle adjust


Servo servo_left, servo_right, servo_right2, servo_left2; // create servo object to control a servo

void setup() {
  Serial.begin(9600);

  pinMode(servo_left_pin, OUTPUT);
  pinMode(servo_right_pin, OUTPUT);
  pinMode(servo_left2_pin, OUTPUT);
  pinMode(servo_right2_pin, OUTPUT);

  servo_left.attach(servo_left_pin);//output pin No
  servo_right.attach(servo_right_pin); //output pin No
  servo_left2.attach(servo_left2_pin);//output pin No
  servo_right2.attach(servo_right2_pin); //output pin No
delay(2000);//Avoid abnormal positions at startup-wait 2 second until RX starts220306

}

void loop() {
prev_time = current_time;      
  current_time = micros();      
  dt = (current_time - prev_time)/1000000.0;

  elapsed_time = elapsed_time + dt; // total time spent in the main loop since beginning one upstroke/downstroke

  ch3value = ppm.rawChannelValue(3);//Ch3
  ch1value = ppm.rawChannelValue(1);//Ch1
  ch2value = ppm.rawChannelValue(2);//Ch2
  ch4value = ppm.rawChannelValue(4);//Ch4
  ch5value = ppm.rawChannelValue(5);//Ch5
ch6value = ppm.rawChannelValue(6);//Ch6
ch7value = ppm.rawChannelValue(7);//Ch7
ch8value = ppm.rawChannelValue(8);//Ch8

    
    //Serial.print("ch3value ");Serial.print(ch3value);
    //Serial.print(",\t"); 
    //Serial.print("ch1value ");Serial.print(ch1value);
    //Serial.print(",\t");
    //Serial.print("ch2value ");Serial.print(ch2value);
//Serial.print(",\t");
    //Serial.print("ch4value ");Serial.print(ch4value);
//Serial.print(",\t");
    //Serial.print("ch5value ");Serial.print(ch5value);
    //Serial.println(",\t");
    //Serial.print("ch6value ");Serial.print(ch6value);
    //Serial.println(",\t");


 rudder=(int)(ch1value-1500);//Ch1  Flap angle incline
 elevator=(int)(ch2value-1500);//Ch2 Flap Angle bilateral UP&Down
 flapamp=(int)(ch4value-1500);//Ch4 Right and left Flap angle difference
delaytime=( ch5value -950)/5;//Ch5 Flapping frequency 
 delaytime2=( ch6value -950)/10;//Ch6 Delay frontServo-RearServo 
 rearwingtrim =( ch7value - 1500);//Ch7 Right and left angle trim difference -0.5to0.5
 rearWElevtrim =( ch8value - 1500);//Ch8 Right and left angle trim -0.5to0.5
delaytime4 = delaytime * delaytime2 / 200;
delaytime3 = delaytime- delaytime4;

// you can change UP or Down direction by your transmitter Reverse setting of each Channel

  
    //Serial.print("rudder");Serial.print(rudder);
    //Serial.print(",\t");
    //Serial.print("elevator");Serial.print(elevator);
    //Serial.print(",\t");
    //Serial.print("flapamp");Serial.print(flapamp);
//Serial.print(",\t");
    //Serial.print("delaytime");Serial.print(delaytime);
    //Serial.print(",\t");
//Serial.print("delaytime2");Serial.print(delaytime);
    //Serial.print(",\t");


 if (ch3value > 1080) {
if (elapsed_time < delaytime4/1000) {
  servo_comm1 = (int)( (ch3value -1000)/2+1500 + rudder - elevator+ servo_zero1+ flapamp);
  servo_comm2 = (int)(1000 + (2000 - ((ch3value -1000)/2+1500)) + rudder + elevator- servo_zero2+flapamp);  
  servo_comm3 = (int)( (ch3value -1000)/2+1500 + rudder - elevator + rearwingtrim - rearWElevtrim + servo_zero1+ flapamp);
  servo_comm4 = (int)(1000 + (2000 - ((ch3value -1000)/2+1500)) + rudder + elevator + rearwingtrim + rearWElevtrim - servo_zero2+flapamp);  

  
   // Serial.print("servo_comm1 ");Serial.print(servo_comm1);
   // Serial.print(",\t"); 
   // Serial.print("servo_comm2 ");Serial.print(servo_comm2);
   // Serial.print(",\t");
   // Serial.print("servo_comm3 ");Serial.print(servo_comm3);
//Serial.print(",\t");
   // Serial.print("servo_comm4 ");Serial.print(servo_comm4);

   
  servo_left2.writeMicroseconds(servo_comm3); // Rear left servo position 
  servo_right2.writeMicroseconds(servo_comm4); // Rear right servo position 
}
if ((elapsed_time > delaytime4/1000) && ( elapsed_time < (delaytime4 + delaytime3)/1000)) {


  servo_left.writeMicroseconds(servo_comm1); // Front left servo position  
  servo_right.writeMicroseconds(servo_comm2); // Front right servo position 
}
if ((elapsed_time > (delaytime4 + delaytime3)/1000) && (elapsed_time < (delaytime4 + delaytime3 + delaytime4)/1000)) {

  servo_comm1 = (int)( (ch3value -1000)/2+1500 + rudder + elevator+ servo_zero1-flapamp);
  servo_comm2 = (int)(1000 + (2000 - ((ch3value -1000)/2+1500)) + rudder - elevator- servo_zero2-flapamp); 
  servo_comm3 = (int)( (ch3value -1000)/2+1500 + rudder + elevator+ rearwingtrim + rearWElevtrim + servo_zero1-flapamp);
  servo_comm4 = (int)(1000 + (2000 - ((ch3value -1000)/2+1500)) + rudder - elevator + rearwingtrim - rearWElevtrim - servo_zero2-flapamp);  

  servo_left2.writeMicroseconds(servo_comm4); // Rear left servo position
  servo_right2.writeMicroseconds(servo_comm3); // Rear right servo position 
}
   if (elapsed_time > (delaytime4 + delaytime3 + delaytime4)/1000)  {

  servo_left.writeMicroseconds(servo_comm2); // Front left servo position 
  servo_right.writeMicroseconds(servo_comm1); // Front right servo position 

  
    //Serial.print("servo_comm1");Serial.print(servo_comm1);
    //Serial.print(",\t");
    //Serial.print("servo_comm2");Serial.print(servo_comm2);
    //Serial.println(",\t");
  }

  }
else{

  servo_comm1=(int)(1500+rudder-elevator+glide_deg);
  servo_comm2=(int)(1500+rudder+elevator-glide_deg);  
servo_comm3=(int)(1500 + rearwingtrim - rearWElevtrim + rudder - elevator + glide_deg);
  servo_comm4=(int)(1500 + rearwingtrim + rearWElevtrim + rudder +elevator-glide_deg);

  servo_left.writeMicroseconds(servo_comm1); // servo position in variable 'pos'
  servo_right.writeMicroseconds(servo_comm2); // servo position in variable 'pos' 
servo_left2.writeMicroseconds(servo_comm3); // servo position in variable 'pos'
  servo_right2.writeMicroseconds(servo_comm4); // servo position in variable 'pos'

  
    //Serial.print("servo_comm1");Serial.print(servo_comm1);
    //Serial.print(",\t");
    //Serial.print("servo_comm2");Serial.print(servo_comm2);
    //Serial.println(",\t");

}
       if (elapsed_time > (delaytime4 + delaytime3 + delaytime4 + delaytime3)/1000) {// one full flap is finisheddt
         elapsed_time = 0; // start next flapping cycle
}

}
