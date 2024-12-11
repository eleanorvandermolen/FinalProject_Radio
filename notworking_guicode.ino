#include <SD.h> // Library for SD card
#include <TMRpcm.h>
#include <LiquidCrystal_I2C.h> // Liquid crystal library
#include <SoftwareSerial.h>
#include <RemoteXY.h> // library for Remote xy app

// RemoteXY connection settings
#define REMOTEXY_MODE__SOFTSERIAL
#define REMOTEXY_SERIAL_RX 2
#define REMOTEXY_SERIAL_TX 3
#define REMOTEXY_SERIAL_SPEED 9600

// RemoteXY GUI configuration
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] = {

};

// RemoteXY structure
struct {
  uint8_t play_cliffs;
  uint8_t play_hp;
  uint8_t play_jb;
  uint8_t play_fl;
  uint8_t play_wewill;
  uint8_t connect_flag;
} RemoteXY;
#pragma pack(pop)

#define SD_CS_PIN 4 // SD card chip select pin
#define SPEAKER_PIN 9 // Speaker PWM output pin

LiquidCrystal_I2C lcd(0x27, 16, 2);
TMRpcm audio;

void setup() {
  // Initialize RemoteXY
  RemoteXY_Init();

  // LCD setup
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Initializing...");
  delay(2000);

  // Audio setup
  audio.speakerPin = SPEAKER_PIN;
  if (!SD.begin(SD_CS_PIN)) {
    lcd.clear();
    lcd.print("SD Init Failed!");
    while (true);
  }

  lcd.clear();
  lcd.print("Ready!");
}

void playSong(const char* fileName, const char* songName) {
  lcd.clear();
  if (SD.exists(fileName)) {
    lcd.print("Playing: ");
    lcd.setCursor(0, 1);
    lcd.print(songName);
    audio.play(fileName);
  } else {
    lcd.print("File Not Found");
  }
}

void loop() {
  RemoteXY_Handler(); // Ensure button inputs are handled.

  if (RemoteXY.play_cliffs) {
    playSong("ERICJO~1.WAV", "Cliffs of Dover");
    RemoteXY.play_cliffs = 0;
  }

  if (RemoteXY.play_hp) {
    playSong("HEDWIG~1.WAV", "Harry Potter");
    RemoteXY.play_hp = 0;
  }

  if (RemoteXY.play_jb) {
    playSong("JINGLE~1.WAV", "Jingle Bells");
    RemoteXY.play_jb = 0;
  }

  if (RemoteXY.play_fl) {
    playSong("FLASHI~1.WAV", "Flashing Lights");
    RemoteXY.play_fl = 0;
  }

  if (RemoteXY.play_wewill) {
    playSong("WEWILL~1.WAV", "We Will Rock You");
    RemoteXY.play_wewill = 0;
  }
}
