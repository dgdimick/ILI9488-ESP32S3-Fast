# ILI9488-ESP32S3-FAST Arduino Library

**Updated July 2025**

This is a fast and simplified fork of [jaretburkett's ILI9488 library](https://github.com/jaretburkett/ILI9488), modified for compatibility with ESP32-S3 and other ESP32 variants.

##  Features

- Optimized for **ESP32-S3** (also works on ESP32 and ESP32-S2)
- Supports **ILI9488** SPI displays
- Confirmed compatibility with **ST7796S** 4" 480x320 SPI displays
- Uses hardware SPI for high performance
- Includes fast screen-clearing and RGB332 support

## Supported Display Controllers

| Controller | Interface | Resolution | Status |
|------------|-----------|------------|--------|
| ILI9488    | SPI (4-wire) | 480x320 |  Fully Supported |
| ST7796S    | SPI (4-wire) | 480x320 |  Compatible (confirmed working)* |

> \* The ST7796S controller is not explicitly initialized but is compatible with the ILI9488 command set. The library functions (text, graphics, etc.) have been verified to work on ST7796S modules with proper SPI wiring.

## Example Sketches

- `ESP32-S2-Hello_World-simple.ino` — Basic test (works on ILI9488 and ST7796S)
- `ESP32-S3-Hello_World-simple.ino` - Basic test (works on ILI9488 and ST7796S)
- `Speed_test.ino` — Fast text rendering
- `Bouncing_Ball.ino` — Simple animation

## Installation

1. Clone or download this repository.
2. Copy the folder to your `Documents/Arduino/libraries/` directory.
3. Restart the Arduino IDE.

## Wiring Example (ESP32-S2 and S3)

ESP32-S3
```cpp
#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8
#define TFT_BL   39  // Optional: Backlight control pin


ESP32-S2
```cpp
#define TFT_CS   37
#define TFT_DC   33
#define TFT_RST  35
#define TFT_LED  39  // Backlight pin
