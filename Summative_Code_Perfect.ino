#include "pitches.h" //This file is used to define frequencies as musical notes
#include <LiquidCrystal.h> //This file is used to be able to edit what is shown on LED

int ledPinA = 5; //Red LED is used to turn on when YDB is played
int ledPinB = 13; //Green LED is used to turn on when YDB is played

int buttonApin = 4; //Button A pin is used to play Havana with corresponding text on the LCD
int buttonBpin = 3; //Button B pin is used to play YDB with corresponding text on LCD
int buttonCpin = 6; //Button C pin is used to stop music and will have a goodbye message of thank you for listening

//defined pins that components are plugged into 

byte leds = 0;

LiquidCrystal lcd(7, 8, 9, 10, 11, 12); //pins for LCD screen

// notes in the melody for Havana (bars are based on sheet music):
int melodyA[] = {
  NOTE_AS3,//Notes in Bar 4
  NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, 0, //Notes in Bar 5
  0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 6
  NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, 0, //Notes in Bar 7
  0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 8
  NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, 0,//Notes in Bar 9
  0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 10
  NOTE_D4, NOTE_AS3, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 11
  NOTE_D4, NOTE_A3, 0, NOTE_AS3, NOTE_A3, NOTE_AS3, NOTE_A3, NOTE_AS3, NOTE_AS3, //Note in Bar 12
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, //Notes in Bar 13
  0, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, //Notes in Bar 14
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4, //Notes in Bar 15
  0, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, //Notes in Bar 16
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_A4,//Notes in Bar 17
  0, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, NOTE_AS3, //Notes in Bar 18
  NOTE_G4, NOTE_G4, NOTE_G4, NOTE_D4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_D4,//Notes in Bar 19
  0, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_G3, NOTE_G3, NOTE_G3, //Notes in Bar 20
  NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_AS4, //Notes in Bar 21
  NOTE_C5, NOTE_A4, 0, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, //Notes in Bar 22
  NOTE_G4, NOTE_D4, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 23
  NOTE_D4, NOTE_A3, 0, 0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, //Notes in Bar 24
  NOTE_F4, NOTE_G4, NOTE_F4, NOTE_G4, NOTE_D5, NOTE_C5, NOTE_AS4, //Notes in Bar 25
  NOTE_C5, NOTE_A4, 0, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, NOTE_F4, //Notes in Bar 26
  NOTE_G4, NOTE_D4, 0, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_AS4, NOTE_A4, //Notes in Bar 27
  0, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_G4, NOTE_AS3, //Notes in Bar 28
  NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, 0, //Notes in Bar 29
  0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 30
  NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, 0, //Notes in Bar 31
  0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 32
  NOTE_D4, NOTE_D4, NOTE_AS3, NOTE_AS3, NOTE_G3, 0, //Notes in Bar 33
  0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_DS4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 34
  NOTE_D4, NOTE_AS3, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_AS3, //Notes in Bar 35
  NOTE_D4, NOTE_A3, 0, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, //Notes in Bar 36
  0, //Notes in Bar 37
  };

// note durations: 4 = quarter note, 8 = eighth note, etc. for Havana:
int noteDurationsA[] = {
  8, //Note timings in Bar 4
  8, 8, 8, 8, 4, 4, //Note timings in Bar 5
  8, 8, 8, 8, 8, 8, 8, 8, //Note timings in Bar 6
  8, 8, 8, 8, 4, 4, //Note timings in Bar 7
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 8
  8, 8, 8, 8, 8, 4, 4, //Note Timings in Bar 9
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 10
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 11
  8, 8, 8, 8, 8, 8, 8, 16, 16, //Note Timings in Bar 12
  12, 12, 12, 12, 12, 12, 8, 8, 8, 8, //Note Timings in Bar 13
  4, 8, 8, 8, 8, 8, 16, 16, //Note Timings in Bar 14
  12, 12, 12, 12, 12, 12, 8, 8, 8, 8, //Note Timings Bar 15
  4, 8, 8, 8, 8, 8, 16, 16, //Note Timings in Bar 16
  16, 8, 16, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 17
  4, 8, 8, 8, 8, 8, 16, 16, //Note Timings in Bar 18
  16, 8, 16, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 19
  4, 8, 8, 8, 8, 16, 16, 8, //Note TImings in Bar 20
  8, 4, 8, 8, 8, 8, 8, //Note TImings in Bar 21
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 22
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 23
  8, 8, 4, 8, 16, 16, 16, 16, 8, //Note TImings in Bar 24
  8, 4, 8, 8, 8, 8, 8, //Note TImings in Bar 25
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 26
  8, 8, 8, 8, 6, 16, 8, 8, //Note Timings Bar 27
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 28
  8, 8, 8, 8, 4, 4, //Note Timings in Bar 29
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 30
  8, 8, 8, 8, 4, 4, //Note Timings in Bar 31
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 32
  8, 8, 8, 8, 4, 4, //Note Timings in Bar 33
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 34
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 35
  8, 8, 8, 8, 8, 8, 8, 8, //Note Timings in Bar 36
  8, //Note Timings in Bar 37  
  };

