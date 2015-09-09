/*
  If you have any questions please comment on the video and I'll try to get back
  to you ASAP
  4x4x4 LED cube
  Connect:
  column a1-13
  " a2-12
  " a3-11
  " a4-10
  " b1-9
  " b2-8
  " b3-7
  " b4-6
  " c1-5
  " c2-4
  " c3-3
  " c4-2
  " d1-1
  " d2-0
  " d3-A5
  " d4-A4
  layer 4-A3
  layer 3-A2
  layer 2-A1
  layer 1-A0
*/
//intializing and declaring layers
int layer[4]={A3,A2,A1,A0};
//initializing and declaring leds, bottom right is led[0]
int led[16]={13,12,11,10,9,8,7,6,5,4,3,2,1,0,A5,A4};

 int time = 250;
 int x;
 int y = 1;
 int counter;
 void setup()
{
  Serial.begin(9600);
  //setting leds to ouput
  for(int i = 0; i<16; i++)
  {
    pinMode(led[i], OUTPUT);
  }
  //setting layers to output
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
  //seeding random for random animations
  randomSeed(analogRead(10));
}
//+++++++++++++++++++MAIN FUNCTION+++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void loop()
{
  x = Serial.available();
  
  if(x == y){
    y = y+1;
    counter = y-x;
  randomflicker();
  }
  else{
    
  }
}


//++++++++++++++++++++FUNCTIONS++++++++++++++++++++++++++++++++++++++++
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

//////////////////////////////////////////////////////////turn all off
void turnEverythingOff()
 {
   for(int i = 0; i<16; i++)
   {
     digitalWrite(led[i], 1);
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(layer[i], 0);
   }
 }
 
//////////////////////////////////////////////////////////turn all on

///////////////////////////////////////////////////////random flicker
void randomflicker()
{
  turnEverythingOff();
  int x = 10;
  for(int i = 0; i !=750; i+=2)
  {
  int randomLayer = random(0,4);
  int randomLed = random(0,16);
  
  digitalWrite(layer[randomLayer], 1);
  digitalWrite(led[randomLed], 0);
  delay(x);
  digitalWrite(layer[randomLayer], 0);
  digitalWrite(led[randomLed], 1);
  delay(x); 
  }
}

