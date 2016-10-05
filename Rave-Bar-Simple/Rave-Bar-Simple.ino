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

int wilson_sky_red[59] = {154,139,145,136,153,124,122,154,139,145,136,153,245,168,213,246,230,249,245,204,148,128,135,241,250,141,153,224,239,239,202,165,250,247,182,253,251,247,231,253,233,157,253,248,227,250,240,239,142,104,145,137,247,189,229,242,114,190,159};
int wilson_sky_green[59] = {156,126,134,127,133,107,109,156,126,134,127,133,202,130,139,181,171,223,139,134,166,129,127,172,180,139,143,134,140,210,133,145,162,186,162,227,197,134,135,209,168,134,211,134,138,159,162,121,139,105,116,124,135,118,129,199,108,110,110};
int wilson_sky_blue[59] = {154,131,137,130,136,107,111,154,131,137,130,136,189,133,140,156,161,207,136,132,144,134,133,160,155,142,143,132,125,189,134,145,148,153,156,211,180,127,135,189,160,141,189,128,137,135,129,115,134,112,120,125,130,119,121,170,115,111,111};
int wilson_water_red[59] = {154,130,159,138,141,138,146,147,138,155,149,155,157,140,146,93,131,144,115,124,152,135,120,125,130,132,108,139,129,146,193,122,118,129,111,129,105,127,110,114,113,108,110,120,117,109,116,105,103,127,111,114,124,98,102,105,121,105,153};
int wilson_water_green[59] = {148,133,157,140,140,137,148,145,136,153,152,152,155,144,149,109,134,150,122,128,152,139,128,136,138,138,119,148,138,146,187,130,131,138,122,139,119,138,125,126,126,122,123,132,133,122,131,122,123,142,131,135,138,120,122,127,139,128,158};
int wilson_water_blue[59] = {135,127,145,132,127,127,143,131,126,140,145,142,143,136,140,111,127,136,120,122,143,133,127,135,136,132,118,142,136,133,167,128,131,131,120,135,121,138,127,126,128,124,126,131,135,125,133,126,126,141,131,138,135,126,123,128,137,131,148};

void setup() {
  S_1.begin();
  S_2.begin();
  turnOffAll();
}

void loop() {
  runWilson();
  turnOffAll();
  delay(1000);
  
}

void runWilson() {
  for (int i=0; i<59; i++) {
    turnOnS1(wilson_sky_red[i], wilson_sky_green[i], wilson_sky_blue[i], 0);
    delay(100);
  }
}

void turnOnS1(int r, int g, int b, int onTime) {
  for (int i=0; i<72; i++) {
    S_1.setPixelColor(i, S_1.Color(r,g,b));
  }
  S_1.show();
  delay(onTime);
}

void turnOnS2(int r, int g, int b, int onTime) {
  for (int i=0; i<72; i++) {
    S_2.setPixelColor(i, S_2.Color(r,g,b));
  }
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


