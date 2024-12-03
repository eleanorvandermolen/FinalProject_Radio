#include <SD.h>
#include <TMRpcm.h>

#define SD_CS_PIN 4   // SD card chip select pin
#define SPEAKER_PIN 9 // Speaker PWM output pin

TMRpcm audio;

void setup() {
  Serial.begin(9600);

  // Initialize SD card
  if (!SD.begin(SD_CS_PIN)) {
    Serial.println("SD card initialization failed!");
    while (true); // Stop if SD card initialization fails
  }

  Serial.println("SD card initialized.");

  // Initialize TMRpcm
  audio.speakerPin = SPEAKER_PIN;

  // Specify the file name
  String fileName = "HEDWIG~1.WAV";

  // Check if the file exists
  if (SD.exists(fileName.c_str())) {
    Serial.println("Playing file: " + fileName);
    audio.play(fileName.c_str());
  } else {
    Serial.println("File not found: " + fileName);
  }
}

void loop() {
  // Do nothing in the loop
}