// notes in the melody for YDB (bars are based on sheet music):
int melodyB[] = {
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, //Bar 1 Notes
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, //Bar 2 Notes
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, //Bar 3 Notes
  NOTE_CS4, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, //Bar 4 Notes
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, //Bar 5 Notes
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, //Bar 6 Notes
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_CS5, NOTE_AS4, NOTE_GS4, NOTE_AS4, //Bar 7 Notes
  NOTE_CS4, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4,//Bar 8 Notes
  NOTE_FS4, NOTE_FS4, 0, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, //Bar 9 Notes
  NOTE_FS4, NOTE_FS4, 0, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, 0, //Bar 10 Notes
  NOTE_FS4, NOTE_FS4, 0, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, //Bar 11 Notes
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, //Bar 12 Notes
  NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, NOTE_CS4, NOTE_DS4, //Bar 13 Notes
  NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, 0, //Bar 14 Notes
  NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_DS4, NOTE_CS4, NOTE_DS4, //Bar 15 Notes
  0, NOTE_AS4, NOTE_GS4, NOTE_AS4, NOTE_GS4, NOTE_FS4, NOTE_FS4, NOTE_FS4, //Bar 16 Notes
  };

// note durations: 4 = quarter note, 8 = eighth note, etc. for YDB:
int noteDurationsB[] = {
  8, 8, 8, 8, 8, 8, 8, 8, //Rhythm Bar 1
  8, 8, 8, 8, 8, 8, 4, //Rhythm Bar 2
  8, 8, 8, 8, 8, 8, 8, 8, //Rhythm Bar 3
  8, 8, 8, 8, 8, 8, 4, //Rhythm Bar 4
  8, 8, 8, 8, 8, 8, 8, 8, //Rhythm Bar 5
  8, 8, 8, 8, 8, 8, 4, //Rhythm Bar 6
  8, 8, 8, 8, 8, 8, 8, 8, //Rhythm Bar 7
  16, 16, 8, 8, 8, 8, 8, 8, 16, 16, //Rhythm Bar 8
  8, 8, 16, 8, 8, 8, 16, 16, 16, 8, //Rhythm Bar 9
  8, 8, 16, 8, 8, 8, 16, 8, 8, //Rhythm Bar 10
  8, 8, 16, 8, 8, 8, 16, 16, 16, 8, //Rhythm Bar 11
  8, 8, 8, 8, 16, 16, 8, 4, //Rhythm Bar 12
  8, 8, 8, 16, 16, 8, 8, 8, 16, 16, //Rhythm Bar 13
  8, 8, 8, 16, 16, 8, 8, 8, 8, //Rhythm Bar 14
  8, 8, 8, 16, 16, 8, 8, 8, 8, //Rhythm Bar 15
  8, 8, 8, 8, 16, 16, 8, 4, //Rhythm Bar 16
  };

void setup() {
  pinMode(ledPinA, OUTPUT); //defines LED as an output
  pinMode(ledPinB, OUTPUT); //defines LED as an output
  pinMode(buttonApin, INPUT_PULLUP);  //defines buttonA as an input
  pinMode(buttonBpin, INPUT_PULLUP); //defines buttonB as an input
  pinMode(buttonCpin, INPUT_PULLUP); //defines buttonC as an input
}

void loop() 

#define delayTime 1500 //delayTime is defined as 1.5 seconds

