#include "ESP8266WiFi.h" 
#include <Wire.h>  // This library is already built in to the Arduino IDE
include <LiquidCrystal_I2C.h> //This library you can add via Include Library > Manage Library > 

 
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup()
{
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  lcd.init();   // initializing the LCD
  lcd.backlight(); // Enable or Turn On the backlight 

}
 
void loop()
{

    int n = WiFi.scanNetworks();

 if (n == 0)
 {
  

  lcd.setCursor(0, 0);
  lcd.print("no networks found"); // Start Print text to Line 1
  lcd.setCursor(0, 1);      
  lcd.print("--------"); // Start Print Test to Line 2
}
 
  else
  {
    lcd.setCursor(0, 0);
    lcd.print(n);
    lcd.setCursor(0, 1);
    lcd.print(" networks found ");
    delay(2000);
    for (int i = 0; i < n; ++i)
    {
      // Print SSID and RSSI for each network found
      lcd.setCursor(0, 0);
      lcd.print("                ");
      lcd.setCursor(0, 0);
      lcd.print(i + 1);
      lcd.print(": ");
      lcd.setCursor(0, 1);
      lcd.print("                ");
      lcd.setCursor(0, 1);  
      lcd.print(WiFi.SSID(i));
      /*
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?" ":"*");*/
      delay(2000);
    }
  }


  // Wait a bit before scanning again
  delay(5000);
  
  
}
