const char releaseNumber[6] = "1.30";              // Displays the release on the menu


// Declare water_ultra_temp variable here
float temp=0;
float prev_temp=0;
long duration,cm;
int distance;
volatile int flow_frequency; // Measures flow sensor pulses
unsigned int l_hour; // Calculated litres/hour
unsigned long currentTime;
unsigned long cloopTime;

// Declare all pins here
int tempPin = A0; //Temperature Sensor Input
const int tpin=7; //Ultrasonic Sensor Input
const int epin=6; //Ultrasonic Sensor Input
unsigned char flowsensor = 2; // waterFlow Sensor Input

void flow () // Interrupt function
{
   flow_frequency++;
}

void setup() 
{
  //   Initialise the sensor here. 
  Serial.begin(9600);
  pinMode(tpin,OUTPUT);
  pinMode(epin,INPUT);
  temp = analogRead(tempPin) * 0.48828125;
  prev_temp=temp;
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH); // Optional Internal Pull-Up
  attachInterrupt(0, flow, RISING); // Setup Interrupt
  sei(); // Enable interrupts
  currentTime = millis();
  cloopTime = currentTime;
  
}

void loop() 
{
   prev_temp=temp;
   temp = analogRead(tempPin)*0.48828125;
   ReadTemperature(prev_temp,temp);
   UltrasonicReading();
   WaterFlow();
}

void WaterFlow()
{
   currentTime = millis();
   // Every second, calculate and print litres/hour
   if(currentTime >= (cloopTime + 100))
   {
      cloopTime = currentTime; // Updates cloopTime
      // Pulse frequency (Hz) = 7.5Q, Q is flow rate in L/min.
      l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
      flow_frequency = 0; // Reset Counter
      Serial.print(l_hour, DEC); // Print litres/hour
      Serial.println(" L/hour");
   }
}

/*
  update sensor reading each one second
*/
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
  Serial.print("DISTANCE=");  // display distance value
  Serial.print(distance);
  Serial.println("cm");
  myDelay(100);   // update sensor reading each one second
  }
