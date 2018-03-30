////////////////////////////////////////////////////////
//                 Red Dress SKIRT Sketch             \\
//                                                    \\
//                  Heart Truth 2016                  \\
//             Bliss Carman Middle School             \\
//          Sketch compiled by Taylor Gregan,         \\
//             Keegan Goodine, Alice Newling &        \\
//                  Elizabeth McTimoney               \\
//            (Lucinda Mills & Jacob Lingley)         \\
//                                                    \\
//         Code adapted from Adafruit Industries      \\
////////////////////////////////////////////////////////

// This first bit of the sketch retrieves the code designed
// so that the neopixels function properly.

#include <Adafruit_NeoPixel.h>

// Here we are defining the variable PIN which allows the
// sketch to know which PIN on the FLORA to code. Any of
// the pins will do, but why not go with 6?

#define PIN 6

// This next line of code is important! This tells the FLORA
// what kind of neopixels are hooked up. There are three
// parameters that can change based on your installation:
// Parameter 1 = Number of Pixels in strip - start counting.
// Parameter 2 = Arduino PIN Number (you defined this earlier)
// Parameter 3 = Specifically what type of pixels are you using?
//               Some pixels have RGB LEDs, and some have RGBW.
//               Do you know which you are using? If the colours
//               look different, you are probably using RGB when
//               you have the newer RGBW (or vice versa).

Adafruit_NeoPixel strip = Adafruit_NeoPixel(233, PIN, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRBW + NEO_KHZ800);

// IMPORTANT: WHEN YOU ARE ATTACHING YOUR NEOPIXELS, IT IS GOOD
// PRACTICE TO ALWAYS AVOID HOOKING UP THE POWER WIRES FIRST.
// ATTACH THEM IN THE FOLLOWING ORDER: DATA, GROUND AND THEN POWER.

// OK! So, this line below sets up your favourite colours for when the
// heart beat simply sparkles as she starts to come out.
// They are all equal numbers to make white light!

//                          R   G   B
uint8_t myColors[][3] = {{255, 255, 255}, // white
  {255, 255, 255}, // white
  {255, 255, 255}, // white
};

// Don't edit the line below! Who knows what will happen.

#define FAVCOLORS sizeof(myColors) / 3

// Alright, are you ready to get the code / sketch going?
// An arduino code always has two important components / sections.
// The first section (void setup) sets up the program - almost as if you are
// giving the FLORA a pre-game pep talk of what to expect.
// The second component / section (void loop) is where the magic happens:
// this is where you will code what you want to happen over and over again.

void setup() {
  // Everything you put here will run once - only once.
  // PS: Semi-colons are the punctuation that ends a line of code.

  strip.begin(); // This starts the neopixel show!
  strip.setBrightness(150); // Turn up the brightness!
  strip.show(); // Turn all pixels to 'off'

}

void loop() {
  // Everything you put here is your main code. It will run repeatedly:
  // Any time code is dealing with colour, they are measured using 3 numbers.
  // Colour codes have a value from 0-255 for each of the colours. Since
  // all visible colours are comprised of Red, Green, and Blue, those are
  // the numbers in each of the (R, G, B) sequences.
  // Newer neopixels however have an extra LED that is pure white. These will
  // have 4 numbers associated with the colour: (R, G, B, W). Often there will
  // be another number ouside of the colour code like (R, G, B) #). This is
  // the brightness - it also has a value from 0-255.

  colorWipe(strip.Color(0, 0, 0), 50);
  colorWipe(strip.Color(0, 0, 0), 50);
  colorWipe(strip.Color(0, 0, 0), 50);
  flashRandom(10, 6);  // First # is delay between flashes -
  flashRandom(8, 26);
  flashRandom(6, 25);
  flashRandom(4, 36);
  flashRandom(1, 50);
  colorWipe(strip.Color(0, 0, 0), 50); //Skirt Off // the smaller the first # is the shorter the twinkle
  //  flashRandom(12, 30); // second # is how many neopixels to simultaneously light up
  //  flashRandom(12, 30);
  //  flashRandom(12, 30);
  //  flashRandom(12, 80);
  //  flashRandom(12, 80);
  //  flashRandom(12, 80);
  theaterChase(strip.Color(127, 127, 127), 30); // Now comes the heart beat.
  // theaterChase(strip.Color(0, 0, 0), 0); // It is called theatrechase after
  //  theaterChase(strip.Color(127, 127, 127), 30); // an old-style theatre sign. This
  //  theaterChase(strip.Color(127, 127, 127), 30); // is setting the colour to white,
  //  theaterChase(strip.Color(127, 127, 127), 30); // and the background brightness.
  
 // strip.setBrightness(70);
  //rainbow(40);
  delay(25); //Will //this actually //delay?

}

// Now the code is going to tell the FLORA exactly what to do during flashing.

void flashRandom(int wait, uint8_t howmany) {

  for (uint16_t i = 0; i < howmany; i++) {
    // Pick a random favorite color!
    int c = random(FAVCOLORS);
    int red = myColors[c][0];
    int green = myColors[c][1];
    int blue = myColors[c][2];

    // Choose random neopixels from the strip

    int j = random(strip.numPixels());

    // Now we will 'fade' it in 5 steps

    for (int x = 0; x < 5; x++) {
      int r = red * (x + 1); r /= 5;
      int g = green * (x + 1); g /= 5;
      int b = blue * (x + 1); b /= 5;

      strip.setPixelColor(j, strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }

    // And now fade those neopixels out in 5 steps

    for (int x = 5; x >= 0; x--) {
      int r = red * x; r /= 5;
      int g = green * x; g /= 5;
      int b = blue * x; b /= 5;

      strip.setPixelColor(j, strip.Color(r, g, b));
      strip.show();
      delay(wait);
    }
  }
  // LEDs will be off when done (they are faded to 0)
}

// Turn skirt lights off in between flash and heart beat

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(2);
  }
}

// Now comes the specific code for the heart beat!

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j<(3/2); j++) { //do 10 cycles of chasing OR is it how many travel together?
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i++)
      {
        strip.setPixelColor(i, 255, 255, 255); // Colour of moving lights.
        if (i > 0) {
          strip.setPixelColor(i - 4, 40, 40, 40); // Background white lights.
        }
        strip.show();
        delay(40);
      }
    }
  }
}

// This is here because it declares the values for Rainbow.

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// This is here because it is asking for Wheel to be declared. We declared it.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
