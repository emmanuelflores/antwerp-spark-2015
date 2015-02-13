// This #include statement was automatically added by the Spark IDE.
#include "neopixel/neopixel.h"
#include "application.h"


// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN D2
#define PIXEL_COUNT 10
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

int button=D0;
int buttonval=0;
int counter=0;
int websitebutton=0;
int kleur = 0;

bool state = HIGH;

void setup() 
{
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  pinMode(button, INPUT);
  Spark.variable("kleur", &kleur, INT);
  Spark.function("tag", tagfunction);
  
  pinMode(D5, INPUT);
  
}

void loop(){
    
buttonval = digitalRead(button);

if (buttonval == 1){
    counter = counter + 1;
}

if (counter %2 == 0){
    groenworden();
    strip.show();
    kleur = 1;
}
    
if (counter %2 != 0){
    roodworden();
    strip.show();
    kleur = 2;
}

delay(10);
    
}


void groenworden(){
    for(int i=0;i<strip.numPixels();i++){
            strip.setPixelColor(i,255, 0, 0);
        }
}

void roodworden(){
    for(int i=0; i<strip.numPixels(); i++){
        strip.setPixelColor(i,0, 255, 0);
        }   
}

int tagfunction(String kleur) {

if (kleur = 1){
    groenworden();
    strip.show();
    kleur = 2;
}

if (kleur = 2){
    roodworden();
    strip.show();
    kleur = 1;
}

delay(10);

    return 200; // This is checked in the web app controller for validation
}