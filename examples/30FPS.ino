#include <SPI.h>
#include <ILI9488-ESP32S3.h>

#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8

ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

char currentChar = 33;  // Start at '!'
const int charsPerLine = 20;
const int fontSize = 4;  // Text size (larger characters)
const int charWidth = 6 * fontSize;
const int lineHeight = 8 * fontSize;

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);  // Rotate display 90 degrees (landscape)
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextSize(fontSize);
  tft.setTextWrap(false);
}

void loop() {
  // Clear line area (now vertical due to rotation)
  tft.fillRect(100, 0, lineHeight, tft.height(), ILI9488_BLACK);

  // Draw 20 repeating characters rotated
  tft.setCursor(100, 10);  // X and Y are swapped due to rotation
  tft.setTextColor(ILI9488_GREEN, ILI9488_BLACK);
  for (int i = 0; i < charsPerLine; i++) {
    tft.print(currentChar);
  }

  // Advance to next ASCII character
  currentChar++;
  if (currentChar > 126) currentChar = 33;

  delay(33);  // ~30 FPS
}
