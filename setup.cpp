/***************************************/
/* ----------- SETUP CODE ------------ */
/***************************************/

#include "ccs811.h"
#include "config.h"
#include "clock.h"
#include <TimeLib.h>

/* --- Global Libraries --- */
#include <EEPROM.h> // Library to read & store info in EEPROM long term memory
#include <SPI.h>    // SPI library
#include <Wire.h>   // Wire library
// externals

extern boolean AS3935_SPI;
extern volatile int AS3935IrqTriggered;
extern boolean slideShowPlaying;
#include "src/MCUFRIEND_kbv/MCUFRIEND_kbv.h"
extern MCUFRIEND_kbv tft; // we use a DRIVER IC ILI9341


/* --- BME280 air sensor --- */
#define BME280_ADDR                                                            \
  0x77 // Default I2C Address of BME280 sensor, can be 0x76 if jumper closed
#include <Adafruit_BME280.h>
extern Adafruit_BME280 myBME280;

#include "src/SparkFun_AS3935/src/SparkFun_AS3935.h"
extern SparkFun_AS3935 lightningSPI;
extern SparkFun_AS3935 lightningIIC;
extern boolean AS3935_bootOK; // value to store OK boot status of the sensor

// speaker variables
extern boolean BuzzerEnabled; // 1= Buzzer on, 0= Buzzer off => can be modified
                              // via TFT interface

// led variables
boolean LEDenabled =
    1; // 1= LED on, 0= LED off. Will also declare pins for output if turned on.

/* --- metric / imperial switch --- */
boolean MetricON; // boolean to check if values of temperature and lightning
                  // distance are set in Celsius/km or Fahrenheit/miles => can
                  // be modified via TFT interface

// protos
bool detectSD();

void bme280_setup() {
  Serial.println("***BME280 Sensor feedback***");

  tft.setCursor(15, 165);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("BME280 status: ");

  if (myBME280.begin(BME280_ADDR) == false) {
    Serial.println("BME280 Sensor connection failed!");
    tft.setTextColor(RED);
    tft.print("NOT FOUND");
  } else {
    Serial.println("BME280 Sensor connection successful!");
    tft.setTextColor(GREEN);
    tft.print("DETECTED");
  }

  // weather monitoring - setup code from
  // https://github.com/adafruit/Adafruit_BME280_Library Copyright (c) 2015,
  // Limor Fried & Kevin Townsend for Adafruit Industries
  //
  // Adafruit invests time and resources providing this open source code,
  // please support Adafruit andopen-source hardware by purchasing products
  // from Adafruit!
  //
  Serial.println("BME280: -- Weather Station Scenario --");
  Serial.println("BME280: forced mode, 1x temperature / 1x humidity / 1x "
                 "pressure oversampling,");
  Serial.println("filter off");
  myBME280.setSampling(Adafruit_BME280::MODE_FORCED,
                       Adafruit_BME280::SAMPLING_X1, // temperature
                       Adafruit_BME280::SAMPLING_X1, // pressure
                       Adafruit_BME280::SAMPLING_X1, // humidity
                       Adafruit_BME280::FILTER_OFF);
  // end code copied from Adafruit example

  MetricON = EEPROM.read(
      MetricON_EEPROMaddr); // read metric or imperial state from memory. If not
                            // set, this will be true, since all EEPROM
                            // addresses are 0xFF by default
  Serial.println();
}

