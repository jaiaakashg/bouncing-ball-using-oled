#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET    -1  // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Ball properties
int ballX = SCREEN_WIDTH / 2;
int ballY = SCREEN_HEIGHT / 2;
int ballRadius = 5;
int xSpeed = 2;
int ySpeed = 2;

void setup() {
  // Initialize with I2C address 0x3C (128x64)
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }

  display.clearDisplay(); // Clear the display buffer
}

void loop() {
  display.clearDisplay(); // Clear the display buffer

  // Update ball position
  ballX += xSpeed;
  ballY += ySpeed;

  // Bounce off edges
  if (ballX <= ballRadius || ballX >= (SCREEN_WIDTH - ballRadius)) {
    xSpeed = -xSpeed;
  }
  if (ballY <= ballRadius || ballY >= (SCREEN_HEIGHT - ballRadius)) {
    ySpeed = -ySpeed;
  }

  // Draw ball
  display.fillCircle(ballX, ballY, ballRadius, SSD1306_WHITE);

  // Update display
  display.display();

  // Delay to control animation speed
  delay(30);
}

