const int input2 = A0; 
const int output2 = 13;    
int idealLightIntensity = 5; 
int ledState = 0;
int count = 0;

void setup() {
    Serial.begin(9600);
    pinMode(input2, INPUT); 
    pinMode(output2, OUTPUT);     
}

void loop() 
{
    int lightIntensity = analogRead(input2);
    String lightIntensity2 = String(analogRead(input2));
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
    String ledState2 = String(ledState);
    String count2 = String(count);
    String final = lightIntensity2+":"+ledState2+":"+count2;
    Serial.println(final);
}
