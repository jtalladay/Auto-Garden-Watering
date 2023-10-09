# Auto-Garden-Watering
Automatic garden watering system using home made moisture sensors
Hardware
- Adafruit Feather (arduoino architecture)
- Moisture Sensor
- Humidity/Temperature Sensor
- LCD Screen for readout
  
Moisture Sensors:
- Sensors were made using two sanded, galvanized nails installed 1 cm apart in a plastic housing.
- Wires are soldered to the head of each nail
- Resistance is measured between the two nails

Program
- Program will measure the resistance from the moisture sensor
- This resistance will indicate the moisture level of the soil
- A signal will be sent to a relay based on a designated resistance range
- Moisture level, Temperature, Humidity will print out to LCD screen and also write to text file for database implementation
