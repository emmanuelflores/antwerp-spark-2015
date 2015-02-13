int SliderPin = A0;    // select the input pin for the potentiometer
int ledPin1 = D1;
int ledPin2 = D2;
int ledPin3 = D3;
int ledPin4 = D4;
int ledPin5 = D5;
int ledPin6 = D6;
int val = 0;
int buttonState = 0;
int messageButton = D0;
int val1 = 681;
int val2 = 1363;
int val3 = 2044;
int val4 = 2725;
int val5 = 3406;
int val6 = 5000;

int mapval = 0; // variable used to re-map the value coming from the sensor

void setup() {
    pinMode(ledPin1, OUTPUT);  // declare the ledPin as an OUTPUT
    pinMode(messageButton, INPUT);
    Spark.variable("RAWSlider", &val, INT); // declare spark variable for the sensor
    Spark.variable("MAPSlider", &mapval, INT); // spark variable of remapped value
    Spark.variable("knop", &buttonState, INT);
    
    pinMode(ledPin2, OUTPUT);  // declare the ledPin as an OUTPUT
    
    pinMode(ledPin3, OUTPUT);  // declare the ledPin as an OUTPUT
 
    pinMode(ledPin4, OUTPUT);  // declare the ledPin as an OUTPUT
   
    pinMode(ledPin5, OUTPUT);  // declare the ledPin as an OUTPUT
   
    pinMode(ledPin6, OUTPUT);  // declare the ledPin as an OUTPUT
    buttonState = 0;
}

void loop() {
    val = analogRead(SliderPin);
    if (val<val1){
        digitalWrite(ledPin1,1);
        digitalWrite(ledPin2,0);
        digitalWrite(ledPin3,0);
        digitalWrite(ledPin4,0);
        digitalWrite(ledPin5,0);
        digitalWrite(ledPin6,0);
        buttonState = 0;
    }
    
     else if (val<val2){
        digitalWrite(ledPin1,0);
        digitalWrite(ledPin2,1);
        digitalWrite(ledPin3,0);
        digitalWrite(ledPin4,0);
        digitalWrite(ledPin5,0);
        digitalWrite(ledPin6,0);
        buttonState = 0;
    }
    
     else if (val<val3){
        digitalWrite(ledPin1,0);
        digitalWrite(ledPin2,1);
        digitalWrite(ledPin3,1);
        digitalWrite(ledPin4,0);
        digitalWrite(ledPin5,0);
        digitalWrite(ledPin6,0);
        buttonState = 0;
    }
    
     else if (val<val4){
        digitalWrite(ledPin1,0);
        digitalWrite(ledPin2,1);
        digitalWrite(ledPin3,1);
        digitalWrite(ledPin4,1);
        digitalWrite(ledPin5,0);
        digitalWrite(ledPin6,0);
        buttonState = 0;
    }
    
     else if (val<val5){
        digitalWrite(ledPin1,0);
        digitalWrite(ledPin2,1);
        digitalWrite(ledPin3,1);
        digitalWrite(ledPin4,1);
        digitalWrite(ledPin5,1);
        digitalWrite(ledPin6,0);
        buttonState = 0;
    }
    
    else if (val<val6){
        digitalWrite(ledPin1,0);
        digitalWrite(ledPin2,1);
        digitalWrite(ledPin3,1);
        digitalWrite(ledPin4,1);
        digitalWrite(ledPin5,1);
        digitalWrite(ledPin6,1);
        
        buttonState = digitalRead(messageButton);
        
        delay(10);
        
        if (buttonState == 1) {
        blink3();
        }
        
    }
}

void blink3(){
            digitalWrite(ledPin1,0);
            digitalWrite(ledPin2,1);
            digitalWrite(ledPin3,1);
            digitalWrite(ledPin4,1);
            digitalWrite(ledPin5,1);
            digitalWrite(ledPin6,1);
            delay(500);
            digitalWrite(ledPin1,0);
            digitalWrite(ledPin2,0);
            digitalWrite(ledPin3,0);
            digitalWrite(ledPin4,0);
            digitalWrite(ledPin5,0);
            digitalWrite(ledPin6,0);
            delay(200);
            digitalWrite(ledPin1,0);
            digitalWrite(ledPin2,1);
            digitalWrite(ledPin3,1);
            digitalWrite(ledPin4,1);
            digitalWrite(ledPin5,1);
            digitalWrite(ledPin6,1);
            delay(500);
            digitalWrite(ledPin1,0);
            digitalWrite(ledPin2,0);
            digitalWrite(ledPin3,0);
            digitalWrite(ledPin4,0);
            digitalWrite(ledPin5,0);
            digitalWrite(ledPin6,0);
            delay(200);
            digitalWrite(ledPin1,0);
            digitalWrite(ledPin2,1);
            digitalWrite(ledPin3,1);
            digitalWrite(ledPin4,1);
            digitalWrite(ledPin5,1);
            digitalWrite(ledPin6,1);
            delay(500);
            digitalWrite(ledPin1,0);
            digitalWrite(ledPin2,0);
            digitalWrite(ledPin3,0);
            digitalWrite(ledPin4,0);
            digitalWrite(ledPin5,0);
            digitalWrite(ledPin6,0);
            delay(200);
            
        while (val > val1) {
            digitalWrite(ledPin1,0);
            digitalWrite(ledPin2,0);
            digitalWrite(ledPin3,0);
            digitalWrite(ledPin4,0);
            digitalWrite(ledPin5,0);
            digitalWrite(ledPin6,0);
            val = analogRead(SliderPin);
            buttonState = 0;
        }
            
}