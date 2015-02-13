int lightsensorPin = A0;    // select the input pin for the potentiometer
int ledPin1 = D0;   // select the onboard LED of the spark board
int val = 0;       // variable to store the value coming from the sensor
int mapval = 0; // variable used to re-map the value coming from the sensor
int delaytime= 100;
int Timer= 0;
int AlarmTimer= 5000;
int ledPin2= D1; 


void setup() {
    pinMode(lightsensorPin, INPUT);
    pinMode(ledPin1, OUTPUT);  // declare the ledPin as an OUTPUT
    pinMode(ledPin2, OUTPUT); 
    Spark.variable("RAWlight", &val, INT); // declare spark variable for the sensor
}

void loop() {
   val = analogRead(lightsensorPin); // read the value from the sensor
    
    if (val<3100)
    {
        digitalWrite(ledPin2, 0);
        delay(delaytime);
        Timer=delaytime+Timer;
        
        if (Timer>AlarmTimer)
        {
            digitalWrite(ledPin1, 1);
            digitalWrite(ledPin2,0);
        }
    }
    else 
    {
        Timer=0;
        digitalWrite(ledPin2, 1);
        digitalWrite(ledPin1,0);
        delay(100);
    }
}