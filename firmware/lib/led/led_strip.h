#ifndef LED_STRIP
#define LED_STRIP

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LedStrip
{
    private:
        Adafruit_NeoPixel strip_;

    public:
    LedStrip(uint16_t led_count, uint8_t pin):
        strip_(led_count, pin)
    {
    }

    void init()
    {
        strip_.begin();
        strip_.setBrightness( 30 );
        strip_.clear();
        set(0.2, 0.2, 0.2);
        strip_.show();
    }

    void set(float r, float g, float b)
    {
        // Convert floats to integers that the library can use
        uint8_t red = min((uint8_t) (r * 255), 255);
        uint8_t green = min((uint8_t) (g * 255), 255);
        uint8_t blue = min((uint8_t) (b * 255), 255);

        for(int i=0; i<strip_.numPixels(); i++) { // For each pixel...
                strip_.setPixelColor(i, strip_.Color(red, green, blue));
            }
        strip_.show();   // Send the updated pixel colors to the hardware.
    }
};

#endif
