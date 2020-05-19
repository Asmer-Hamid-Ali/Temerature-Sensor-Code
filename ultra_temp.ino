const char releaseNumber[6] = "1.20";              // Displays the release on the menu


// Declare ultra_temp variable here
float temp=0;
float prev_temp=0;
long duration,cm;
int distance;

// Declare all pins here
int tempPin = A0;
const int tpin=7;
const int epin=6;

void setup() 
{
  //   Initialise the sensor here. 
  Serial.begin(9600);
  pinMode(tpin,OUTPUT);
  pinMode(epin,INPUT);
  temp = analogRead(tempPin) * 0.48828125;
  prev_temp=temp;
  
}

void loop() 
{
   prev_temp=temp;
   temp = analogRead(tempPin)*0.48828125;
   ReadTemperature(prev_temp,temp);
   UltrasonicReading();

}
void myDelay(int del) 
{
  unsigned long myPrevMillis = millis();
  while (millis()- myPrevMillis <= del);
}

/*
   This will check the absolute value of current and previousTemperature. 
   If it crosses the threshold then it will return 1 else 0. 
 */
void ReadTemperature(float a,float b)
{
  if abs((a-b)>=1.0)
   {
     // convert the analog volt to its temperature equivalent
     Serial.print("TEMPERATURE = ");
     Serial.print(b); // display temperature value
     Serial.print("*C");
     Serial.println();
     myDelay(100); // update sensor reading each one second
   }
  else
  {
     Serial.print("TEMPERATURE = ");
     Serial.print(a); // display temperature value
     Serial.print("*C");
     Serial.println();
     myDelay(100); // update sensor reading each one second
  }
}
void UltrasonicReading()
{
  /*
   * Generating a pulse for measuring distance.
   */
  digitalWrite(tpin,LOW);
  delayMicroseconds(2);
  digitalWrite(tpin,HIGH);
  delayMicroseconds(10);
  digitalWrite(tpin,LOW);
  duration=pulseIn(epin,HIGH);
  distance=duration*0.034/2;
  Serial.print("Distance=");  // display distance value
  Serial.print(distance);
  Serial.println("cm");
  myDelay(100);   // update sensor reading each one second
  }
