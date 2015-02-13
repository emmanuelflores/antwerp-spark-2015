
int pos = 0;                                //store mapped value of potentiometer
int readPot;                                //reads value of potentiometer
int ledState=0;                             //Led on or off (could also be a boolean)

//SETUP


void setup()
{
  pinMode(A0,INPUT);                        //potentio connected to A0
  pinMode(D0,OUTPUT);                       // LED connected to D0
  Spark.function("setpos", setPosition);    // Controls LED
  Spark.variable("getpos", &pos, INT);      // Sends value of potentiometer
}

//LOOP


void loop()
{
  readPot= analogRead(A0);                  // read potentiometer
    pos = map (readPot, 0,4095, 0, 4);      // map this value
}

//Spark function for receiving value for LED

int setPosition(String posValue) {          //value from HTML
   ledState = posValue.toInt();             //store value
    digitalWrite(D0,ledState);              //turn on LED
    return 0;                               
}