////////////////////////////////////////////////////////
//                 FRACTION BRACELET                  \\
//                                                    \\
//                  Brilliant Labs &                  \\
//             George Street Middle School            \\
//          Sketch compiled by Lilli & Anna           \\
//                                                    \\
//                                                    \\
//         Code adapted from Adafruit Industries      \\
////////////////////////////////////////////////////////


// This 'library' retrieves commands specifically for neopixels. 

#include <Adafruit_NeoPixel.h> 

#define PIN 9 // Where DATA exits the board
#define NUM 36   // Total Number of NeoPixels

// The 'int' commands below define values that you would 
// like to use later. 

int ONENINTH = 4;
int TWONINTH = 8;
int THREENINTH = 12;
int FOURNINTHS = 16;
int FIVENINTHS = 20;
int SIXNINTHS = 24;
int SEVENNINTHS = 28;
int EIGHTNINTHS = 32;
int FULL = 36;

// There are two different types of neopixels, this line
// defines the RGBW strip that has 4 different pixels, 
// one for each of the colours: red, green, blue and white. 

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM, PIN, NEO_GRBW + NEO_KHZ800);

// Arduino codes require two central functions 'setup' and 'loop' 
// the 'setup' command tells the trinket how to prepare the neopixels.

void setup() {
  
  strip.begin(); // This tells the strip to get ready for code. 
  strip.show(); // Turns all pixels off. 
  strip.setBrightness(127); // Those pixels can get awfully bright values 0-255.
  
}

// Here comes the 'loop' function. This code repeats in a 'loop'.

void loop() { 

  strip.show(); // The GO command. 

// HERE COMES YOUR CODE.
//
// Here is a picture of your neopixel strip [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
// while there are 9, they are not numbered  0   1   2   3   4   5   6   7   8
// as you would expect, the first neopixel
// actually occupies the 'zero' position. 
// if you want the first through fourth 
// neopoixels to light up then you will 
// tell neopixels (0-3) to illuminate. 
//
// HERE WE GO...

// FIRST FRACTION OF ONE NINTH

  white(0, 3, 20); 

// SECOND FRACTION OF ONE NINTH

  white(4, 8, 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 3, 20); // Three numbers = Start Pixel, End Pixel, Wait
  off(0, 0, 20); // Off

// Now it's up to you to fill in the values of the variables below. 
// It is a good idea to verify and upload your code each time you 
// change a value. 

// THIRD FRACTION OF ONE NINTH

  white(9, 12, 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 8, 20); // Three numbers = Start Pixel, End Pixel, Wait

// FOURTH FRACTION OF ONE NINTH

  white(13, 16, 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 12, 20); // Three numbers = Start Pixel, End Pixel, Wait  

// FIFTH FRACTION OF ONE NINTH

  white(17, 20 , 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 16, 20); // Three numbers = Start Pixel, End Pixel, Wait

// SIXTH FRACTION OF ONE NINTH

  white(21, 24, 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 20, 20); // Three numbers = Start Pixel, End Pixel, Wait

// SEVENTH FRACTION OF ONE NINTH

  white(25, 28, 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 24, 20); // Three numbers = Start Pixel, End Pixel, Wait

// EIGHTH FRACTION OF ONE NINTH

  white(29, 32, 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 28, 20); // Three numbers = Start Pixel, End Pixel, Wait

// NINTH FRACTION OF ONE NINTH

  white(33, 36, 20); // Three numbers = Start Pixel, End Pixel, Wait
  rainbow(0, 32, 20); // Three numbers = Start Pixel, End Pixel, Wait
  
}

//DON'T CHANGE ANYTHING BELOW HERE. 

void rainbow(uint8_t StartPixel,uint8_t EndPixel,uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) { // This defines Colour DON'T CHANGE
    for(i=StartPixel; i<(EndPixel+1); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void white(uint8_t StartPixel,uint8_t EndPixel,uint8_t wait) {
  for(uint16_t i=StartPixel; i<(EndPixel+1); i++) {
    strip.setPixelColor(i, 0, 0, 0, 255);
    strip.show();
    delay(wait);
  }
 }

 void off(uint8_t StartPixel,uint8_t EndPixel,uint8_t wait) {
  for(uint16_t i=StartPixel; i<(EndPixel+1); i++) {
    strip.setPixelColor(i, 0, 0, 0, 0);
    strip.show();
    delay(wait);
  }
 }

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
