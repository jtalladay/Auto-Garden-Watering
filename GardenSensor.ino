/*This program is designed to use the feather board to read temp and humidity 
 * using the DHT11 sensor, and read moisture using diy moisture sensor, and upload
 * this data to adafruit IO as well as displaying this information to an  
 * onboard LCD display. It also needs to trigger a solenoid water valve
 * based on the moisture reading. 
 */

//#include "config.h"
#include <LiquidCrystal.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define MOISTURE_PIN A0
#define DHTPIN 1
#define DHTTYPE DHT11 
//#define SOLENOID 14

// moisture state
int solenoidPin = 14;
int current_moisture = 0;
int tempPin = 0;

// set up the 'soil_moisture' feed
//AdafruitIO_Feed *soil_moisture = io.feed("soil_moisture");
//AdafruitIO_Feed *Humidity = io.feed("Humidity");
//AdafruitIO_Feed *Temperature = io.feed("Temperature");

//                RS  E  D4 D5  D6  D7
LiquidCrystal lcd(16, 2, 0, 15, 13, 12);
DHT dht(DHTPIN, DHTTYPE);

void setup() 
{
  lcd.begin(16, 2);
  dht.begin();
  pinMode(solenoidPin, OUTPUT);
  
 // connect to io.adafruit.com
  //lcd.print("Connecting to Adafruit IO");
  //io.connect();
  /*
  // wait for a connection
  while(io.status() < AIO_CONNECTED) {
   lcd.print(".");
    delay(1000);
  }
  
   // we are connected
  lcd.println();
  lcd.println(io.statusText());

  lcd.begin(16, 2);
}
*/
}
void loop(){

  //start with a moisture check turning the water valve on if necassary
  current_moisture = analogRead(MOISTURE_PIN);
  //digitalWrite(SOLENOID, LOW);

  if (current_moisture < 280){
     digitalWrite(solenoidPin, HIGH);  
    delay(7200);
  }    else {
    digitalWrite(solenoidPin, LOW);
  }
  

   // io.run(); is required for all sketches.
  // it should always be present at the top of your loop
  // function. it keeps the client connected to
  // io.adafruit.com, and processes any incoming data.
  //io.run();
  
  // grab the current state of the moisture sensor
  // read humidity (h)
  // read temperature (f)
  current_moisture = analogRead(MOISTURE_PIN);
  float h = dht.readHumidity();
  //uncomment for celsius
  //float t = dht.readTemperature();
  float f = dht.readTemperature(true);
  
  //send all values to adafruit io
  // save the current state to the analog feed
  //feed name -> save (variable name)
  //soil_moisture->save(current_moisture);
  //Humidity->save(h);
  //Temperature->save(f);
  
  // print out to lcd       
  lcd.print("T       H    ");
  lcd.setCursor(2, 0);
  lcd.print(f);
  lcd.setCursor(10,0);
  lcd.print(h);
  
  // Display Moisture on second row
  int moistureReading = analogRead(current_moisture);
  lcd.setCursor(0, 1);
  //         ----------------
  lcd.print("Water         ");  
  lcd.setCursor(6, 1);
  lcd.print(current_moisture);
   
  delay(10000);
  
}