{ //if function for Havana
  if (digitalRead(buttonApin) == LOW) //If button A is pressed
    { //then
    digitalWrite(ledPinA, HIGH); //Red LED is turned on
    digitalWrite(ledPinB, LOW); //Green LED is turned off
    lcd.begin(16, 2); //LCD setup to display text
    lcd.print("Now Playing:"); //First line of LCD displays Now Playing
    lcd.setCursor(0, 1); //LCD setup to display text
    lcd.print("Havana"); //Second line of LCD displays Havana
  
      for (int thisNote = 0; thisNote < 252; thisNote++) //start Havana song
        {
        // to calculate the note duration, take 1.8 seconds divided by the note type.
        //e.g. quarter note = 1800 / 4, eighth note = 1800/8, etc.
        int noteDuration = 1800 / noteDurationsA[thisNote];
        tone(2, melodyA[thisNote], noteDuration);
        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;
        delay(pauseBetweenNotes);
        // stop the tone playing:
        noTone(2);
    
          if (digitalRead(buttonCpin) == LOW) //If button C is pressed after Button A has already been pressed and while Havana is still playing
            { //then
            digitalWrite(ledPinA, LOW); //Red LED is turned off
            digitalWrite(ledPinB, LOW);//Green LED is turned off
            lcd.begin(16, 2); //LCD setup to display text
            lcd.print("Thank You For"); //First line displays "Thank You For"
            lcd.setCursor(0, 1); //LCD setup to display text
            lcd.print("Listening!"); //Second line displays "Listening!"
            delay(delayTime); //Lcd displays Thank You For Listening for 1.5 seconds
            lcd.begin(16, 2); //LCD setup to display text
            lcd.print(""); //LCD displays nothing, is blank, after thank you message
            lcd.setCursor(0, 1); //LCD setup to display text
            lcd.print(""); //Lcd displays a blank screen for the rest of the time until another button is pressed
            break; //Music Stops
            //Note at this time Button A can be pressed to start Havana again, or Button B can be pressed to play YDB   
            }
        }
     //After song finishes playing, LCD displays thank you message and then turns off (is left blank)
     lcd.begin(16, 2); //LCD setup to display text
     lcd.print("Thank You For"); //First line displays "Thank You For"
     lcd.setCursor(0, 1); //LCD setup to display text
     lcd.print("Listening!"); //Second line displays "Listening!"
     delay(delayTime); //Lcd displays Thank You For Listening for 1.5 seconds
     digitalWrite(ledPinA, LOW); //Red LED is turned off
     digitalWrite(ledPinB, LOW); //Green LED is turned off
     lcd.begin(16, 2); //LCD setup to display text
     lcd.print(""); //LCD displays nothing, is blank, after thank you message
     lcd.setCursor(0, 1); //LCD setup to display text
     lcd.print(""); //Lcd displays a blank screen for the rest of the time until another button is pressed
     //Note at this time Button A can be pressed to start Havana again, or Button B can be pressed to play YDB
   }


  if (digitalRead(buttonBpin) == LOW) //If button B is pressed
    { //then
    digitalWrite(ledPinB, HIGH); //Green LED is turned on
    digitalWrite(ledPinA, LOW); //Red LED is turned off
    lcd.begin(16, 2); //LCD setup to display text
    lcd.print("Now Playing:"); //First line of LCD displays Now Playing
    lcd.setCursor(0, 1); //LCD setup to display text
    lcd.print("YDB"); //Second line of LCD displays YDB
  
      for (int thisNote = 0; thisNote < 135; thisNote++) //Start YDB song
           {
           // to calculate the note duration, take two and a half seconds divided by the note type. Since YDB is a slower song its number value is greater than Havana's.
           //e.g. quarter note = 2500 / 4, eighth note = 2500/8, etc.
           int noteDuration = 2500 / noteDurationsB[thisNote];
           tone(2, melodyB[thisNote], noteDuration);
           // to distinguish the notes, set a minimum time between them.
           // the note's duration + 30% seems to work well:
           int pauseBetweenNotes = noteDuration * 1.30;
           delay(pauseBetweenNotes);
           // stop the tone playing:
           noTone(2);
    
            if (digitalRead(buttonCpin) == LOW) //If button C is pressed after Button B has already been pressed and while YDB is still playing
              { //then
              digitalWrite(ledPinA, LOW); //Red LED is turned off
              digitalWrite(ledPinB, LOW); //Green LED is turned off
              lcd.begin(16, 2); //LCD setup to display text
              lcd.print("Thank You For"); //First line displays "Thank You For"
              lcd.setCursor(0, 1); //LCD setup to display text
              lcd.print("Listening!"); //Second line displays "Listening!"
              delay(delayTime); //Lcd displays Thank You For Listening for 1.5 seconds
              lcd.begin(16, 2); //LCD setup to display text
              lcd.print(""); //LCD displays nothing, is blank, after thank you message
              lcd.setCursor(0, 1); //LCD setup to display text
              lcd.print(""); //Lcd displays a blank screen for the rest of the time until another button is pressed
              break; //Music Stops
              //Note at this time Button A can be pressed to start YDB again, or Button B can be pressed to play Havana  
              }  
           }
    //After song finishes playing, LCD displays thank you message and then turns off (is left blank)       
    lcd.begin(16, 2); //LCD setup to display text
    lcd.print("Thank You For"); //First line displays "Thank You For"
    lcd.setCursor(0, 1); //LCD setup to display text
    lcd.print("Listening!"); //Second line displays "Listening!"
    delay(delayTime); //Lcd displays Thank You For Listening for 1.5 seconds
    digitalWrite(ledPinA, LOW); //Red LED is turned off
    digitalWrite(ledPinB, LOW); //Green LED is turned off
    lcd.begin(16, 2); //LCD setup to display text
    lcd.print(""); //LCD displays nothing, is blank, after thank you message
    lcd.setCursor(0, 1); //LCD setup to display text
    lcd.print(""); //Lcd displays a blank screen for the rest of the time until another button is pressed
    //Note at this time Button A can be pressed to start YDB again, or Button B can be pressed to play Havana 
    }
}
  
