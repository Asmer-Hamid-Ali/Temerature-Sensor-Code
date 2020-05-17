const char releaseNumber[6] = "1.10";              // Displays the release on the menu


// Declare temperature variable here
float temp=0;
float prev_temp=0;

// Declare all pins here
int tempPin = A0;

void setup() 
{
  //   Initialise the sensor here. 
  Serial.begin(9600);
  temp = analogRead(tempPin) * 0.48828125;
  prev_temp=temp;
  
}

void loop() 
{
   prev_temp=temp;
   Serial.println(prev_temp);
   temp = analogRead(tempPin)*0.48828125;
   ReadTemperature(prev_temp,temp);

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
