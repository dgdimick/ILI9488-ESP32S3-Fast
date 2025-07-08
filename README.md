# ILI9488-ESP32S3-FAST Arduino Library

**Updated July 2025**

This is a fast and simplified fork of [jaretburkett's ILI9488 library](https://github.com/jaretburkett/ILI9488), modified for compatibility with ESP32-S3 and other ESP32 variants.

##  Features

- Optimized for **ESP32-S3** (also works on ESP32 and ESP32-S2)
- Supports **ILI9488** SPI displays
- Confirmed compatibility with **ST7796S** 480x320 SPI displays
- Uses hardware SPI for high performance
- Includes fast screen-clearing and RGB332 support

## Supported Display Controllers

| Controller | Interface | Resolution | Status |
|------------|-----------|------------|--------|
| ILI9488    | SPI (4-wire) | 480x320 |  Fully Supported |
| ST7796S    | SPI (4-wire) | 480x320 |  Compatible (confirmed working)* |

> \* The ST7796S controller is not explicitly initialized but is compatible with the ILI9488 command set. The library functions (text, graphics, etc.) have been verified to work on ST7796S modules with proper SPI wiring.

## ?? Example Sketches

- `ESP32-S2-Hello_World-simple.ino` — Basic test (works on ILI9488 and ST7796S)
- `ESP32-S3-Hello_World-simple.ino` - Basic test (works on ILI9488 and ST7796S)
- `Speed_test.ino` — Fast text rendering
- `Bouncing_Ball.ino` — Simple animation

## ?? Installation

1. Clone or download this repository.
2. Copy the folder to your `Documents/Arduino/libraries/` directory.
3. Restart the Arduino IDE.

## Wiring Example (ESP32-S3)

```cpp
#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8
#define TFT_BL   39  // Optional: Backlight control pin

## Wiring Example (ESP32-S2)

```cpp
#define TFT_CS   37
#define TFT_DC   33
#define TFT_RST  35
#define TFT_LED  39  // Backlight pin

I’ve included the original README content from the source repository below for reference.

---

## Original README (by Jaret Burkett)

This library is for support for the 320x480 TFT controller over 4-wire SPI. It is based heavily on the [Adafruit\_ILI9341](https://github.com/adafruit/Adafruit_ILI9341) library and is designed to work with the [Adafruit\_GFX library](https://github.com/adafruit/Adafruit-GFX-Library).

I have made some heavy modifications, as the typical Adafruit TFT libraries are designed to work with 16-bit color (RGB565), and the ILI9488 can only do 24-bit (RGB888) color in 4-wire SPI mode. You can still use the library EXACTLY like you would for 16-bit mode color—the colors are converted before sending to the display.

What this means is:

* Things will be slower than normal.
* Not only do you have to write twice as many pixels as a normal 240x320 display (153,600px vs 76,800px),
* But you also have to do a lightweight conversion on each color and write 3 bytes instead of 2 bytes per pixel.

For this reason, I do **not recommend** an AVR-based Arduino for this library, although it will still work.

> ? Highly recommended: Faster microcontrollers based on ARM or ESP32 such as:
>
> * ESP32 (this fork supports ESP32-S3)
> * Teensy
> * [STM32duino](https://github.com/rogerclarkmelbourne/Arduino_STM32)
> * Arduino Zero
> * Arduino Due

On STM32duino, DMA is supported and therefore performance is significantly better.

