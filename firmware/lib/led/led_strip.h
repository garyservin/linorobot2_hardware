#ifndef LED_STRIP
#define LED_STRIP

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LedStripHW
{
    private:
        Adafruit_NeoPixel strip_;

    public:
    LedStripHW(uint16_t led_count, uint8_t pin):
        strip_(led_count, pin)
    {
    }

    void init()
    {
        strip_.begin();
        strip_.setBrightness( 30 );
        strip_.clear();
        set(50, 50, 50);
        strip_.show();
    }

    void set_strip(const void * msgin)
    {
	const omnibot_interfaces__msg__LedStrip * msg = (const omnibot_interfaces__msg__LedStrip *)msgin;

        for(uint8_t i=0; i<strip_.numPixels(); i++){
            strip_.setPixelColor(i, strip_.Color(msg->data[i].red, msg->data[i].green, msg->data[i].blue));
	}
        strip_.show();   // Send the updated pixel colors to the hardware.
    }

    void set(uint8_t red, uint8_t green, uint8_t blue)
    {
        for(int i=0; i<strip_.numPixels(); i++) { // For each pixel...
                strip_.setPixelColor(i, strip_.Color(red, green, blue));
        }
        strip_.show();   // Send the updated pixel colors to the hardware.
    }
};

#endif
