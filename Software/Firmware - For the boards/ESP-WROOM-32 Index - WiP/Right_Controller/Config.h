//==========================================================================================================
//************************************ USER CONFIGURABLE STUFF HERE*****************************************
//==========================================================================================================
#define SERIAL_DEBUG
#define CALPIN              5              //pin to start mag calibration at power on
#define APin                4
#define BPin                3
#define SysPin              5
#define FingerIndexPin      1
#define FingerMiddlePin     6
#define FingerRingPin       7
#define FingerPinkyPin      8
#define JoyXPin             A2
#define JoyYPin             A1
#define JoyClickPin         2
#define VbatPin             A6

#define BatLevelMax         968             //you need to find all of these values on your own
#define JoyXMin             212             //check on the utils folder for sketches and instructions
#define JoyXMax             741             //that help on getting these values
#define JoyYMin             261             //YOU NEED TO DO THIS FOR BOTH CONTROLLERS
#define JoyYMax             674             //if you use these values without changing them you MAY
#define JoyXDeadZoneMin     460             //get stick drift
#define JoyXDeadZoneMax     480
#define JoyYDeadZoneMin     460
#define JoyYDeadZoneMax     490
//==========================================================================================================
//**************************************** RF Data stuff ***************************************************
//==========================================================================================================
uint64_t Pipe = 0xF0F0F0F0E1LL; //right
//uint64_t Pipe = 0xF0F0F0F0D2LL; //left
