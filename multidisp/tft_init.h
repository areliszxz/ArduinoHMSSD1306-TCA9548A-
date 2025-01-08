#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Fonts/muMatrix8ptRegular.h"
#include "Fonts/Dialog_italic_8.h"
#include "Fonts/muHeavy8ptBold.h"
#include "Fonts/FreeSans9pt7b.h"
#include "iot_iconset_16x16.h"

const short width = 128;  

#define SCREEN_WIDTH2 128
#define SCREEN_HEIGHT2 64
Adafruit_SSD1306 display(SCREEN_WIDTH2, SCREEN_HEIGHT2, &Wire, -1);

//0.91"
Adafruit_SSD1306 display91 = Adafruit_SSD1306(128, 32, &Wire);

// Select I2C BUS
void TCA9548A(uint8_t bus){
  Wire.beginTransmission(0x70);  // TCA9548A address
  Wire.write(1 << bus);          // send byte to select bus
  Wire.endTransmission();
  Serial.print(bus);
}



