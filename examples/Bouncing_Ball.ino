#include <SPI.h>
#include <ILI9488-ESP32S3.h>

// Pin definitions (adjust to your wiring)
#define TFT_CS   10
#define TFT_DC    9
#define TFT_RST   8

ILI9488 tft = ILI9488(TFT_CS, TFT_DC, TFT_RST);

// Ball properties
int x = 160, y = 120;         // Start in center
int dx = 3, dy = 2;           // Movement per frame
int radius = 10;
uint16_t ballColor = ILI9488_GREEN;
uint16_t bgColor = ILI9488_BLACK;

void setup() {
  Serial.begin(115200);
  tft.begin();
  tft.fillScreen(bgColor);
}

void loop() {
  // Erase previous ball
  tft.fillCircle(x, y, radius, bgColor);

  // Update position
  x += dx;
  y += dy;

  // Bounce off walls
  if (x - radius <= 0 || x + radius >= tft.width()) {
    dx = -dx;
  }
  if (y - radius <= 0 || y + radius >= tft.height()) {
    dy = -dy;
  }

  // Draw ball at new position
  tft.fillCircle(x, y, radius, ballColor);

//  delay(16);  // ~60 FPS
  delay(32);  // ~30 FPS
}
