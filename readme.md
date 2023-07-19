# PID Beam Ball Balance
Final project for Feedback and Control Systems 

## Getting Started
It is controlled with a servo motor and an Arduino with a PID code. The idea is to get the ping pong ball in the middle. To do that we will use a IR distance sensor. By knowing the distance to the ball and using the PID code to move the servo, we could control the position and speed of the ball and stop it exactly in the middle. The system could get better with a better resolucion sensor and better servo motor, also better PID constants.

There are also 3D files that you can print. 

Credits to : Electronoobs
video :  https://www.youtube.com/watch?v=JFTJ2SS4xyA

### PID Parameters
You can change this parameters to your desired value depending on your prototype. 
```
float kp=12; //Mine was 8
float ki=0.2; //Mine was 0.2
float kd=3100; //Mine was 3100
float distance_setpoint = 25; 
```
$$ \ohm \:  lul $$
$$ \ohm \ohm \ohm$$
