bool state = HIGH;

int SliderPin = A0;    // select the input pin for the potentiometer
int ledPinY = D3;   // select the onboard LED of the spark board
int val = 0;       // variable to store the value coming from the sensor
int mapval = 0; // variable used to re-map the value coming from the sensor
int mapValY = 0;
int Button = D5;    // select the input pin for the potentiometer
int waarde=0; 

void setup() {
    pinMode(D0,OUTPUT);
    pinMode(D1,OUTPUT);
    digitalWrite(D0,HIGH); // turn on D7 by default
    digitalWrite(D1,HIGH);
    Spark.function("test", testFunction);
    Spark.function("test2",test2Function);
    pinMode(ledPinY, OUTPUT);  // declare the ledPin as an OUTPUT
    Spark.variable("RAWSlider", &val, INT); // declare spark variable for the sensor
    Spark.variable("MAPSlider", &mapval, INT); // spark variable of remapped valueint Button = D5;    // select the input pin for the potentiometer
    pinMode(Button, INPUT);
    Spark.variable("rawclick", &waarde, INT);
}

void loop() {
    
    waarde=digitalRead(Button);
    
      val = analogRead (SliderPin);
    mapval = map(val, 0, 4090, 0, 255);

    
    if(val<100){
        digitalWrite(ledPinY, 0);

    }
    else if(val>100 && val <4000){
        digitalWrite(ledPinY, 1);
        delay(4090/5-val/5);
        digitalWrite(ledPinY, 0);
        delay(4090/6-val/6);
       
    }
    else if(val>4000){
        digitalWrite(ledPinY, 1);
    
        
    }
    delay (5);
}

int testFunction(String args) {
    state = !state; // toggle the state
    digitalWrite(D0,state); // update the LED so we can see some action
    return 200; // This is checked in the web app controller for validation
}    
int test2Function(String args) {
    state = !state; // toggle the state
    digitalWrite(D1,state); // update the LED so we can see some action
    return 200; // This is checked in the web app controller for validation
}