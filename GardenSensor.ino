/*This program is designed to use the feather board to read temp and humidity 
 * using the DHT11 sensor, and read moisture using diy moisture sensor, and save data to text file.
 * It also needs to trigger a solenoid water valve
 * based on the moisture reading. 
 */

#include <LiquidCrystal.h>
#include <DHT.h>

#define MOISTURE_PIN A0
#define DHTPIN 1
#define DHTTYPE DHT11 
//#define SOLENOID 14

// moisture state
int solenoidPin = 14;
int current_moisture = 0;
int tempPin = 0;

//                RS  E  D4 D5  D6  D7
LiquidCrystal lcd(16, 2, 0, 15, 13, 12);
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  lcd.begin(16, 2);
  dht.begin();
  pinMode(solenoidPin, OUTPUT);

}

void loop(){

  digitalWrite(solenoidPin, LOW);

  //start with a moisture check turning the water valve on if necassary
  current_moisture = analogRead(MOISTURE_PIN);
  
  while (current_moisture < 280){
    digitalWrite(solenoidPin, HIGH);  
    delay(7200);
  }   

  current_moisture = analogRead(MOISTURE_PIN);
  float humidity = dht.readHumidity();
  float temp = dht.readTemperature(true);
  
  // print out to lcd       
  lcd.print("T       H    ");
  lcd.setCursor(2, 0);
  lcd.print(temp);
  lcd.setCursor(10,0);
  lcd.print(humidity);
  
  // Display Moisture on second row
  int moistureReading = analogRead(current_moisture);
  lcd.setCursor(0, 1);
  //         ----------------
  lcd.print("Water         ");  
  lcd.setCursor(6, 1);
  lcd.print(current_moisture);
   
  delay(10000);
  
}
