/*
  Copyright 2023 HadesVR
  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
  to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
  and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
  TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include "Config.h"
#include <Wire.h>
#include <SPI.h>
#include "RF24.h"

//==========================================================================================================
//*****************************************Basic Config*****************************************************
//==========================================================================================================
RF24 radio(9, 10);  //NRF24L01 Pins
//==========================================================================================================

#define IB_AClick 0x0001
#define IB_ATouch 0x0002
#define IB_BClick 0x0004
#define IB_BTouch 0x0008
#define IB_SYSClick 0x0010
#define IB_ThumbStickClick 0x0020
#define IB_ThumbStickTouch 0x0080
struct ctrlData {
  int16_t qW;
  int16_t qX;
  int16_t qY;
  int16_t qZ;
  int16_t accX;
  int16_t accY;
  int16_t accZ;
  uint16_t BTN;
  uint8_t trigg;
  int8_t axisX;
  int8_t axisY;
  int8_t trackY;
  uint8_t vBAT;
  uint8_t fingerThumb;
  uint8_t fingerIndex;
  uint8_t fingerMiddle;
  uint8_t fingerRing;
  uint8_t fingerPinky;
  uint8_t gripForce;
  uint16_t Data;
};
ctrlData data;

int tracky;
int trackoutput;
int axisX;
int axisY;
bool joyTouch = false;

void setup() {
  Wire.begin();
  Wire.setClock(400000);  //400khz clock

  pinMode(APin, INPUT_PULLUP);
  pinMode(BPin, INPUT_PULLUP);
  pinMode(SysPin, INPUT_PULLUP);
  pinMode(JoyClickPin, INPUT_PULLUP);
  pinMode(FingerPinkyPin, INPUT_PULLUP);
  pinMode(FingerRingPin, INPUT_PULLUP);
  pinMode(FingerMiddlePin, INPUT_PULLUP);

#ifdef SERIAL_DEBUG
  Serial.begin(9600);
#endif

  radio.begin();
  radio.setPayloadSize(32);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_2MBPS);
  radio.openWritingPipe(Pipe);
  radio.startListening();
  radio.setAutoAck(false);

  if (!radio.isChipConnected()) {
    Serial.println("NRF24L01 Module not detected!");
    while (true)
      ;
  } else {
    Serial.println("NRF24L01 Module up and running!");
  }

  //initialize controller data.
  data.qW = 1;
  data.BTN = 0;
  data.axisX = 0;
  data.axisY = 0;
  data.vBAT = 0;
  data.fingerThumb = 0;
  data.fingerIndex = 0;
  data.fingerMiddle = 0;
  data.fingerRing = 0;
  data.fingerPinky = 0;
  data.Data = 0x4B3;
}

void loop() {

  joyTouch = false;
  int btn = 0;
  axisX = analogRead(JoyXPin);
  axisY = analogRead(JoyYPin);

  if (axisX > JoyXDeadZoneMax || axisX < JoyXDeadZoneMin) {
    if (axisX > JoyXMax) {
      axisX = JoyXMax;
    }
    if (axisX < JoyXMin) {
      axisX = JoyXMin;
    }
    data.axisX = -map(axisX, JoyXMin, JoyXMax, -127, 127);
    btn |= IB_ThumbStickTouch;
    joyTouch = true;
  } else {
    data.axisX = 0;
  }

  if (axisY > JoyYDeadZoneMax || axisY < JoyYDeadZoneMin) {
    if (axisY > JoyYMax) {
      axisY = JoyYMax;
    }
    if (axisY < JoyYMin) {
      axisY = JoyYMin;
    }
    data.axisY = map(axisY, JoyYMin, JoyYMax, 127, -127);
    btn |= IB_ThumbStickTouch;
    joyTouch = true;
  } else {
    data.axisY = 0;
  }

  if (!digitalRead(APin)) {
    btn |= IB_AClick;
    btn |= IB_ATouch;
  }
  if (!digitalRead(BPin)) {
    btn |= IB_BClick;
    btn |= IB_BTouch;
  }
  if (!digitalRead(SysPin)) {
    btn |= IB_SYSClick;
  }
  if (!digitalRead(JoyClickPin)) {
    btn |= IB_ThumbStickClick;
  }
    if (digitalRead(FingerIndexPin)) {
      data.fingerIndex = 0;
    }
    else {
      data.fingerIndex = 255;
    }
  data.gripForce = 0;
  if (digitalRead(FingerMiddlePin)) {
    data.fingerMiddle = 0;
    data.gripForce += 128;
  } else {
    data.fingerMiddle = 255;
  }
  if (digitalRead(FingerRingPin)) {
    data.fingerRing = 0;
    data.gripForce += 64;
  } else {
    data.fingerRing = 255;
  }
  if (digitalRead(FingerPinkyPin)) {
    data.fingerPinky = 0;
    data.gripForce += 63;
  } else {
    data.fingerPinky = 255;
  }

  data.BTN = btn;
  data.vBAT = (map(analogRead(VbatPin), 787, BatLevelMax, 0, 255));

  radio.stopListening();
  radio.write(&data, sizeof(ctrlData));
  radio.startListening();
}