# Arduino CODE for 4ServoFlapOrnithopter

![230711-2 Pterasaur3small](/image/230711-2%20Pterasaur3small%20.jpg)

The Servo Flap Ornithopter(SFO) flies by flapping its wings, which are programmed through an Arduino board and operated using Servo.
Unlike model airplanes which use propellers to fly, this allows for a more natural flight.
However, because it uses the weak power of the Servo to flap its wings, it needs to be as lightweight as possible, which demands advanced building techniques.

 This is the code for an Ornithopter which uses four Servos.
  DragonFly, Flaptter, Dune's Ornithopter, Hebikera etc

 ![250115 4SFO for SFO CODE GitHub](/image/250115%204SFO%20for%20SFO%20CODE%20GitHub.jpg)

![241211  4 ServoFlap system with Aileron and Elevator trim of Rear wing](/image/241211%20%204%20ServoFlap%20system%20with%20Aileron%20and%20Elevator%20trim%20of%20Rear%20wing.jpg)
## New Servo Flap System by K.Kakuta

1 Bilateral Servo Flap between Max high point and Max low point

2 Change max flap point (throttle stick 3ch ) 
 
  and change Flapping frequency(5ch)

3 Change center of Flapping angle Horizontal (Ch1 aileron stick) and Vertical (Ch2 elevator stick)

4 Change flapping amplitude on each Servo (Ch4 rudder stick)
Increase flap amplitude of one servo and decrease flap amplitude of another servo

5 Ch6 allows the flapping phase of the front wings to be delayed compared to the flapping phase of the rear wings.
This can range from flapping the front and rear wings simultaneously to flapping the front wing flapping phase 1/2 phase behind the rear wing flapping phase.
The maximum thrust can be obtained when the flapping phase of the front wings is 1/4 phase behind the flapping phase of the rear wings.

6 Ch7 allows the inclination of the rear wings to be adjusted.

7 Ch8 allows the dihedral angle of the rear wings to be adjusted.


Setting : 

Set elevator and rudder and aileron stick Center-- 1500microsesond

Set 5Ch at Slider or Volume or other switch

Set throttle stick at low max --1000 microsecond

## Need :
   Small ppm output Receiver(8 channels)

   High power High speed Digital Servo

   -----BLUEARROW AF D43S-6.0-MG Micro Metal Gear Digital Servo is best

   Arduino Pro mini board  
   
  
   Lipo2cell (high discharge rate 20C)

## Wiring

![230710  5VtoRX ServoFlap system 4 servo AF D43S-6.0-MG Wiring](/image/230710%20%205VtoRX%20ServoFlap%20system%204%20servo%20AF%20D43S-6.0-MG%20Wiring.jpg)


PPM Receiver-- RX PPM signal input to D2 pin

Front right Servo --D5 pin

Front left Servo--D6 pin

Rear right Servo --D8 pin

Rear left Servo --D9 pin

A voltage of 5V from VCC of Arduino Pro mini bouard is supplied to the RX.


Ground -GND pin

6V -RAW pin ( 6-6.2V from Step down DC converter or Step up DC converter for 6V servo)




## My setting

Lipo: 70-150mAh2cell Lipo battery

Servo: BLUEARROW AF D43S-6.0-MG Micro Metal Gear Digital Servo

Arduino Pro mini board

DC step down converter from 2cell Lipo to 6V output



## Flap motion and Wing control VTR 
SFODragonFly132 Pro mini New Wing 71g : Flap Test and Motion
(https://www.youtube.com/watch?v=1vFoBIzVszE)


## My YouTube channel 
 Various ServoFlapOrnithopters have been uploaded.
(https://www.youtube.com/@BZH07614)

## My Website of ornithopter
 (http://kakutaclinic.life.coocan.jp/HabatakE.htm)

## Request site for production of Kazu Ornithpter
(http://kakutaclinic.life.coocan.jp/KOrniSSt.html)


## SFODragonFly90  
https://www.youtube.com/playlist?list=PLErvdRrwWuPoEXs-Y3nmkGWoydMAHvemE

## SFOFlaptter117(BlueArrowD0576Servo) & 114(BlueArrowAFD43SServo)
https://www.youtube.com/playlist?list=PLErvdRrwWuPq1wbbz15mC92AITdaS9xsx

## SFOHebikera119
https://www.youtube.com/playlist?list=PLErvdRrwWuPp_7BxYukhfohXXNFYhidXz

## SFODuneOrni115
https://www.youtube.com/playlist?list=PLErvdRrwWuPo04E3fHelekA5IRo_u4Kzd

## SFODragonFly132 (BlueArrowD0576Servo)
https://www.youtube.com/playlist?list=PLErvdRrwWuPpVqIoOMe4YXRlmgb4fDPQO

 
