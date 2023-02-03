#pragma once
//
//    FILE: AD5245.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.2.0
// PURPOSE: Arduino library for I2C digital potentiometer AD5245.
//    DATE: 2022-07-31
//     URL: https://github.com/RobTillaart/AD5245


// experimental - to be tested - use at own risk

#include "Arduino.h"
#include "Wire.h"


#define AD5245_LIB_VERSION   (F("0.2.0"))


#define AD5245_OK             0
#define AD5245_ERROR          100

#define AD5245_MIDPOINT       128


class AD5245
{
public:
  explicit AD5245(const uint8_t address, TwoWire *wire = &Wire);

#if defined (ESP8266) || defined(ESP32)
  bool    begin(uint8_t sda, uint8_t scl);
#endif
  bool    begin();
  bool    isConnected();

  uint8_t reset();

  uint8_t read();        //  read from cache (fast!)
  uint8_t readDevice();  //  read from device
  uint8_t write(const uint8_t value);


  //  experimental - to be tested - use at own risk
  uint8_t shutDown();


private:
  uint8_t send(const uint8_t cmd, const uint8_t value);

  uint8_t _address;
  uint8_t _lastValue;

  TwoWire*  _wire;
};


//  -- END OF FILE --