void setup(void) {
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

  /* --- LCD screen feedback --- */
  Serial.println("***LCD screen feedback***");
  Serial.println(F("TFT LCD test"));
#ifdef USE_ADAFRUIT_SHIELD_PINOUT
  Serial.println(F("Using Adafruit 2.4\" TFT Arduino Shield Pinout"));
#else
  Serial.println(F("Using Adafruit 2.4\" TFT Breakout Board Pinout"));
#endif
  Serial.print("TFT size is ");
  Serial.print(tft.width());
  Serial.print("x");
  Serial.println(tft.height());
  tft.reset();

  uint16_t identifier = tft.readID();
  if (identifier == 0x9325) {
    Serial.println(F("Found ILI9325 LCD driver"));
  } else if (identifier == 0x9328) {
    Serial.println(F("Found ILI9328 LCD driver"));
  } else if (identifier == 0x4535) {
    Serial.println(F("Found LGDP4535 LCD driver"));
  } else if (identifier == 0x7575) {
    Serial.println(F("Found HX8347G LCD driver"));
  } else if (identifier == 0x9341) {
    Serial.println(F("Found ILI9341 LCD driver"));
  } else if (identifier == 0x7783) {
    Serial.println(F("Found ST7781 LCD driver"));
  } else if (identifier == 0x8230) {
    Serial.println(F("Found UC8230 LCD driver"));
  } else if (identifier == 0x8357) {
    Serial.println(F("Found HX8357D LCD driver"));
  } else if (identifier == 0x0101) {
    identifier = 0x9341;
    Serial.println(F("Found 0x9341 LCD driver"));
  } else {
    Serial.print(F("Unknown LCD driver chip: "));
    Serial.println(identifier, HEX);
    Serial.println(
        F("If using the Adafruit 2.8\" TFT Arduino shield, the line:"));
    Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
    Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
    Serial.println(
        F("If using the breakout board, it should NOT be #defined!"));
    Serial.println(
        F("Also if using the breakout, double-check that all wiring"));
    Serial.println(F("matches the tutorial."));
    identifier = 0x9341;
  }

  tft.begin(identifier);
  /*
  //Benchmark filling screen R/G/B
  Serial.println(F("Benchmark                Time (microseconds)"));
  Serial.print(F("Screen fill              "));
  Serial.println(testFillScreen());
  delay(500);
  Serial.println(F("Done!"));
  */
  tft.fillScreen(BLACK);
  tft.setRotation(1);
  pinMode(touchPin, OUTPUT); // pin to control reading of touchscreen

  /* --- RGB LED pins --- */
  if (LEDenabled) // set pins for RGB LED & set everything low => black, but
                  // only if LEDenabled = true
  {
    pinMode(LEDgnd, OUTPUT);
    digitalWrite(LEDgnd, LOW);
    pinMode(LEDg, OUTPUT);
    digitalWrite(LEDg, LOW);
    pinMode(LEDr, OUTPUT);
    digitalWrite(LEDr, LOW);
    pinMode(LEDb, OUTPUT);
    digitalWrite(LEDb, LOW);
  }

  /* --- Write LCD fields to show boot info --- */
  Serial.println("Show EarthListener boot animation");
  Serial.println();
  showScreen(0);

  /* --- Check first boot & if true, set values to default settings --- */
  if (EEPROM.read(firstBoot_EEPROMaddr)) {
    // it's the first time the EarthListener has booted! Set default values
    EEPROM.write(AS3935_SPI_EEPROMaddr, false); // set AS3935 interface to I2C
    EEPROM.write(AS3935_outdoor_EEPROMaddr, false); // set AS3935 to indoor use
    EEPROM.write(globalSense_EEPROMaddr,
                 2); // set AS3935 sensitivity to 2 (medium)
    EEPROM.write(Buzzer_EEPROMaddr, true);   // set buzzer on
    EEPROM.write(MetricON_EEPROMaddr, true); // set values to metric
    EEPROM.write(firstBoot_EEPROMaddr,
                 false); // set firstboot on false, this will not be run again
  }

  // clear the screen before moving on with sensors
  // show the logo for 1 second before clearing
  delay(1000);
  /* --- CCS811 sensor feedback --- */
  ccs811_setup();

  /* --- AS3935 sensor feedback --- */
  Serial.println("***AS3935 sensor feedback***");
  Serial.print("Checking interface...");

  tft.setCursor(15, 135);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("AS3935 status: ");

  // read value for AS3935_SPI out of EEPROM memory
  AS3935_SPI = EEPROM.read(AS3935_SPI_EEPROMaddr);
  // Serial.print("AS3935_SPI = "); Serial.println(AS3935_SPI);
  if (AS3935_SPI) {
    // SPI interface
    Serial.println(" SPI");
    AS3935_SPI = true; // set in case it's not properly set

    SPI.begin(); // For SPI
    if (!lightningSPI.beginSPI(spiCS, 2000000)) {
      AS3935_bootOK = false;
    } else {
      // double check to be sure (read a value)
      int spikeValTest = lightningSPI.readSpikeRejection();
      if (spikeValTest != 0) {
        AS3935_bootOK = true;
      } else {
        AS3935_bootOK = false;
      }
    }

  } else {
    // IIC interface
    Serial.println(" IIC");
    AS3935_SPI = false; // set in case it's not properly set

    Serial.print("Scanning at address 0x");
    if (AS3935_ADD < 10) {
      Serial.print("0");
    }
    Serial.print(AS3935_ADD, HEX);
    Serial.println(", please wait...");

    if (!lightningIIC.begin()) { // Initialize the sensor.
      AS3935_bootOK = false;
    } else {
      // double check to be sure (read a value)
      int spikeValTest = lightningIIC.readSpikeRejection();
      if (spikeValTest != 0) {
        AS3935_bootOK = true;
      } else {
        AS3935_bootOK = false;
      }
    }
  }

  if (AS3935_bootOK) {
    Serial.println("Lightning sensor ready! Starting setup procedure...");
    tft.setTextColor(GREEN);
    tft.print("DETECTED");

    updateLightningSense(); // set the sensitivity of the sensor
    setupAS3935();          // run setup of AS3935 sensor

    // enable interrupt (hook IRQ pin to Arduino Uno/Mega interrupt to
    // AS3935_IRQPIN -> 18)
    pinMode(AS3935_IRQPIN,
            INPUT); // See http://arduino.cc/en/Tutorial/DigitalPins
    attachInterrupt(digitalPinToInterrupt(AS3935_IRQPIN), interruptFunction,
                    CHANGE);
    Serial.println("Setup AS3935 sensor done.");
    Serial.println();
  } else {
    Serial.println("Lightning sensor did not start up!");
    Serial.println();
    tft.setTextColor(RED);
    tft.print("ERROR");
    delay(1000);
  }

  /* --- BME280 sensor feedback --- */
  bme280_setup();

  /* --- set buzzer pin & read value from EEPROM --- */
  BuzzerEnabled = EEPROM.read(Buzzer_EEPROMaddr);
  // Serial.print("BuzzerEnabled = "); Serial.println(BuzzerEnabled);
  // BuzzerEnabled = 0;
  pinMode(BuzzerPin, OUTPUT);
  digitalWrite(BuzzerPin, LOW);

  /* --- SD card feedback --- */
  Serial.println("***SD card feedback***");
  Serial.print("Initializing...");

  tft.setCursor(15, 195);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("SD card: ");
  // see if the card is present and can be initialized:
  if (detectSD()) {
    tft.setTextColor(GREEN);
    tft.print("DETECTED");

  } else {
    tft.setTextColor(RED);
    tft.print("NOT FOUND");
  }
  Serial.println();

  // -- scan i2c for debug purposes - what devices do we have connected to the
  // board? 0x5B is the CCS811 chip 0x03 is the AS3935 sensor 0x77 is the BME280
  // 0x68 is the ds1307, if present
  // scani2c();

  /* --- RTC feedback --- */
  Serial.println("*** RTC feedback***");
  Serial.print("Initializing...");
  tft.setCursor(15, 225);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Clock status: ");
  // clock returns true if we have at least ONE sync source (RTC or NTP)
  if (setup_clock()) {
    Serial.println("Clock initialized!");
    tft.setTextColor(GREEN);
    tft.print("DETECTED");
  } else {
    Serial.println(" RTC failed or not present!");
    tft.setTextColor(RED);
    tft.print("NOT FOUND");
  }
  Serial.println();

  /* --- end of boot, wait 2 secs & set interrupt state, then show info screen
   * --- */
  delay(2000);
  AS3935IrqTriggered = 0; // set the interrupt state of the AS3935 sensor to 0
                          // (fix data input on boot)
  Serial.println("***End of setup, starting loop***");
  Serial.println();
  slideShowPlaying =
      INITIAL_SLIDESHOW_STATUS; // we always start without slide show
  showScreen(1);                // show info screen

  Serial.print("Checking number of active screens: ");
  Serial.print(NRSCREENS);
  Serial.print(" candidates, active = ");
}
