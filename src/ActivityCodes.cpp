#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

const int chipSelect = 10;

int position = 0;

File dataFile;

const int potPin = A0; 

int sensorValue = 0; 

void setup() {

    // Activity 1
    Serial.begin(9600);
    Serial.println("Program Started");
    Serial.println("Initializing SD Card...");
    
    // Activity 2
    if(SD.begin(chipSelect)) { // Check if SD card is detected
    Serial.println("SD Card Found");
    }
    else {
    Serial.println("SD Card Not Found");
    }

    // Activity 3
    dataFile = SD.open("data.txt", FILE_WRITE); // Open hello.txt
    dataFile.println("Hello Dawson"); // Write Hello Dawson
    dataFile.close(); // Close the file

    // Activity 4
    sensorValue = analogRead(potPin); 
    Serial.print("Value = "); 
    Serial.println(sensorValue); 
    delay(500);

    // Activity 5
    dataFile = SD.open("sensor.txt", FILE_WRITE); // Open sensor.txt
    dataFile.println("Save: "); // Write Save:
    dataFile.close(); // Close the file

    // Activity 6
    dataFile = SD.open("sensor.csv", FILE_WRITE); // Open sensor.csv
    if (dataFile) {
        dataFile.println("Time,Value"); // Write header
        dataFile.close(); // Close the file
        Serial.println("CSV Header Written");
    } 
    else {
        Serial.println("Failed to Create File");
    }
}
 
void loop() {

    // Activity 7/8
    int sensorValue = analogRead(potPin); // Read the potentiometer value
    
    unsigned long timeSeconds = millis() / 1000; // Get time in seconds
    
    Serial.print("Time: ");
    Serial.print(timeSeconds);
    Serial.print(" s    "); 

    Serial.print("Value: ");
    Serial.println(sensorValue);

    dataFile = SD.open("sensor.csv", FILE_WRITE); // Open sensor.csv

    if (dataFile) {
        dataFile.print(timeSeconds); // Write time
        dataFile.print(","); // Write comma
        dataFile.println(sensorValue); // Write value
        
        dataFile.close(); // Close the file
        
        Serial.println("Data Saved");
    }  
    else {
        Serial.println("Error Opening File");
    }
    
    Serial.println(position);
    delay(1000);

}
