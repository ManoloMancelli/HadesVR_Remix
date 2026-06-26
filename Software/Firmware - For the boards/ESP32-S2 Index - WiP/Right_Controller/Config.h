//==========================================================================================================
//************************************ USER CONFIGURABLE STUFF HERE*****************************************
//==========================================================================================================
#define SERIAL_DEBUG

#define APin                40
#define BPin                39
#define SysPin              0
#define FingerIndexPin      99
#define FingerMiddlePin     99
#define FingerRingPin       99
#define FingerPinkyPin      99
#define JoyXPin             2
#define JoyYPin             1
#define JoyClickPin         38
#define VbatPin             99

#define BatLevelMax         968       
#define JoyXMin             4000     
#define JoyXMax             4000       
#define JoyYMin             4000       
#define JoyYMax             4000      
#define JoyXDeadZoneMin     460            
#define JoyXDeadZoneMax     480
#define JoyYDeadZoneMin     460
#define JoyYDeadZoneMax     490
//==========================================================================================================
//**************************************** RF Data stuff ***************************************************
//==========================================================================================================
uint64_t Pipe = 0xF0F0F0F0E1LL; //right
//uint64_t Pipe = 0xF0F0F0F0D2LL; //left
