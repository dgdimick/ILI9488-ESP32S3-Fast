#include <SPI.h>
#include <ILI9488-ESP32S3.h>

// Pin definitions (adjust as needed for your wiring)
#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8

ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

int y = 0;
const int textHeight = 30;

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextSize(3);  // ~30px high
  tft.setTextColor(ILI9488_GREEN, ILI9488_BLACK);  // Green text, black background
  tft.setTextWrap(false);
}

void loop() {
  // Clear the previous line
  tft.fillRect(0, y, 320, textHeight, ILI9488_BLACK);

  // Update y position
  y += textHeight;
  if (y > tft.height()) {
    y = 0;
  }

  // Draw new line of text
  tft.setCursor(20, y);
  tft.print("Hello ILI9488!");

  delay(500);  // Adjust scroll speed
}
