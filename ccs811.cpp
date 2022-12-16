
// for unknown reasons the original code for CCS811 did not work well. I got really high readings, like 2500-4000 ppm.
// using the sparkfun example sketch worked. Hence, these functions are derived from that sketch to be able to get some
// insight in what might be happening - the original code is less readable than I prefer

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_CCS811.h>
#include "config.h"
#include "screens.h"

#include "src/MCUFRIEND_kbv/MCUFRIEND_kbv.h"                  // TFT library by David Prentice
extern MCUFRIEND_kbv tft;


extern Adafruit_CCS811 myCCS811;

extern uint16_t CO2;
extern uint16_t TVOC;

extern CO2Screen co2screen;
extern TVOCScreen tvocscreen;

bool haveccs811=false;

//printDriverError decodes the CCS811Core::status type and prints the
//type of error to the serial terminal.
//
//Save the return value of any function of type CCS811Core::status, then pass
//to this function to see what the output was.

void drawCCS811status(bool error )
{
  tft.setCursor(15, 105);
  tft.setTextColor(WHITE); 
  tft.setTextSize(2);

  tft.print("CCS811 status: ");

  if(!error) {
      Serial.println("CCS811 - GENERIC_ERROR - (Likely not present)"); 
      tft.setTextColor(RED); 
      tft.print("ERROR");
      co2screen.setEnabled(false);
      tvocscreen.setEnabled(false);
  }  else { 
      Serial.println("CCS811 - SUCCESS");
      tft.setTextColor(GREEN); 
      tft.print("DETECTED");
      co2screen.setEnabled(true);
      tvocscreen.setEnabled(true);
  }
   /* case CCS811Core::CCS811_Stat_ID_ERROR:
      Serial.print("ID_ERROR");
      tft.setTextColor(RED); 
      tft.print("ID_ERROR");
      break;
    case CCS811Core::CCS811_Stat_I2C_ERROR:
      Serial.print("I2C_ERROR");
      tft.setTextColor(RED); 
      tft.print("I2C_ERROR");
      break;
    case CCS811Core::CCS811_Stat_INTERNAL_ERROR:
      Serial.print("INTERNAL_ERROR");
      tft.setTextColor(RED); 
      tft.print("INTERNAL_ERROR");
      break;
    case CCS811Core::CCS811_Stat_GENERIC_ERROR:
      Serial.print("GENERIC_ERROR");
      tft.setTextColor(RED); 
      tft.print("GENERIC_ERROR");
      break;
    default:
      Serial.print("Unspecified error.");
      tft.setTextColor(RED); 
      tft.print("Unspecified error.");
  }
  return false;*/
}


void ccs811_setup() {
  bool status;
  Wire.begin(); //Inialize I2C Hardware

  status = myCCS811.begin(CCS811_ADDR);
   

  drawCCS811status(status);
  haveccs811=status;

  if(!status)
  return;
  
   while(!myCCS811.available())
    Serial.println("ccs811...");
}

// read from ccs811 and update the two lovely globals
void ccs811_loop()
{
  if(!haveccs811) {
      CO2=0;
      TVOC=0;      
    return;
  }
  //Check to see if data is ready with .dataAvailable()
  if (myCCS811.available())
  {
    //If so, have the sensor read and calculate the results.
    //Get them later
    if(!(myCCS811.readData())) {

    Serial.print("CO2[");
    //Returns calculated CO2 reading
    CO2 = myCCS811.geteCO2();
    Serial.print(CO2);
    Serial.print("] tVOC[");
    //Returns calculated TVOC reading
    TVOC = myCCS811.getTVOC();
    Serial.print(TVOC);
    Serial.print("] millis[");
    //Display the time since program start
    Serial.print(millis());
    Serial.print("]");
    Serial.println();
    }
  }
}


#if 0
//printSensorError gets, clears, then prints the errors
//saved within the error register.
void printSensorError()
{
  Serial.println("Error with CCS811 sensor!");
  uint8_t error = myCCS811.getErrorRegister();

  tft.setCursor(15, 105);
  tft.setTextColor(RED);  tft.setTextSize(2);
  tft.println("Error with CCS811 sensor!");

  if ( error == 0xFF ) //comm error
  {
    Serial.println("Failed to get ERROR_ID register.");
    tft.println("Failed to get ERROR_ID register!:");
  }
  else
  {
    Serial.print("Error: ");
    if (error & 1 << 5) Serial.print("HeaterSupply");     tft.println(" Error: HeaterSupply");
    if (error & 1 << 4) Serial.print("HeaterFault");      tft.println(" Error: HeaterFault");
    if (error & 1 << 3) Serial.print("MaxResistance");    tft.println(" Error: MaxResistance");
    if (error & 1 << 2) Serial.print("MeasModeInvalid");  tft.println(" Error: MeasModeInvalid");
    if (error & 1 << 1) Serial.print("ReadRegInvalid");   tft.println(" Error: ReadRegInvalid");
    if (error & 1 << 0) Serial.print("MsgInvalid");       tft.println(" Error: MsgInvalid");
    Serial.println();
  }
}

#endif
