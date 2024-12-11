#include <SD.h> //Library for sd card reading
#include <TMRpcm.h>
#include <LiquidCrystal_I2C.h> // liquid crystal library

#define SD_CS_PIN 4   // SD card chip select pin
#define SPEAKER_PIN 9 // Speaker PWM output pin

LiquidCrystal_I2C lcd(0x27,16,2); 
TMRpcm audio; // library setup for sd card audio reader


void setup() {
  
  Serial.begin(9600);

  // initlaizing lcd
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Waiting...");
  delay(5000);

  audio.speakerPin = SPEAKER_PIN; 

  if (!SD.begin(SD_CS_PIN)){
    Serial.println("SD card initalization failed!");
    while (true);
  }
  Serial.println("SD card initalized");
  Serial.println("Bluetooth is ready. Waiting for song request...");


}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    String command = "";

    while (Serial.available()){
      char c = Serial.read();
      command += c;
      delay(10);
    }
    command.trim();

    Serial.print("Song Choice: ");
    Serial.println(command);

    if (command == "Harry Potter"){
      String fileName = "HEDWIG~1.WAV";
      lcd.clear();
      if (SD.exists(fileName.c_str())){
        Serial.println("Playing file: Hedwig Theme song");
        lcd.print("Playing:Harry Potter");
        audio.play(fileName.c_str());
      }
      else{
        Serial.println("File not found");
      }
    }
    if (command == "Flasing Lights"){
      String fileName = "FLASHI~1.WAV";
      lcd.clear();
      if (SD.exists(fileName.c_str())){
        Serial.println("Playing file: Flashing Lights");
        lcd.print("Playing:Falsing Lights");
        audio.play(fileName.c_str());
      }
      else{
        Serial.println("File not found");
      }
    }
    if (command =="Cliffs of Dover"){
      String fileName = "ERICJO~1.WAV";
      lcd.clear();
      if (SD.exists(fileName.c_str())){
        Serial.println("Playing file: Cliffs of Dover");
        lcd.print("Playing:Cliffs of Dover");
        audio.play(fileName.c_str());
      }
      else{
        Serial.println("File not found");
      }
    }
    if (command == "Jingle Bells"){
      String fileName = "JINGLE~1.WAV";
      lcd.clear();
      if (SD.exists(fileName.c_str())){
        Serial.println("Playing file: Jingle Bells");
        lcd.print("Playing:Jingle Bells");
        audio.play(fileName.c_str());
      }
      else{
        Serial.println("File not found");
      }
    }
    if (command == "Star Wars"){
      String fileName = "MICHAE~1.WAV";
      lcd.clear();
      if (SD.exists(fileName.c_str())){
        Serial.println("Playing file: Star Wars");
        lcd.print("Playing:Star Wars");
        audio.play(fileName.c_str());
      }
      else{
        Serial.println("File not found");
      }
    }
    if (command == "Rock You"){
      String fileName = "WEWILL~1.WAV";
      lcd.clear();
      if (SD.exists(fileName.c_str())){
        Serial.println("Playing file: We will Rock You");
        lcd.print("Playing:Rock you");
        audio.play(fileName.c_str());
      }
      else{
        Serial.println("File not found");
      }
    }
  }

}
