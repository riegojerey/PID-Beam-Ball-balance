#include <Servo.h>
#include <Ultrasonic.h>


///////////////////////Inputs/outputs///////////////////////
//const int TrigPin = 3;
//const int EchoPin = 4;
Ultrasonic ultrasonic(3, 4);
Servo myservo;  // create servo object to control a servo, later attatched to D9
///////////////////////////////////////////////////////


////////////////////////Variables///////////////////////
int Read = 0;
float distance = 0.0;
float elapsedTime, ntime, timePrev;        //Variables for time control
float distance_previous_error, distance_error;
int period = 60;  //Refresh rate period of the loop is 50ms
///////////////////////////////////////////////////////


///////////////////PID constants///////////////////////
float kp=12; //Mine was 8
float ki=0.2; //Mine was 0.2
float kd=3100; //Mine was 3100
float distance_setpoint = 25;           //Should be the distance from sensor to the middle of the bar in mm
float PID_p, PID_i, PID_d, PID_total;
///////////////////////////////////////////////////////



void setup() {
  //analogReference(EXTERNAL);
  Serial.begin(9600);  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(125); //Put the servco at angle 125, so the balance is in the middle
//  pinMode(TrigPin, OUTPUT);
//  pinMode(EchoPin, INPUT);
  ntime = millis();
}

void loop() {
  if (millis() > ntime+period)
  {
    ntime = millis();    
    distance = ultrasonic.read(); 
    if (distance > 30 )
    {
      distance = 30;  
    }
    distance_error = distance_setpoint - distance;   
    PID_p = kp * distance_error;
    float dist_diference = distance_error - distance_previous_error;     
    PID_d = kd*((distance_error - distance_previous_error)/period);
      
    if(-3 < distance_error && distance_error < 3)
    {
      PID_i = PID_i + (ki * distance_error);
    }
    else
    {
      PID_i = 0;
    }
  
    PID_total = PID_p + PID_i + PID_d;  
    PID_total = map(PID_total, -150, 150, 0, 150);
  
    if(PID_total < 20)
    {PID_total = 20;}
    if(PID_total > 160) 
    {PID_total = 160; } 
  
    myservo.write(PID_total+25);  
    distance_previous_error = distance_error;
    Serial.println(distance);
  }
}










//
//float readPosition() {
//  delay(50);                                                               
//long duration, cm;
//unsigned long now = millis();
//  //pinMode(TrigPin, OUTPUT);
//  digitalWrite(TrigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(TrigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(TrigPin, LOW);
//
//
//  //pinMode(EchoPin, INPUT);
//  duration = pulseIn(EchoPin, HIGH);
//
//  cm = duration/(29*2);
//  
//  
// if(cm >= 30)     // 30 cm is the maximum position for the ball
//  {cm=30;}
//  
//  //cm=30-cm;
// /* if (cm <7 ) {cm=6; Serial.println("Mazen");}*/
//  Serial.println(cm);
//  
//  return cm;                                          
//}
