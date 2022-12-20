#include "model/EarthListenerController.h"

extern TFTHelper *myScreen;

extern Gas *myGas;
extern Lightning *myLightning;
extern Environment *myEnv;
extern RealTimeClock *myRTC;

extern GasView *myGasView;
extern LightningView *myLightningView;
extern EnvironmentView *myEnvView;

extern EarthListenerController *elc;


extern unsigned long touchedTime;
extern bool touchedMe;
extern unsigned long allSeconds;
extern unsigned long runDays;
extern unsigned long secsRemaining;
extern unsigned long runHours;
extern unsigned long runMinutes;
extern unsigned long runSeconds;

extern unsigned long lastSecond;

extern int secondCounter;

// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// For the one we're using, its 320 ohms across the X plate
//inline TouchScreen ts = TouchScreen(XP, YP, XM, YM, 320);


/* --- Speaker --- */
//pin setup for speaker
extern boolean BuzzerEnabled;      //1= Buzzer on, 0= Buzzer off => can be modified via TFT interface


/* --- RGB LED --- */
extern boolean LEDenabled;     //1= LED on, 0= LED off. Will also declare pins for output if turned on.


/* --- menus --- */
extern int currentScreenNr;        //start with bootscreen
extern int previousScreenNr;
extern boolean slideShowPlaying;        //is the slide show playing? yes=1, no=0
extern int slideshowTimer;         //time (in seconds) to show each slide
extern unsigned long timeStartSlide;     //time when slide was first shown;


/* --- metric / imperial switch --- */
extern boolean MetricON;  //boolean to check if values of temperature and lightning distance are set in Celsius/km or Fahrenheit/miles => can be modified via TFT interface


void getTimeSinceBoot();



//#include <stdint.h>
//#include "src\ds1302\DS1302.h"
//#include "src\SparkFun_CCS811\src\SparkFunCCS811.h"
//
//
///* fun.c */
//void Print_Level(int data1);
//void printSensorError(void);
//unsigned long testFillScreen(void);
//void updateCCS811vars(float TEMP, float HUMIDITY);
//void interruptFunction(void);
//void controlLED(char COLOR);
//void getTimeSinceBoot(void);
//int returnMinutes(unsigned long Millis);
//char* dayAsString(const Time::Day day);
//char* returnTime (Time currentTime);
////bool touchedMe(void);
//void showScreen(int screenNr);
//void oldlightningscreen(void);
//void setupAS3935(void);
//void updateLightningSense(void);
//void printValues(void);
//void printMenuBtn(void);
//void printLastDetectionTimeAS3935(void);
//void printDriverError( CCS811Core::status errorCode );
//void inputControl(void);
//void checkBaseTouch(void);
//void toggleSlideShow(void);
//void toggleBuzzer(void);
//void toggleMetric(void);
//void toggleIndoor(void);
//void toggleInterface(void);
//void scani2c(void);
//void showbgd(int x, int y, const uint8_t *bmp, int w, int h, uint16_t color,
//             uint16_t bg);
//void setOutput(char COLOR);
//void lightningscreen();
//void controlLogo(uint16_t logocolor);
