//  **********************************************************************//
//  author: Joram de Poel                                                 //
//  date:   8-7-2016                                                      //
//  version: 1.3                                                          //
//  email: joramdepoel@gmail.com                                          //
//  **********************************************************************//
//
//  This code is free to use, edit and distrubate as long as you use it for non profit projects
//
//  this code is writen to use analog joysticks in the easiest way possible and with the most options
//  this code deals with ofsets, limited range, inverted axis and many other problems with joysticks
//  this code uses the map_float function, if you didnt already include this in your arduino core, 
//  just uncomment the function at the bottom

//*****************define your pins here***********************************************//
#define joystick_X 2    //joystick  X-as
#define joystick_Y 1    //joystick  Y-as
#define button_2 38       // button on d2


//****************define the min, max and center you want for your joystick here*******//
long range_X_min = 1000;           //lowest X value
long range_X_max = 10000;          //highest X value
long range_X_center = 0;           //X center calue
unsigned long deadZone_X = 1;      //deadzone X, return center value for center +- deadzone(in steps of 1/1024)

float range_Y_min = 0;             //lowest Y value
float range_Y_max = 1023;          //highest Y value
float range_Y_center = 512;        //Y center value
unsigned long deadZone_Y = 1;      //deadzone Y, return center value for center +- deadzone(in steps of 1/1024)


//***************calibration variables************************************************//
int val_X, val_Y;

unsigned long X_CENTER, X_MIN, X_MAX;
unsigned long Y_CENTER, Y_MIN, Y_MAX;

unsigned long cal_X;
unsigned long cal_Y;


//************setup******************************************************************//

void setup() {
  Serial.begin(9600);
  pinMode(joystick_X, INPUT);
  pinMode(joystick_Y, INPUT);
  pinMode(button_2, INPUT_PULLUP);    //we pull this pin high to avoid a floating pin
  calibrate();
}

long joy_X(long X) {
  X += (X_CENTER-512);   //should always be 512
  if (X <= 512) {
    X = mapfloat(X, X_MIN, X_CENTER, range_X_min, range_X_center);   //min,center to range min, range center
    return X;
  }
  else if (X > 512) {
    X = mapfloat(X, 512, 1024 + X_CENTER, range_X_center, range_X_max);
    return X;
  }
}

long joy_Y(long Y) {
  Y += (Y_CENTER-512);
  if (Y <= range_Y_center) {
    Y = mapfloat(Y, Y_CENTER, 512, 0, 512);
    return Y;
  }
  else if (Y > range_Y_center) {
    Y = mapfloat(Y, 512, 1024 + Y_CENTER, 512, 1024);
    return Y;
  }
}

void loop() {
  val_X = analogRead(joystick_X);
  Serial.print(joy_X(val_X)); Serial.print(" : ");
  delay(50);
  val_Y = analogRead(joystick_Y);
  Serial.println(joy_Y(val_Y));
  delay(50);
  if (digitalRead(button_2) == LOW) {
    calibrate();    //you can call any function you want here, this is just to show the possibilities
  }
}

void set_range_X(float min, float max, float center) {
  range_X_min = min;
  range_X_max = max;
  range_X_center = center;
}

void set_range_Y(float min, float max, float center) {
  range_Y_min = min;
  range_Y_max = max;
  range_Y_center = center;
}

void calibrate() {
  Serial.println("\n---calibrating joystick---\n");
  Serial.println("place the joystick in the center position");
  cal_X = 0;
  cal_Y = 0;
  delay(2500);
  Serial.print("calibrating center");
  for (int i = 0; i < 100; i++) {
    Serial.print(".");
    cal_X += analogRead(joystick_X);
    delay(5);
    cal_Y += analogRead(joystick_Y);
    delay(5);
  }
  X_CENTER = (cal_X/100);
  Y_CENTER = (cal_Y/100);
  Serial.print("\nCorrection X: ");Serial.print(X_CENTER);
  Serial.print("\nCorrection Y: ");Serial.println(Y_CENTER);
  
  Serial.println("\nplace the joystick in the bottom-left corner");
  X_MIN = 0;    //reset the values
  Y_MIN = 0;
  delay(2500);
  Serial.print("calibrating position");
   for (int i = 0; i < 100; i++) {    //take 100 readings
    Serial.print(".");
    X_MIN += analogRead(joystick_X);
    delay(5);
    Y_MIN += analogRead(joystick_Y);
    delay(5);
  }
  X_MIN /= 100;
  Y_MIN /= 100;
  Serial.println();
  Serial.print("X: "); Serial.println(X_MIN);
  Serial.print("Y: "); Serial.println(Y_MIN);

Serial.println("\nplace the joystick in the top-right corner");
  X_MAX = 0;    //reset the values
  Y_MAX = 0;
  delay(2500);
  Serial.print("calibrating position");
   for (int i = 0; i < 100; i++) {    //take 100 readings
    Serial.print(".");
    X_MAX += analogRead(joystick_X);
    delay(5);
    Y_MAX += analogRead(joystick_Y);
    delay(5);
  }
  X_MAX /=  100;
  Y_MAX /=  100;
  Serial.println();
  Serial.print("X: "); Serial.println(X_MAX);
  Serial.print("Y: "); Serial.println(Y_MAX);

  if(X_MAX < X_MIN){
    unsigned long val = X_MAX;
    X_MAX = X_MIN;
    X_MIN = val;
  }
  if(Y_MAX < Y_MIN){
    unsigned long val = Y_MAX;
    Y_MAX = Y_MIN;
    Y_MIN = val;
  }

  Serial.print("\nrange X: ");Serial.print(X_MIN);Serial.print(" - ");Serial.println(X_MAX);
  Serial.print("range X: ");Serial.print(Y_MIN);Serial.print(" - ");Serial.println(Y_MAX);
    
  Serial.println("\n---calibration done---\n");
}


/*//some people added this function to the Arduino core, comment this if it's already in the Arduino core
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
*/
