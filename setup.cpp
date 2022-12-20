#include "config.h"
#include "globals.h"
#include "functions.h"
#include <EEPROM.h>                             // Library to read & store info in EEPROM long term memory

#include "model/Environment.h"						// My code to wrap the BME280
#include "model/Gas.h"								// My code to wrap the CCS811
#include "model/Lightning.h"						// My code to wrap the AS3935
#include "model/RealTimeClock.h"					// My code to wrap the VMA301
#include "model/TFTHelper.h"
/***************************************/
/* ----------- SETUP CODE ------------ */
/***************************************/

void setup(void)
{
  /* --- Start serial & print sketch info --- */
  Serial.begin(9600);
  Serial.println("----------------------------------");
  Serial.print("Arduino is running Sketch: ");
  Serial.println(__FILE__);
  Serial.print("Compiled on: ");
  Serial.print(__DATE__);
  Serial.print(" at ");
  Serial.println(__TIME__);
  Serial.println("----------------------------------");
  Serial.println();

  /* --- RGB LED pins --- */
  if(LEDenabled)  //set pins for RGB LED & set everything low => black, but only if LEDenabled = true
  {
    pinMode(LEDgnd, OUTPUT);   digitalWrite(LEDgnd, LOW);
    pinMode(LEDg, OUTPUT);     digitalWrite(LEDg, LOW);
    pinMode(LEDr, OUTPUT);     digitalWrite(LEDr, LOW);
    pinMode(LEDb, OUTPUT);     digitalWrite(LEDb, LOW);
  }
  /* --- DIGITAL outputs --- */
  pinMode(GreenOutPin, OUTPUT);     digitalWrite(GreenOutPin, LOW);
  pinMode(YellowOutPin, OUTPUT);    digitalWrite(YellowOutPin, LOW);
  pinMode(RedOutPin, OUTPUT);       digitalWrite(RedOutPin, LOW);

  /* --- Check first boot & if true, set values to default settings --- */
  if(EEPROM.read(firstBoot_EEPROMaddr))
  {
    //it's the first time the EarthListener has booted! Set default values
    EEPROM.write(AS3935_SPI_EEPROMaddr, false);   //set AS3935 interface to I2C
    EEPROM.write(AS3935_outdoor_EEPROMaddr, false);       //set AS3935 to indoor use
    EEPROM.write(globalSense_EEPROMaddr, 2);      //set AS3935 sensitivity to 2 (medium)
    EEPROM.write(Buzzer_EEPROMaddr, true);        //set buzzer on
    EEPROM.write(MetricON_EEPROMaddr, true);      //set values to metric
    EEPROM.write(firstBoot_EEPROMaddr, false);    //set firstboot on false, this will not be run again
  }

  //Init a screen
  TFTHelper myScreen;

  //CCS811 sensor:
  Gas myGas;
  myGas.connect();
  GasView myGasView(&myGas,&myScreen);

  //AS3935 sensor:
  Lightning myLightning;
  myLightning.connect();
  LightningView myLightningView(&myLightning,&myScreen);

  //BME280 sensor
  Environment myEnv;
  myEnv.connect();
  EnvironmentView myEnvView(&myEnv, &myScreen);

  //read value from EEPROM if Temp is in °F or °C and lightning units are in km or mi
  MetricON = EEPROM.read(MetricON_EEPROMaddr);  //read metric or imperial state from memory. If not set, this will be true, since all EEPROM addresses are 0xFF by default

  /* --- set buzzer pin & read value from EEPROM --- */
  BuzzerEnabled = EEPROM.read(Buzzer_EEPROMaddr);
  pinMode(BuzzerPin, OUTPUT);
  digitalWrite(BuzzerPin, LOW);


  /* --- SD card feedback --- */
  //Serial.println("***SD card feedback***");
  //Serial.print("Initializing...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(SS, OUTPUT);
  // see if the card is present and can be initialized:
  //TODO: ignore SD for now
  /*if (SD.begin(chipSelect))
  {
      Serial.println(" card initialized!");
      SDpresent = 1;
      tft.setTextColor(GREEN); 
      tft.print("DETECTED");
      //Check if our logfile is already on the card
     // if(SD.exists(logFileName))
     // {
      //  Serial.print("Logfile '");
      //  Serial.print(logFileName);
      //  Serial.println("' exists!");
      //  logFileExists = 1;
     // }
  }
  else
  {
     Serial.println(" card failed, or not present!");
     SDpresent = 0;
     tft.setTextColor(RED); 
     tft.print("NOT FOUND");
  }
  Serial.println();
*/
  /* -- init the RTC module (RUN ONCE AFTER INSTALLING A RTC MODULE, THEN COMMENT OUT THIS BLOCK) */
  // Init a new chip by turning off write protection and clearing the clock halt flag. 
  // These methods needn't always be called. See the DS1302 datasheet for details.
  /*
  rtc.writeProtect(false);
  rtc.halt(false);
  // Make a new time object to set the date and time. Example: Saturday 14th of December 2019, 22:52:00
  Time newT(2019, 12, 14, 22, 52, 00, Time::kSaturday);
  // Set the time and date on the chip
  rtc.time(newT);
  */
  

  /* --- check if RTC is present --- */
  RealTimeClock myRTC;
  myRTC.connect();
  //myRTC.getDayOfWeek();
  
  /* --- end of boot, wait 2 secs & set interrupt state, then show info screen --- */
  delay(2000);
  myLightning.isTriggered = false;
  slideShowPlaying = 0;   //we always start without slide show
  //create one controller
  EarthListenerController elc(&myEnv, &myEnvView, &myGas, &myGasView, &myLightning, &myLightningView, &myRTC);
  elc.showSummary();
  Serial.println("***End of setup, starting loop***");
  Serial.println();

}
