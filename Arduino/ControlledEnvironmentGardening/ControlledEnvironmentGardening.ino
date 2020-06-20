const int input1 = 5;  
const int output1 = 8;   
int soilmoisture = 0;
byte waterflowInterrupt = 0;  
byte waterflowInputPin = 2;
float cFactor = 4.5;
volatile byte pulse;  
float waterFlowRate;
unsigned int flowML;
unsigned long totalML;
unsigned long previousTime;

const int output2 = 13;   
const int input2 = A0;  
int idealLightIntensity = 5; 
int ledState = 0;
int count = 0;

void setup() 
{
  Serial.begin(9600);
  pinMode(input1,INPUT_PULLUP);
  pinMode(output1,OUTPUT);

  pinMode(input2, INPUT); 
  pinMode(output2, OUTPUT);  
  
  pinMode(waterflowInputPin, INPUT);
  digitalWrite(waterflowInputPin, HIGH);
  pulse = 0;
  waterFlowRate = 0.0;
  flowML = 0;
  totalML = 0;
  previousTime = 0;
  attachInterrupt(waterflowInterrupt, counter, FALLING);
}

void loop() 
{
    int lightIntensity = analogRead(input2);
    delay(1000);
    
    if (lightIntensity < idealLightIntensity)
    { 
      digitalWrite(output2, HIGH);
      ledState = 1;
      count = count + 1;
    } 
    else 
    { 
      digitalWrite(output2, LOW); 
      ledState = 0;
    }

    int soilmoisture= digitalRead(input1);
    delay(1000);
    if (soilmoisture == 1) //DRY
    {
      digitalWrite(output1, HIGH); 
      }
    else if(soilmoisture == 0) //WET
    { 
      digitalWrite(output1, LOW);
      }
    else
    {
      digitalWrite(output1, HIGH);
      }
    
    if((millis() - previousTime) > 1000)    
      { 
        detachInterrupt(waterflowInterrupt);
        waterFlowRate = ((1000.0/(millis() - previousTime))*pulse)/cFactor;
        previousTime = millis();
        flowML = (waterFlowRate / 60) * 1000; //for that second
        totalML += flowML;
        Serial.print("1.Light Intensity: ");           
        Serial.print(lightIntensity);
        Serial.print(" 2.LED State: ");
        Serial.print(ledState);
        Serial.print(" 3.Count: ");
        Serial.print(count);
        Serial.print(" 4.Soil moisture: ");           
        Serial.print(soilmoisture);
        Serial.print("  5.Flow rate: "); 
        Serial.print(int(waterFlowRate));  
        Serial.print(".");            
        unsigned int fraction;
        fraction = (waterFlowRate - int(waterFlowRate)) * 10;
        Serial.print(fraction, DEC) ;      
        Serial.print("Litre/Minute");
        Serial.print("  6.Current Water Flow: "); //for that second          
        Serial.print(flowML);
        Serial.print("mL/Sec");
        Serial.print("  7.Cumulative Water Passed: ");            
        Serial.print(totalML);
        Serial.println("mL"); 
        pulse = 0;
        attachInterrupt(waterflowInterrupt, counter, FALLING);
      }
}

void counter()
{
  pulse++;
}
