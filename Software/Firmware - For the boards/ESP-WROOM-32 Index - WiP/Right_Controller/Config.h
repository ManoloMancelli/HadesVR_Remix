//==========================================================================================================
//************************************ USER CONFIGURABLE STUFF HERE*****************************************
//==========================================================================================================
#define SERIAL_DEBUG

#define APin                15
#define BPin                33
#define SysPin              13
#define FingerIndexPin      99
#define FingerMiddlePin     99
#define FingerRingPin       99
#define FingerPinkyPin      99
#define JoyXPin             99
#define JoyYPin             99
#define JoyClickPin         12
#define VbatPin             99

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
