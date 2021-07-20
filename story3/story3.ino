int const FWD_RIGHT = 12; //forwards int const GREEN = 11; //stopped
int const REV_RIGHT = 11;
int const ENABLE_RIGHT = 10; //backwards
// add all the other connections
int const ENABLE_LEFT = 9;
int const FWD_LEFT = 8;
int const REV_LEFT = 7;
void setup()
{
  pinMode(FWD_RIGHT, OUTPUT);
  pinMode(REV_RIGHT, OUTPUT);
  pinMode(ENABLE_RIGHT, OUTPUT);
  pinMode(ENABLE_LEFT,OUTPUT);
  pinMode(FWD_LEFT,OUTPUT);
  pinMode(REV_LEFT,OUTPUT);
  // add other three connections pinModes
}

void loop() 
{
  digitalWrite(FWD_RIGHT, HIGH);
  digitalWrite(FWD_LEFT, HIGH);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, LOW);
  digitalWrite(REV_LEFT, LOW); 
  delay(5000);
  digitalWrite(FWD_RIGHT, LOW);
  digitalWrite(FWD_LEFT, LOW);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, LOW);
  digitalWrite(REV_LEFT, LOW);
  delay(1000); 
  digitalWrite(FWD_RIGHT, LOW);
  digitalWrite(FWD_LEFT, LOW);
  digitalWrite(ENABLE_RIGHT, HIGH);
  digitalWrite(ENABLE_LEFT, HIGH); 
  digitalWrite(REV_RIGHT, HIGH);
  digitalWrite(REV_LEFT, HIGH); 
  delay(2000);
}
