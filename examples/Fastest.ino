#include <SPI.h>
#include <ILI9488-ESP32S3.h>

#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8

ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

char currentChar = 33;  // Start at '!'
const int fontSize = 4;
const int charWidth = 6 * fontSize;
const int charHeight = 8 * fontSize;

int cursorX = 0;
int cursorY = 0;

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(1);  // Landscape mode
  tft.setTextSize(fontSize);
  tft.setTextWrap(false);
  tft.fillScreen(ILI9488_BLACK);
  tft.setTextColor(ILI9488_GREEN, ILI9488_BLACK);  // Green text on black
}

void loop() {
  // Draw character at current position
  tft.setCursor(cursorX, cursorY);
  tft.print(currentChar);

  // Move cursor
  cursorX += charWidth;
  if (cursorX + charWidth > tft.width()) {
    cursorX = 0;
    cursorY += charHeight;
  }

  // If bottom is reached, reset to top and advance char
  if (cursorY + charHeight > tft.height()) {
    cursorX = 0;
    cursorY = 0;
    currentChar++;
    if (currentChar > 126) currentChar = 33;
    // No screen clear — just overwrite
  }
}
