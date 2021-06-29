// Author :  Dhruvi N. Koshiya
// defines pins
const int trigPin = 3;
const int echoPin = 2;
    
const int InPin = A0;
int pvalue = 0;

const int InPin2 = A1;
int pvalue2 = 0;

bool flag = false;

    #define DCwater_pump 8
    long duration;
    int distance;
    int cm = 0;
    int time = 0;
    
    void setup() 
{
    pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
    pinMode(echoPin, INPUT); // Sets the echoPin as an Input
    pinMode(DCwater_pump, OUTPUT);
    Serial.begin(9600); // For serial communication

    pvalue = analogRead(InPin);
    cm = map(pvalue, 0, 1023, 2, 32); // 0-30 cm ditance range
    pvalue2 = analogRead(InPin2);
    time= map(pvalue2, 0, 1023, 2, 12);     //0-10 sec pump on duration 

}
    void loop() 
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    //Distance calculation
    distance= duration*0.034/2;
    // Printinng the distance on the Serial Monitor
    Serial.print("Distance: ");
    Serial.println(distance);
    Serial.print("pvalue :");
    Serial.println(pvalue);
    Serial.print("mapped pvalue in cm :");
    Serial.println(cm);
   
    Serial.print("pvalue2 :");
    Serial.println(pvalue2);
    Serial.print("mapped pvalue in time :");
    Serial.println(time);
    
     
      Serial.println("======");
        if (distance <= cm && flag == false)
        {
          digitalWrite(DCwater_pump,LOW);
          Serial.println("DC Pump is ON Now!!");
          delay(time*1000);
          digitalWrite(DCwater_pump,HIGH);
          flag = true;
          Serial.println("DC Pump is OFF Now!!");
            
        }
        
        else 
        {
          if(distance > cm)  
            {
              digitalWrite(DCwater_pump,HIGH);
              flag = false;
              Serial.println("DC Pump is OFF Now!!");
            }

             delay(500);
        

    }
    
 
}
