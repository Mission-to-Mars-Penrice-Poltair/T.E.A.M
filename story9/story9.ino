
int const FWD_RIGHT = 7;//forwards int const GREEN = 11; //stopped
int const REV_RIGHT = 8;
int const ENABLE_RIGHT = 9;//backwards
// add all the other connections
int const ENABLE_LEFT = 10;
int const FWD_LEFT = 11;
int const REV_LEFT = 12;

const int LEFT_FEEDBACK = 3; // Pin numbers on Rover 
const int RIGHT_FEEDBACK = 2;

volatile int leftcounter = 0; // initiate counter to zero for start 
volatile int rightcounter = 0; // counter could always be reset

include <NewPing.h>

define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.


void setup()
{
  pinMode(FWD_RIGHT, OUTPUT);
  pinMode(REV_RIGHT, OUTPUT);
  pinMode(ENABLE_RIGHT, OUTPUT);
  pinMode(ENABLE_LEFT,OUTPUT);
  pinMode(FWD_LEFT,OUTPUT);
  pinMode(REV_LEFT,OUTPUT);
  // add other three connections pinModes
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING); 
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING); 
}


void loop() 
{
  delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");
  
  forwards_rover(0);
  // Make the rover go forwards
  
  // If there a wall in front at 15cm
  if (sonar.ping_cm <= 15){
      // stop
  stop_rover(1000);
      // reverse
  reverse_rover(500);
      // turn left
  turn_left(850);
  // carry on forwards
  
    
  }
  

}



void forwards_rover(int delaytime){
  digitalWrite(FWD_RIGHT, HIGH);
  digitalWrite(FWD_LEFT, HIGH);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, LOW);
  digitalWrite(REV_LEFT, LOW);
  delay(delaytime);
}

void stop_rover(int delaytime){
  digitalWrite(FWD_RIGHT, LOW);
  digitalWrite(FWD_LEFT, LOW);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, LOW);
  digitalWrite(REV_LEFT, LOW);
  delay(delaytime);
}  

void turn_left(int delaytime){
  digitalWrite(FWD_RIGHT, HIGH);
  digitalWrite(FWD_LEFT, LOW);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, LOW);
  digitalWrite(REV_LEFT, HIGH);
  delay(delaytime);
}

void reverse_rover(int delaytime){
  digitalWrite(FWD_RIGHT, LOW);
  digitalWrite(FWD_LEFT, LOW);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, HIGH);
  digitalWrite(REV_LEFT, HIGH);
  delay(delaytime);
}

void LeftMotorISR(){
  //add pme tp the counter on each motor revolution
  leftcounter++;
}

void RightMotorISR()
{ 
  // adds one to the counter on each motor revoloution
  rightcounter++; 
}
