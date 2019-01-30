
/*
 phototrope 

  This example shows how to create a light following robot
  

  

  created Aug 2017
  by M.Himamsu
  modified Sep 2017
  by M.Himamsu 


*/

void setup()
{  
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
}


void loop() 
{
  int sensorValue1 = analogRead(A0);
  float v1 = sensorValue1 * (5000.0 / 1023.0);
 Serial.print("   sensor 1   ");
  Serial.print(v1);

  int sensorValue2 = analogRead(A1);
  float v2 = sensorValue2 * (5000.0 / 1023.0);
  Serial.print("   sensor 2   ");
  Serial.print(v2);

  int sensorValue3 = analogRead(A2);
  float v3 = sensorValue3 * (5000.0 / 1023.0);
  Serial.print("   sensor 3   ");
  Serial.print(v3);

  int sensorValue4 = analogRead(A3);
  float v4 = sensorValue4 * (5000.0 / 1023.0);
 Serial.print("  sensor 4  ");
  Serial.print(v4);

 int e1= (v4-v3)/5;
 int d1=0;
if (e1<1023&&e1>-1023)
{
  d1=e1;
  }
else
{
    if(e1>1023)
    {
      d1=1023; 
    }
    if(e1<-1023)    
    {
      d1=-1023;
      }
}
 Serial.print("  diffference aw  ");
 Serial.print(d1);
 int e2= (v2-v1)/5;
 int d2=0;
 if (e2<1023&&e2>-1023)
{
  d2=e2;
  }
else
{
    if(e2>1023)
    {
      d2=1023; 
    }
    if(e2<-1023)    
    {
      d2=-1023;
      }
}
  Serial.print("  diffference pw  ");
 Serial.print(d2);
 Serial.println();

if(d1>0)
{
  analogWrite(5,d1);
  analogWrite(6,LOW);
  analogWrite(9,d1);
  analogWrite(10,LOW); 
  
  }
  if(d1<0)
{
  analogWrite(5,LOW);
  analogWrite(6,(d1*-1));
  analogWrite(9,LOW);
  analogWrite(10,(d1*-1)); 
  
  }
if(d2>0)
{
  analogWrite(5,d2);
  analogWrite(6,LOW);
  analogWrite(9,LOW);
  analogWrite(10,d2);
  
  }
  if(d2<0)
  {
     analogWrite(5,LOW);
  analogWrite(6,(d2*-1));
  analogWrite(9,(d2*-1));
  analogWrite(10,LOW); 
    
    }
 
}
