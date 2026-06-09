#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin = 13;
const int buzzerPin = 8;

const int dotDuration = 200; 
const int dashDuration = dotDuration * 3;
const int toneFrequency = 800;

const char* morseAlfabe[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",    // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",  // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."          // S-Z
};

const char* morseRakamlar[] = {
  "-----", ".----", "..---", "...--", "....-", 
  ".....", "-....", "--...", "---..", "----."  
};

void setup() {
  Serial.begin(9600); 
  
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("Metin Giriniz...");
}

void loop() {
  
  if (Serial.available() > 0) {
    String gelenMetin = Serial.readStringUntil('\n');
    gelenMetin.trim(); 
    
    
    for (int i = 0; i < gelenMetin.length(); i++) {
      char harf = gelenMetin[i];
      karakteriIsle(harf);
    }
    
   
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Metin Giriniz...");
  }
}


void karakteriIsle(char harf) {
  
  harf = toupper(harf);
  if (harf == 'Ç') harf = 'C';
  if (harf == 'Ğ') harf = 'G';
  if (harf == 'İ' || harf == 'ı') harf = 'I';
  if (harf == 'Ö') harf = 'O';
  if (harf == 'Ş') harf = 'S';
  if (harf == 'Ü') harf = 'U';

  String morseKodu = "";

  
  if (harf >= 'A' && harf <= 'Z') {
    morseKodu = morseAlfabe[harf - 'A'];
  } 
  
  else if (harf >= '0' && harf <= '9') {
    morseKodu = morseRakamlar[harf - '0'];
  } 
  
  else if (harf == ' ') {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("[BOSLUK]");
    delay(dotDuration * 7); 
    return;
  } 
  
  else {
    return; 
  }

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Harf: ");
  lcd.print(harf);
  lcd.setCursor(0, 1);
  lcd.print("Sinyal: ");

  for (int i = 0; i < morseKodu.length(); i++) {
    char sinyal = morseKodu[i];
    lcd.print(sinyal); 
    
    if (sinyal == '.') {
      sinyalVer(dotDuration);
    } else if (sinyal == '-') {
      sinyalVer(dashDuration);
    }
  }

  delay(dotDuration * 3); 
}

void sinyalVer(int sure) {
  digitalWrite(ledPin, HIGH);
  tone(buzzerPin, toneFrequency);
  delay(sure);
  
  digitalWrite(ledPin, LOW);
  noTone(buzzerPin);
  delay(dotDuration); 
}

