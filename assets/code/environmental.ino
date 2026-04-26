#include "Grove_Temperature_And_Humidity_Sensor.h"
#include <Wire.h>
#include "rgb_lcd.h"
#include <SD.h>

#define DHTTYPE DHT11                     //temperature and humidity model
#define DHTPIN 2                          //temperature and humidity pin

const int chipSelect = 4;                 //SD pin
int button = 6;                           //button pin
int led[] = {7, 8, 9, 10, 3, 5};          //LED pin array
int moistureVal = A0;                     //soil moisture sensor
int light = A1;                           //light detection sensor pin
unsigned long plantnumber = 1;            //starting plant count
int numLed = 6;                           //number of LEDs
int readTime = 60000;                     //take a reading every minute
File myFile;                              //create myFile

DHT dht(DHTPIN,DHTTYPE);                  //initializing sensor pin and model number
float tempval;                            //decimal for temperature
float humidityval;                        //decimal for humidity

rgb_lcd lcd;                              //create rgb

void setup() {
  Serial.begin(9600);                     //initialize Serial
    while(!Serial);

  dht.begin();                            //initialize temp and humidity sensor
    delay(500);

  digitalWrite(button,HIGH);              //set button state
    delay(100);

  for (int p = 0; p < numLed; p++) {      //initialize LED pins
    pinMode(led[p], OUTPUT);          
  }
    delay(100);

  pinMode(light,INPUT);                   //initialize light sensor

  lcd.begin(16, 2);                       //initialize row followed by column
  lcd.setRGB(255, 255, 255);              // Initial backlight color

  delay(5000);

  Serial.print("Initializing SD card...");
  lcd.setCursor(2,0);
    lcd.print("Initializing");            //visiual to see if SD is initializing
    lcd.setCursor(4, 1);
    lcd.print("SD card");
  
  delay(5000);

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed.");
    lcd.setCursor(3,0);
    lcd.print("No SD Card");              //lcd screen will show if no SD card is found
    lcd.setCursor(4, 1);
    lcd.print("Detected");
    while (true);
  }
  lcd.clear();
  Serial.println("initialization done.");
    lcd.setCursor(2,0);
    lcd.print("Initializing");            //visiual to see if SD is initialized
    lcd.setCursor(6, 1);
    lcd.print("Done");

  myFile = SD.open("final.csv", FILE_WRITE);  //creates file named final.csv meaning its a commas deleted excel
  
  delay(5000);

  lcd.clear();

  if (myFile) {
    lcd.setCursor(4,0);
    lcd.print("Creating");                //visiual to see if files are creatd
    lcd.setCursor(5, 1);
    lcd.print("Files");
    Serial.println("Initializing Headers");
    myFile.print("plant,");               //one reading for multiple plants
    //myFile.print("time_min,");          //multiple readings for one plant
    myFile.print("temp,");
    myFile.print("humidity_percent,");
    myFile.print("moisture_percent,");
    myFile.println("light_percent");
    myFile.close();
  delay(5000);
    Serial.println("Headers written.");   //print to serial if the file was composed correctly
  } else {
    Serial.println("Failed to open file for writing headers.");
    lcd.setCursor(2,0);
    lcd.print("Can't Create");            //visiual to see if file isn't created
    lcd.setCursor(6, 1);
    lcd.print("File");
  }
  delay(1000);
    lcd.clear();
    Serial.println("Setup is complete");
    lcd.setCursor(4, 0);                  
    lcd.print("Welcome");                 //type welcome to show screen is working
    lcd.setCursor(0, 1);                  
    lcd.print("Ready to Begin!");
  delay(100);
  for (int p = 0; p < numLed; p++) {      //turn off LED pins
    digitalWrite(led[p], LOW);          
  }
}

void clearAll() {                         //turns off all LEDs
  for (int i = 0; i < numLed; i++) {
    digitalWrite(led[i],LOW);
      delay(10);
  }
}

float averageHumidity(int numReadings) {  //average humidity readings
  float total = 0.0;
  for(int i=0; i<numReadings; i++){
    total += dht.readHumidity();          //read humidity sensor pin
  }
  delay(10);
  return total/numReadings;
}

void loop() {
  while(digitalRead(button) == LOW){}     //only reads when button is pressed
  //delay(readTime);                      //switch between button press and constant reading

  lcd.clear();                            //clear lcd from previous state
  clearAll();                             //clear all LEDs

  float water = analogRead(moistureVal);  //function to read averaged moisture

if (water > 0) {
  int lightReading = analogRead(light);   //function to read light
  int lightPercent = map(lightReading, 0, 800, 0, 100);

  float moisture = analogRead(moistureVal);                 //function to read averaged moisture (for serial printing)
  int moisturePercent = map(moisture,0,650,0,100);          //function to convert moisture to percent (for serial printing)
  int moisturePercentC = constrain(moisturePercent,0,100);  //the meter sometimes went above 100 for standing water so now it wont
  int numLit = map(water,0,650,0,numLed);                   //function to light up LEDs based on moisture level
    for (int i = 0; i < numLit; i++) {
      digitalWrite(led[i], HIGH);
      delay(10);
  }
  
  tempval = dht.readTemperature();        //function to read temp
  humidityval = averageHumidity(5);       //function to read average humidity

    
    Serial.print("Plant #");              //print to serial plant number
    Serial.print(plantnumber);            
    Serial.print(", ");   
    Serial.print(tempval);                //print to serial temperature
    Serial.print("*C,");
    Serial.print(" Humidity: ");          //print to serial humidity
    Serial.print(humidityval);            
    Serial.print("%, Moisture: ");
    Serial.print(moisturePercentC);       //print to serial moisture reading
    Serial.print("%, Light: ");
    Serial.print(lightPercent);           //print to serial light reading
    Serial.println("%");
    

    lcd.setCursor(0, 0);                  //set cursor to first row for lcd screen
    lcd.print(tempval);                   //print temperature to lcd
    lcd.print("C ");
    lcd.print("Light:");                  //print light to lcd
    lcd.print(lightPercent);
    lcd.print("%");
    lcd.setCursor(0, 1);                  //set cursor to second row
    lcd.print("Humidity: ");              //print humidity to lcd
    lcd.print(humidityval);
    lcd.print("%");

    myFile = SD.open("final.csv", FILE_WRITE);

  if (myFile) {
    myFile.print(plantnumber);            //print plant number to excel sheet
    myFile.print(",");
    myFile.print(tempval);                //print temperature to excel sheet
    myFile.print(",");
    myFile.print(humidityval);            //print humidity to excel sheet
    myFile.print(",");
    myFile.print(moisturePercentC);       //print moisture to excel sheet
    myFile.print(",");
    myFile.println(lightPercent);         //print light to excel sheet
    myFile.close();
  }

  plantnumber++;                          //increase plant number or time if single plant is active

  delay(2500);
  } else {
    lcd.setCursor(5, 0);                  // if the soil moisture sensor detects no reading
    lcd.print("No Plant");                // the logger stops recording and throws up this error message
    lcd.setCursor(5, 1);
    lcd.print("Detected");
  }
}