bool state1 = LOW;
bool state2 = LOW;
bool state3 = LOW;
bool state4 = LOW;
bool lastButton = LOW;
bool ledOn = false;
int counter = 0;
int counter2 = 0;
int valButton = 0;
int valSlider = 0;
int Slider = A2;
int mapval = 0;


void setup() {
    pinMode(D0,OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    
    pinMode(D4, INPUT);
    
    pinMode(D7, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(A1, OUTPUT);
    
    pinMode(A2, INPUT);
    pinMode(A4, OUTPUT);

    
    digitalWrite(D0,LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    Spark.function("player1", testFunction);
    Spark.function("player2", testFunction2);
    Spark.function("mexican", testFunction3);
    Spark.function("count", testFunction4);
}

void loop() {

//pauze();
slider();


if (state1 == HIGH) {
    counter = 0;
    counter2 = 0;
flicker1();
}

if (state2 == HIGH) {
counter = 0;
counter2 = 0;
flicker2();
}


if (state3 == HIGH) {
    counter2 = 0;
    wave();
}

if (state4 == HIGH){
    counter = 0;
    countdown();
    
}

}



void flicker1(){
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    analogWrite(A1, 255);
    //digitalWrite(D3,HIGH);
    delay(150);
    digitalWrite(D7,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D5,LOW);
    analogWrite(A1, 0);
    //digitalWrite(D3,LOW);
    delay(150);
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    analogWrite(A1, 255);
    //digitalWrite(D3,HIGH);
    delay(150);
    digitalWrite(D7,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D5,LOW);
    analogWrite(A1, 0);
    //digitalWrite(D3,LOW);
    delay(2000);
}

void flicker2(){
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    analogWrite(A1, 255);
    //digitalWrite(D3,HIGH);
    delay(150);
    digitalWrite(D7,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D5,LOW);
    analogWrite(A1, 0);
    //digitalWrite(D3,LOW);
    delay(150);
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    analogWrite(A1, 255);
    //digitalWrite(D3,HIGH);
    delay(150);
    digitalWrite(D7,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D5,LOW);
    analogWrite(A1, 0);
    delay(200);
}

void wave(){
    counter ++;
    if(counter < 4){
        digitalWrite(D0,HIGH);
        delay(150);
        digitalWrite(D0,LOW);
        digitalWrite(D1,HIGH);
        delay(150);
        digitalWrite(D1,LOW);
        digitalWrite(D2,HIGH);
        delay(150);
        digitalWrite(D2,LOW);
        delay(150);
    }
    else if (counter > 4 && counter < 200){
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
    }
   
}

void countdown(){
    counter2 ++;
    if(counter2 < 2){
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    analogWrite(A1, 255);
    delay(1000);
    digitalWrite(D7,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D5,LOW);
    analogWrite(A1, 0);
    delay(1000);
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    analogWrite(A1, 255);
    delay(600);
    digitalWrite(D7,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D5,LOW);
    analogWrite(A1, 0);
    delay(600);
    digitalWrite(D7,HIGH);
    digitalWrite(D6,HIGH);
    digitalWrite(D5,HIGH);
    analogWrite(A1, 255);
    delay(300);
    digitalWrite(D7,LOW);
    digitalWrite(D6,LOW);
    digitalWrite(D5,LOW);
    analogWrite(A1, 0);
    delay(200);
    }
    else if (counter2 > 2 && counter2 < 200){
        digitalWrite(D0,LOW);
        digitalWrite(D1,LOW);
        digitalWrite(D2,LOW);
    }
}


/*void pauze(){
if (digitalRead(D4) == HIGH && lastButton == LOW)
  {
    D0 = !D0;
    lastButton = HIGH;
  }
  else
  {
    //lastButton = LOW;
    lastButton = digitalRead(D4);
  }
  
  digitalWrite(D0, HIGH);

}*/
    
/*    valButton = digitalRead(D4);
    if (valButton = !valButton){
    digitalWrite(D0, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    }
}*/

void slider(){
    valSlider = analogRead(Slider);
    mapval = map(valSlider, 0, 4090, 0, 255);
    analogWrite(A4, mapval);
    delay(10);
    
}

int testFunction(String args) {
    state1 = !state1; // toggle the state
    state2 = LOW;
    state3 = LOW;
    state4 = LOW;
    return 200; // This is checked in the web app controller for validation
}

int testFunction2(String args) {
    state2 = !state2; // toggle the state
    state1 = LOW;
    state3 = LOW;
    state4 = LOW;
    return 200; // This is checked in the web app controller for validation
}

int testFunction3(String args) {
    state3 = !state3; // toggle the state
    state1 = LOW;
    state2 = LOW;
    state4 = LOW;
    return 200; // This is checked in the web app controller for validation
}

int testFunction4(String args) {
    state4 = !state4;
    state1 = LOW;
    state2 = LOW;
    state3 = LOW;// toggle the state
    return 200; // This is checked in the web app controller for validation
}


    
    