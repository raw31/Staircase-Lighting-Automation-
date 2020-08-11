int light_status = 0;
int intr1 = D2;//PIR1 sensor to D2
int intr2 = D4;//PIR2 sensor to D4
int ldrPin = A0; //IDR sensor to A0  
int relayPin = D6;// Relay to the D6 of node MCU
int statusPir = LOW;
int readPir=0;
int counting=0;
int timer = 0;

void setup() {
    Serial.begin(9600);
    Serial.println("Starting....");
    Serial.println(".");
    
  while (!Serial) {
    ; 
  }
  pinMode(intr1, INPUT);
  pinMode(intr2, INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(relayPin, OUTPUT);
}
void loop() 
{    
  if(readPir == HIGH)
  {  
    if(analogRead(ldrPin) < 800)
    {          
          digitalWrite(relayPin, HIGH);
          light_status = 1;
          startTimer();
       if(statusPir==LOW)
       {  
          counting = counting + 1;
          Serial.print("pir reads high, was low, counting to ");
          Serial.println(counting);
          statusPir = HIGH;
          Serial.println("pir status set high, no increment before goes low");
       }
    }
  }
     
   else  
   {
       digitalWrite(relayPin, LOW);
       light_status = 0;
       if (statusPir == HIGH) 
       {
        Serial.println("pir reads low, was high");
        Serial.println("pir status set low, can increment now");
        statusPir = LOW;
     }
    } 
}

void startSystem(){
  statusPir = 1;
  timer = 0;
}


void startTimer(){

    for(timer = 0; timer  < 200; timer++)
    {

      // For testing:
            Serial.print("1 - ");
            Serial.println(digitalRead(intr1));
            Serial.print("2 - ");
            Serial.println(digitalRead(intr2));

      // Reset timer:            
       // if (digitalRead(intr1)==HIGH || digitalRead(intr2)==HIGH){
       //     timer=0;
       // }
        
        Serial.println(timer);
        delay(100);
    }  
}
