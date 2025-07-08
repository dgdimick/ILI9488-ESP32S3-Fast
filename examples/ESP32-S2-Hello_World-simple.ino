#include <SPI.h>
#include <ILI9488-ESP32S3.h>  // Or your custom ILI9488-ESP32S3.h

#define TFT_CS   37
#define TFT_DC   33
#define TFT_RST  35
#define TFT_LED  39  // Backlight pin

ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(115200);

  // Backlight on
  pinMode(TFT_LED, OUTPUT);
  digitalWrite(TFT_LED, HIGH);

  // Set custom SPI pins: SCK = 16, MOSI = 18
  SPI.begin(16, -1, 18);

  // Initialize display
  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9488_BLACK);

  // Draw green text
  tft.setTextColor(ILI9488_GREEN, ILI9488_BLACK);
  tft.setTextSize(3);
  tft.setCursor(20, 100);
  tft.println("Hello ILI9488");
}

void loop() {
  // Nothing here
}
