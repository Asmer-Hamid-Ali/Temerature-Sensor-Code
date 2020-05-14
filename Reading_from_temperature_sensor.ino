float temp=0;
int tempPin = 0;
float prev_temp=0;
void setup() 
{
   Serial.begin(9600);
}

void loop() 
{
//   temp = analogRead(tempPin);
   prev_temp=temp;
   Serial.print(prev_temp);
   temp = analogRead(tempPin);
   // read analog volt from sensor and save to variable temp
   temp = temp * 0.48828125;
   ReadTemperature();
}
void myDelay(int del) 
{
  unsigned long myPrevMillis = millis();
  while (millis()- myPrevMillis <= del);
}
void ReadTemperature()
{
  if abs((prev_temp-temp) >=1)
   {
   // convert the analog volt to its temperature equivalent
   Serial.print("TEMPERATURE = ");
   Serial.print(temp); // display temperature value
   Serial.print("*C");
   Serial.println();
   myDelay(100); // update sensor reading each one second
   }
}
