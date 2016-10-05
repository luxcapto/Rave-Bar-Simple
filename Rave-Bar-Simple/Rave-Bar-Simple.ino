#include <Adafruit_NeoPixel.h>
#include <avr/power.h>

/* STRIP 1 & 2 DEFINES & SETUP (RIGHT PORT ON CONTROLLER) */

#define S_1_PIN           2
#define S_2_PIN           14

#define S_1_PIXELS        72
#define S_2_PIXELS        72

Adafruit_NeoPixel S_1 = Adafruit_NeoPixel(S_1_PIXELS, S_1_PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel S_2 = Adafruit_NeoPixel(S_2_PIXELS, S_2_PIN, NEO_GRB + NEO_KHZ800);

/* RESET VALUES BACK TO ZERO */

int S_1_Red = 0;
int S_1_Blue = 0;
int S_1_Green = 0;

int S_2_Red = 0;
int S_2_Blue = 0;
int S_2_Green = 0;

void setup() {
  S_1.begin();
  S_2.begin();
  turnOffAll();
  columnOne(255,0,0,500);
  columnTwo(0,255,0,500);
  columnThree(0,0,255,500);
  columnFour(255,0,0,500);
  columnFive(0,255,0,500);
  columnSix(0,0,255,500);
  delay(10000);

}

void loop() {
  runFader();
}

void runFader() {

  int r = random(0,200);
  int g = random(0,200);
  int b = random(0,200);
  int randomness = random(0,10);
  int onTime = 30;

  for(int i=0;i<S_1_PIXELS;i++) {
    S_1.setPixelColor(i, S_1.Color(r, i*randomness, b));
    S_2.setPixelColor(i, S_2.Color(r, i*randomness, b));
    delay(onTime);
    S_1.show(); 
    S_2.show();
  } 
  delay(1000);
}

void columnOne(int r, int g, int b, int onTime) {
    for (int i=0; i<11; i++) {
      S_1.setPixelColor(i, S_1.Color(r,g,b));
      S_2.setPixelColor(i, S_2.Color(r,g,b));
    }
    S_1.show(); 
    S_2.show();
    delay(onTime);
}

void columnTwo(int r, int g, int b, int onTime) {
    for (int i=12; i<23; i++) {
      S_1.setPixelColor(i, S_1.Color(r,g,b));
      S_2.setPixelColor(i, S_2.Color(r,g,b));
    }
    S_1.show(); 
    S_2.show();
    delay(onTime);
}

void columnThree(int r, int g, int b, int onTime) {
    for (int i=24; i<35; i++) {
      S_1.setPixelColor(i, S_1.Color(r,g,b));
      S_2.setPixelColor(i, S_2.Color(r,g,b));
    }
    S_1.show(); 
    S_2.show();
    delay(onTime);
}

void columnFour(int r, int g, int b, int onTime) {
    for (int i=36; i<47; i++) {
      S_1.setPixelColor(i, S_1.Color(r,g,b));
      S_2.setPixelColor(i, S_2.Color(r,g,b));
    }
    S_1.show(); 
    S_2.show();
    delay(onTime);
}

void columnFive(int r, int g, int b, int onTime) {
    for (int i=48; i<59; i++) {
      S_1.setPixelColor(i, S_1.Color(r,g,b));
      S_2.setPixelColor(i, S_2.Color(r,g,b));
    }
    S_1.show(); 
    S_2.show();
    delay(onTime);
}

void columnSix(int r, int g, int b, int onTime) {
    for (int i=60; i<71; i++) {
      S_1.setPixelColor(i, S_1.Color(r,g,b));
      S_2.setPixelColor(i, S_2.Color(r,g,b));
    }
    S_1.show(); 
    S_2.show();
    delay(onTime);
}

void turnOffAll() {
  turnOffS1();
  turnOffS2();
}

void turnOffS1() {
  for(int i=0;i<S_1_PIXELS;i++){
    S_1.setPixelColor(i, S_1.Color(0, 0, 0));
  } 
  S_1.show();
}

void turnOffS2() {
  for(int i=0;i<S_2_PIXELS;i++){
    S_2.setPixelColor(i, S_2.Color(0, 0, 0));
  } 
  S_2.show();
}


