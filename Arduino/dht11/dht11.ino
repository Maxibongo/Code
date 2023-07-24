#include <LiquidCrystal.h>
#include <DHT.h>

// Wetterstation mit einem einfachen LC-Display


#define DHTPIN 2 //Der Sensor wird an PIN 2 angeschlossen    
#define DHTTYPE DHT11    // Es handelt sich um den DHT11 Sensor

DHT dht(DHTPIN, DHTTYPE); //Der Sensor wird ab jetzt mit „dth“ angesprochen
LiquidCrystal lcd(12, 11, 6, 5, 4, 3); // Pins des LCD festlegen


void setup()
{
  dht.begin(); //DHT11 Sensor starten
  // LCD einschalten
  lcd.begin(16, 2); // Display mit 16 Zeichen und 2 Zeilen
  lcd.setCursor(0, 0); //Startposition: Erstes Zeichen in der oberen Zeile
  lcd.print("Wetterstation"); // Das soll permanent in der oberen Zeile angezeigt werden
  Serial.begin(9600);
}

void loop()
{
   delay(2000); //Zwei Sekunden Vorlaufzeit bis zur Messung (der Sensor ist etwas träge)

  float Luftfeuchtigkeit = dht.readHumidity(); //die Luftfeuchtigkeit auslesen /speichern
  float Temperatur = dht.readTemperature();//die Temperatur auslesen / speichern
  
  // Ausgabe auf LCD
  lcd.setCursor(0, 1);
  lcd.print(Temperatur);
  lcd.print("\337C "); // \337 -> Grad
  lcd.print(Luftfeuchtigkeit);
  lcd.print("%");
  Serial.print(Temperatur);
  Serial.print(Luftfeuchtigkeit);
}
