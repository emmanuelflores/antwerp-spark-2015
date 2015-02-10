/*
This example will read the value of a slider and transform the reading into a value between 0 and 255. This value is used to change the brightness of an LED.
NOTE : On the spark core, only pins D0 and D1 can be used to attach the LED. This is because these are the only pins which support PWM.
*/

int SliderPin = A0;    // select the input pin for the potentiometer
int ledPin = D0;   // select the onboard LED of the spark board
int val = 0;       // variable to store the value coming from the sensor
int mapval = 0; // variable used to re-map the value coming from the sensor

void setup() {
    pinMode(ledPin, OUTPUT);  // declare the ledPin as an OUTPUT
    Spark.variable("RAWSlider", &val, INT); // declare spark variable for the sensor
    Spark.variable("MAPSlider", &mapval, INT); // spark variable of remapped value
}

void loop() {
    val = analogRead(SliderPin); // read the value from the sensor
    mapval = map(val, 0, 4090, 0, 255);
    analogWrite(ledPin, mapval);
    delay(10);
}