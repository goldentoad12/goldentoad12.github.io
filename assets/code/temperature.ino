#include <SD.h>
#include <math.h>

//This was on the grove website as to how to convert the temp sensor reading to temperature

const int chipSelect =4;
File myFile;
//grove temp sensor needed code
const int B = 4275;
const int R0 = 100000;
const int pinTempSensor = A0;
int readDelay = 30000;

#if defined(ARDUINO_ARCH_AVR)
#define debug  Serial
#elif defined(ARDUINO_ARCH_SAMD) ||  defined(ARDUINO_ARCH_SAM)
#define debug  SerialUSB
#else
#define debug  Serial
#endif

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  // wait for Serial Monitor to connect. Needed for native USB port boards only:
  while (!Serial);

  delay(100);

  Serial.print("Initializing SD card...");

  if (!SD.begin(chipSelect)) {
    Serial.println("initialization failed.");
    while (true);
  }

  Serial.println("initialization done.");
  myFile = SD.open("tempo.csv", FILE_WRITE);
  
  delay(1000);

  if (myFile) {
  Serial.println("Initializing Headers");
  myFile.print("Time (s),");
  myFile.print("Temp (C),");
  myFile.println("Site");
  myFile.close();
  delay(1000);
  Serial.println("Headers written.");
  } else {
    Serial.println("Failed to open file for writing headers.");
  }
  delay(1000);
  Serial.println("Setup is complete");
}

void loop() {
  delay(readDelay);

  int a = analogRead(pinTempSensor);

  float R = 1023.0/a-1.0;
  R = R0*R;

  float temperature = 1.0/(log(R/R0)/B+1/298.15)-273.15;  //this is how grove said to do it

  //Serial.println("Temperature rading successful");

  unsigned long currentTimeMillis = millis();
  float timeInSeconds = currentTimeMillis / 1000.0;
  int timeCorrected = timeInSeconds - 3.02;             //  found this to roughly be how long it takes the setup to initialize

  myFile = SD.open("tempo.csv", FILE_WRITE);

  if (myFile) {
    Serial.print(timeCorrected);
    Serial.print(", ");
    Serial.println(temperature);

    myFile.print(timeCorrected);
    myFile.print(",");
    myFile.print(temperature);
    myFile.print(",");
    myFile.println("outside");

    myFile.close(); 
  }

  //Serial.println("Writing Succesful");
}





