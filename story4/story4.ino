
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
  // Story 4
  // Use the if condition to check if one counter reaches 870
  // if it has, stop the rover
  forwards_rover(0);
  // Make the rover go forwards
  
  // Is one counter > 870?
  if(leftcounter >= 870){
    // Stop rover
    stop_rover(999999);
    // Keep it stopped
    
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
}  

void reverse_rover(int delaytime){
  digitalWrite(FWD_RIGHT, LOW);
  digitalWrite(FWD_LEFT, LOW);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, HIGH);
  digitalWrite(REV_LEFT, HIGH); 
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
