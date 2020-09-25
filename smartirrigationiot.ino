#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"           // including the library of DHT11 temperature and humidity sensor  //including the library of SimpleTimer
#define DHTTYPE DHT11      // DHT 11

#define dht_dpin D0
#define r D1
char j;
WidgetLCD lcd(2);
DHT dht(dht_dpin, DHTTYPE); 
char auth[] = "CgcPAt8oXzwMURWylQ0dgrhMWTKM2zqm";            // You should get Auth Token in the Blynk App.
                                           // Go to the Project Settings (nut icon).

char ssid[] = "Redmi";    // Your WiFi credentials.
char pass[] = "876543210";  // Set password to "" for open networks.
float t;                                   // Declare the variables 
float h;
void setup()
{
    Serial.begin(9600);// Debug console
    Blynk.begin(auth, ssid, pass);
    dht.begin();
}
void loop()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  lcd.print(0, 0, "MOISTURE"); 
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Serial.print(digitalRead(r));
  
  int counter = 0;
  if(Serial.available()>0)
  {
    while(Serial.available()==0);
    j=Serial.read();
    check();
  }

  Blynk.run();
}
void check()
{
  if(j=='1'){
    lcd.clear();
  lcd.print(0,1, "Dry");
  delay(1000);}
  if(j=='2'){
    lcd.clear();
    lcd.print(0,1,"Wet");
    delay(1000);
  }
}
