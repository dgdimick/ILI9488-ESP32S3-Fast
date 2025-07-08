#include <SPI.h>
#include <ILI9488.h>

// Pin definitions
#define TFT_CS    10
#define TFT_DC     9
#define TFT_RST    8
#define TFT_BL     7

ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST); // hardware SPI

void setup() {
  Serial.begin(115200);

  // Start SPI
  SPI.begin(12, -1, 11);  // SCK=12, MISO=unused, MOSI=11

  // Init display
  tft.begin();

  // Turn on backlight
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);

  tft.fillScreen(ILI9488_BLACK);
  tft.setTextColor(ILI9488_ORANGE);
  tft.setTextSize(3);
  tft.setCursor(20, 50);
  tft.println("Hello ILI9488!");
}

void loop() {
  // nothing
}
