#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

#define PIN            6

#define NUMPIXELS      7

#define COLOURNUMBER 3

#define PIXELNUMBER 7

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const byte ledPin0 = 9;
const byte ledPin1 = 10;
const byte ledPin2 = 11;
const byte interruptPin0 = 2;
const byte interruptPin1 = 3;
const byte interruptPin2 = 18;
long colournumber; // Generates a random number
volatile byte state = LOW;
long pixelColors[] = {pixels.Color(0, 150, 0),pixels.Color(150, 150, 0),pixels.Color(255, 0, 144), };
unsigned long prevTime = 0;
unsigned long currentTime = 0;
unsigned int Speed =10000;
int j,k;
void setup() {
  randomSeed(analogRead(0));
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif

  pixels.begin(); // This initializes the NeoPixel library.
  pinMode(ledPin0, OUTPUT);
  pinMode(interruptPin0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin0), blink2, CHANGE);
  pinMode(ledPin1, OUTPUT);
  pinMode(interruptPin1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), blink, CHANGE);
  pinMode(ledPin2, OUTPUT);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), blink3, CHANGE);
}

void loop() {


  long pixelnumber; // Random pixel
  
  currentTime = millis();

  if (currentTime - prevTime >= 4000) {
    prevTime = currentTime;
    for(int i=0; i< PIXELNUMBER; i++){
      pixels.setPixelColor(i, pixels.Color(0, 0, 0));
    }
  k=random(0, COLOURNUMBER);
  j=random(0, PIXELNUMBER);
    pixels.setPixelColor(j, pixelColors[k]);
    pixels.show();
    
  }

}


void blink() {
  if (k == 0) {
    digitalWrite(ledPin0, HIGH);
    pixels.setPixelColor(j,pixels.Color(0, 0, 0));
    pixels.show();
    delay(300);
    digitalWrite(ledPin0, LOW);
    
    
  } else {
    digitalWrite(ledPin0, LOW);
  }
}

void blink2() {
  if (k == 1) {
    digitalWrite(ledPin1, HIGH);
    pixels.setPixelColor(j,pixels.Color(0, 0, 0));
    pixels.show();
    delay(300);
    digitalWrite(ledPin1, LOW);
    
    
  } else {
    digitalWrite(ledPin1, LOW);
  }
}

void blink3() {
  if (k == 2) {
    digitalWrite(ledPin2, HIGH);
    pixels.setPixelColor(j,pixels.Color(0, 0, 0));
    pixels.show();
    delay(300);
    digitalWrite(ledPin2, LOW);
    
    
  } else {
    digitalWrite(ledPin2, LOW);
  }
}
