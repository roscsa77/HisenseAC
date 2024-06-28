/*
todo:
		* AC_ON_Sequence != 0 közben kommunikáció megszakad...
*/

#include "esphome.h"
#include <iostream>
#include <sstream>
#include <string>
#include <WiFi.h>

class MyCustomClimate : public Component, public Climate, public UARTDevice {
 public:
  MyCustomClimate(UARTComponent *parent) : UARTDevice(parent) {}
//  uint8_t AC_FAN_OFF[44]			= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//  uint8_t AC_ECO_ON[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//  uint8_t AC_ECO_ON[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x0B, 0x01, 0x00, 0x33, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//  uint8_t AC_ECO_OFF[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x0B, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x34, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//  uint8_t AC_BOOST_ON[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x01, 0x00, 0x41, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//  uint8_t AC_BOOST_ON[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x01, 0x01, 0x00, 0x41, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
//  uint8_t AC_BOOST_OFF[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  
  uint8_t AC_ON[44]  				= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_OFF[44]				= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_EXTRA_LOW_FAN[44] 		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x0B, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_LOW_FAN[44]			= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x0D, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_NORMAL_FAN[44] 		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_HIGH_FAN[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x11, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_EXTRA_HIGH_FAN[45]   	= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01};
//uint8_t AC_EXTRA_HIGH_FAN[44]   	= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x13, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_AUTO_FAN[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_SILENT_ON[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_SILENT_OFF[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_ECO_ON[44]   			= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_ECO_OFF[44]   			= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_SWING_ON[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_SWING_OFF[44]  		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_BOOST_ON[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_BOOST_OFF[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_FAN_MODE[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x13, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x14, 0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_HEAT_MODE[44]  		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x01, 0x01, 0x30, 0x2F, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x14, 0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_COOL_MODE[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x01, 0x01, 0x50, 0x35, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x14, 0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_DRY_MODE[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x0B, 0x01, 0x70, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x14, 0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_AUTO_MODE[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x01, 0x01, 0x90, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x14, 0x05, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_SET_TEMP[44]   		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_DISPLAY_OFF[44] 		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_DISPLAY_ON[44] 		= {0x00, 0x40, 0x29, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x65, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_GET_STATUS_1E[22] 		= {0x00, 0x40, 0x13, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  uint8_t AC_GET_STATUS_66[15] 		= {0x00, 0x40, 0x0C, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x66, 0x00, 0x00, 0x00};
  uint8_t AC_START_COMM1[14] 		= {0x00, 0x40, 0x0B, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x66, 0x40, 0x00};
  uint8_t AC_START_COMM2[22] 		= {0x00, 0x40, 0x13, 0x00, 0x00, 0x01, 0x01, 0xFE, 0x01, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x80, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
  /* 0x65 bytes:
  14: fan mode
  16: HVAC mode
  17: Temperature
  
  */
  
  uint8_t inBuf[128] = {0};
  double statusCycleTime = 0;
  double sentTime = 0;
  uint8_t dimmer = 0;
  uint8_t outBuf[128];
  
  uint8_t outLen=0;
  uint8_t inMsg[128];
  uint8_t inMsgCnt = 0;
  uint8_t prevByte = 0;
  uint8_t currentByte = 0;
  uint8_t msgIsComoing = 1;
  uint8_t reqSend = 0;

  uint8_t rq_target_temperature = 0;
  uint8_t rq_power_mode = 0; 	// 0 -> Off, 8 -> On
  uint8_t rq_mode = 0; 		 	// 00->fan, 10->heat, 20->cool, 30->dry, 60->auto
  uint8_t rq_fan = 0; 		 	// 00->Off, 1->Auto, 0xA->Super low, 0xC->Low, 0xE->Normal, 0x10->High, 0x12->Super high
  uint8_t rq_swing = 0; 	 	// 2->On, 0->On
  uint8_t rq_preset = 0; 	 	// 0->Off, 1->Comfort, 2->Eco, 3->Boost
  uint8_t last_rq_preset = 0; 	 	// 0->Off, 1->Comfort, 2->Eco, 3->Boost
  uint8_t saved_Temp = 0;
  uint8_t saved_Fan_Mode = 0;
  

  uint8_t act_power_mode = 0; 	// 0 -> Off, 8 -> On
  uint8_t act_preset = 0; 	 	// 0->Off, 1->Comfort, 2->Eco, 3->Boost
  uint8_t act_fan_mode = 0;
  uint8_t act_hvac_mode = 0;	//
  uint8_t commProcess = 0;		// 0->None, 0x65 (Command), 0x66 (Status), 0x1E (Acknowledge)
  
  uint8_t tempChangeReq = 0;
  uint8_t powerModeChange = 0;
  uint8_t modeChangeReq = 0;
  uint8_t fanChangeReq = 0;
  uint8_t swingChangeReq = 0;
  uint8_t presetChangeReq = 0;
  
  uint8_t AC_ON_Sequence = 0;
  uint8_t load_AC_State_Sequence = 0;
  
  uint8_t receivedCommandCode = 0;
    
  uint8_t commandProcess = 0;

  double pauseEnd = 0;
  uint8_t pause = 0;
  uint8_t lastMessage = 0;
  
  double startTime = 0;
  uint8_t startSequence = 0;

  void setup() override {
    // This will be called by App.setup()
	pinMode(26, OUTPUT);
	statusCycleTime = millis() + 5000;
	startTime = millis() + 5000;
  }
   
  bool checkCRC(uint8_t len, uint8_t msg[]) {
	uint16_t crc = 0;
    for (int i = 2; i < len - 3; i++) 
	{
		crc += msg[i];
	}
	uint8_t crcH = (char)(crc>>8);
	uint8_t crcL = (char) (crc & 0x00ff);
	if ((crcH == msg[len-3]) & (crcL == msg[len-2])) {
      return true;
	} 
	else
	{
	  ESP_LOGE("checkCRC", "CRC Error within incoming message. Received CRC: %d %d | Calculated CRC: %d %d", msg[len-3], msg[len-2], crcH, crcL);
      return false;
	}
  }
  
  void processMsg(uint8_t inLen, uint8_t inBuf[]) {

//    ESP_LOGD("processMsg", "Message received");
	
	if (inLen < 5) {
		ESP_LOGE("processMSG", "Number of received bytes < 5. Buffer size: %d", inLen);
		commProcess = 0;
		receivedCommandCode = 0x1E;
		return;
	}
	

    uint8_t len = inBuf[4];

	if (inBuf[2] != 0x01) { //Has response come?
		return;
	}

    //uint8_t len = inBuf[4];
	if (inLen < len + 6) {
		ESP_LOGE("processMSG", "Number of received bytes < len + 6. Buffer size: %d | len + 6: %d", inLen, len + 6);
		commProcess = 0;
		receivedCommandCode = 0x1E;
		return;
	}

	if ((inBuf[len+7] != 0xF4) | (inBuf[len+8] != 0xFB))
	{
		ESP_LOGE("processMSG", "Length error within incoming message. Length in message: %d | Received bytes: %d", len, inLen);
		commProcess = 0;
		receivedCommandCode = 0x1E;
		return;
	}
	
	if (checkCRC(inLen, inBuf) == false) 
	{
		ESP_LOGE("processMSG", "CRC error!");
		commProcess = 0;
		receivedCommandCode = 0x1E;
		return;
	}

	if ((inBuf[13] != 0x65) & (inBuf[13] != 0x66) & (inBuf[13] != 0x1E))
	{
		ESP_LOGE("processMSG", "Nem megfelelő (%d) response code", inBuf[13]);
		commProcess = 0;
		receivedCommandCode = 0x1E;
		return;
	}
	
	if ((inBuf[13] == 0x65) & (len < 73)) 
	{
		ESP_LOGE("processMSG", "Response Code is: %d, but received length < 73. Len: %d", inBuf[13], len);
		commProcess = 0;
		receivedCommandCode = 0x1E;
		return;
	}

	if ((inBuf[13] == 0x66) & (len != 73) & (len != 28)) 
	{
		ESP_LOGE("processMSG", "Response Code is: %d, but received length < 73. Len: %d", inBuf[13], len);
		commProcess = 0;
		receivedCommandCode = 0x1E;
		return;
	}

	if ((inBuf[13] == 0x66) & (len == 28)) 
	{
//		ESP_LOGW("processMSG", "Start com response received");
		receivedCommandCode = 0x66;
		commProcess = 0;
		return;
	}

	if (inBuf[13] == 0x1E) //Még nincs feldolgozva
	{
		receivedCommandCode = 0x1E;
		return;
	}

	if (inBuf[13] == 0x65) 
	{
		receivedCommandCode = 0x65;
		return;
	}

	auto traits = this->get_traits();
	std::set<std::string> fanModes = traits.get_supported_custom_fan_modes();
	std::string fanModeSL; 
	std::string fanModeSH; 
	std::string fanModeL; 
	std::string fanModeH; 
	std::string fanModeN; 
	std::string fanModeA; 
	std::string fanModeQ; 
	std::string fanModeO; 
	for (std::set<std::string>::iterator it=fanModes.begin(); it!=fanModes.end(); ++it) {
	  std::string temp = *it;
	  if (temp.compare("1 Super Low")==0) {
		  fanModeSL = *it;
	  }
	  if (temp.compare("5 Super High")==0) {
		  fanModeSH = *it;
	  }
	  if (temp.compare("2 Low")==0) {
		  fanModeL = *it;
	  }
	  if (temp.compare("4 High")==0) {
		  fanModeH = *it;
	  }
	  if (temp.compare("3 Normal")==0) {
		  fanModeN = *it;
	  }
	  if (temp.compare("6 Auto")==0) {
		  fanModeA = *it;
	  }
	  if (temp.compare("7 Quiet")==0) {
		  fanModeQ = *it;
	  }
	  if (temp.compare("8 OFF")==0) {
		  fanModeO = *it;
	  }
	}

	this->current_temperature = inBuf[20];

	this->target_temperature = inBuf[19];
	
	if ((inBuf[18]&0x08) != 0x08) {
		act_power_mode = 0;
		this->mode = CLIMATE_MODE_OFF;
	}
	else
	{
		act_power_mode = 1;
		act_hvac_mode = inBuf[18]&0xF0;
		switch(inBuf[18]&0xF0) {
		  case 0x00: this->mode = CLIMATE_MODE_FAN_ONLY;
			break;
		  case 0x10: this->mode = CLIMATE_MODE_HEAT;
			break;
		  case 0x20: this->mode = CLIMATE_MODE_COOL;
			break;
		  case 0x30: this->mode = CLIMATE_MODE_DRY;
			break;
		  case 0x60: this->mode = CLIMATE_MODE_AUTO;
			break;
		}
	}

	if ((inBuf[16]==0) or (inBuf[16]==1) or (inBuf[16]==0x02) or (inBuf[16]==0x0A) or (inBuf[16]==0x0C) or (inBuf[16]==0x0E) or (inBuf[16]==0x10) or (inBuf[16]==0x12)) 
	{
		switch(inBuf[16]) {
		  case 0x00: this->custom_fan_mode = fanModeO;
			break;
		  case 0x01: this->custom_fan_mode = fanModeA;
			break;
		  case 0x02: this->custom_fan_mode = fanModeQ;
			break; 
		  case 0x0A: this->custom_fan_mode = fanModeSL;
			break;
		  case 0x0C: this->custom_fan_mode = fanModeL;
			break;
		  case 0x0E: this->custom_fan_mode = fanModeN;
			break;
		  case 0x10: this->custom_fan_mode = fanModeH;
			break;
		  case 0x12: this->custom_fan_mode = fanModeSH;
			break;
		}
		act_fan_mode = inBuf[16];
	}
	
	if((inBuf[18]&0x02) == 2) {
		this->swing_mode = CLIMATE_SWING_VERTICAL;
	}
	else {
		this->swing_mode = CLIMATE_SWING_OFF;
	}

	act_preset = 0;
	if ((inBuf[36]&0x4) == 4) {
		act_preset = 1;
		this->preset = CLIMATE_PRESET_COMFORT;
	} 

	if ((inBuf[35]&0x4) == 4) {
		act_preset = 2;
		this->preset = CLIMATE_PRESET_ECO;
	} 

	if ((inBuf[35]&0x2) == 2) {
		act_preset = 3;
		this->preset = CLIMATE_PRESET_BOOST;
	}

	if (act_preset == 0) {
		this->preset = CLIMATE_PRESET_NONE;
	}

	if ((inBuf[37]&0x80) == 0x80) {
		dimmer = 1;
	} else {
		dimmer = 0;
	}

	this->publish_state();

	if ((inBuf[13] == 0x66)) {
		receivedCommandCode = 0x66;
	}

	commProcess = 0;

  }
  
  void sendMessage(uint8_t len, uint8_t inBuf[]) {
	  
	  uint16_t crc = 0;
	  commProcess = inBuf[11];
//	  ESP_LOGW("sendMessage", "Message sending...: %d", commProcess);	  
	  for(int i=0; i<len; i++) {
		  crc += inBuf[i];
	  }	  
	  digitalWrite(26, HIGH);
	  delay(100);
	  	  
	  write(0xF4);
	  write(0xF5);
	  for(int j=0; j<len; j++) {
		write(inBuf[j]);
	  }
	  uint8_t crcH = (char)(crc>>8);
	  uint8_t crcL = (char) (crc & 0x00ff);
	  write(crcH);
	  write(crcL);
	  if (crcL == 244) {
		write(crcL);
	  }
	  write(0xF4);
	  write(0xFB);
	  
	  delay(150);
	  digitalWrite(26, LOW);
	  sentTime = millis();

	  
	  if (inBuf[11]==0x65)
	  {
		  commandProcess = 1;
	  }
	  if (inBuf[11]==0x66) 
	  {
		commandProcess = 0;
	  }

  }
  
  void createMessage(uint8_t len, uint8_t inBuf[]) {
	  if (inBuf[11]==0x65) {
		reqSend = 1; //Command
//		ESP_LOGD("createMessage", "Create 0x65");
	  } else if (inBuf[11]==0x66) {
		reqSend = 2; //STATUS 2
//		ESP_LOGD("createMessage", "Create 0x66");
	  } else if (inBuf[11]==0x1E) {
//		ESP_LOGD("createMessage", "Create 0x1E");
		reqSend = 3; //STATUS 1
	  }
	  outLen = len;
	  memcpy(outBuf, inBuf, len);
	  return;
  }
  
      
  void control(const ClimateCall &call) override {
    if (call.get_mode().has_value()) {
      // User requested mode change
      ClimateMode mode = *call.get_mode();
      if ((mode != CLIMATE_MODE_OFF) & (act_power_mode == 0)) { //bekapcsolás
		  AC_ON_Sequence = 1;
		  ESP_LOGD("control", "AC ON initiated");		  
	  }
	  if ((mode == CLIMATE_MODE_OFF) & (act_power_mode == 1)) { //Kikapcsolás
		  ESP_LOGD("control", "AC OFF initiated");		  
		  powerModeChange = 1;
		  rq_power_mode = 0;
	  }
      // Send mode to hardware
      if (mode == CLIMATE_MODE_HEAT) {
			modeChangeReq = 1;
			rq_mode = 0x10;
      }
      else if (mode == CLIMATE_MODE_COOL) {
			modeChangeReq = 1;
			rq_mode = 0x20;
      }
      else if (mode == CLIMATE_MODE_AUTO) {
			modeChangeReq = 1;
			rq_mode = 0x60;
      }
      else if (mode == CLIMATE_MODE_DRY) {
			modeChangeReq = 1;
			rq_mode = 0x30;
      }
      else if (mode == CLIMATE_MODE_FAN_ONLY) {
			modeChangeReq = 1;
			rq_mode = 0;
      }
    }
	
	if (call.get_custom_fan_mode().has_value()) {
	  fanChangeReq = 1;

	  auto traits = this->get_traits();
	  std::set<std::string> fanModes = traits.get_supported_custom_fan_modes();
	  std::string fanMode = *call.get_custom_fan_mode();
	  int cnt = 0;

		std::string fanModeSL; 
		std::string fanModeSH; 
		std::string fanModeL; 
		std::string fanModeH; 
		std::string fanModeN; 
		std::string fanModeA; 
		std::string fanModeQ; 
		std::string fanModeO; 
		std::string fanModeON; 
		for (std::set<std::string>::iterator it=fanModes.begin(); it!=fanModes.end(); ++it) {
		  std::string temp = *it;
		  if (temp.compare("1 Super Low")==0) {
			  fanModeSL = *it;
		  }
		  if (temp.compare("5 Super High")==0) {
			  fanModeSH = *it;
		  }
		  if (temp.compare("2 Low")==0) {
			  fanModeL = *it;
		  }
		  if (temp.compare("4 High")==0) {
			  fanModeH = *it;
		  }
		  if (temp.compare("3 Normal")==0) {
			  fanModeN = *it;
		  }
		  if (temp.compare("6 Auto")==0) {
			  fanModeA = *it;
		  }
		  if (temp.compare("7 Quiet")==0) {
			  fanModeQ = *it;
		  }
		  if (temp.compare("8 OFF")==0) {
			  fanModeO = *it;
		  }
		  if (temp.compare("0 AC ON")==0) {
			  fanModeON = *it;
		  }
		}
		
		  if (fanMode.compare("5 Super High") == 0) {
			rq_fan = 0x12;
		  }
		  if (fanMode.compare("1 Super Low") == 0) {
			rq_fan = 0x0A;
		  }
		  if (fanMode.compare("6 Auto") == 0) {
			rq_fan = 0x1;
		  }
		  if (fanMode.compare("3 Normal") == 0) {
			rq_fan = 0x0E;
		  }
		  if (fanMode.compare("4 High") == 0) {
			rq_fan = 0x10;
		  }
		  if (fanMode.compare("2 Low") == 0) {
			rq_fan = 0x0C;
		  }
		  if (fanMode.compare("8 OFF") == 0) {
			rq_fan = 0x0;
		  }
		  if (fanMode.compare("0 AC ON") == 0) {
			powerModeChange = 1;
			rq_power_mode = 1;
			ESP_LOGD("control", "AC ON initiated by custom FAN mode");		  
		  }	  
	}

	if (call.get_preset().has_value()) {
	  ClimatePreset preset = *call.get_preset();
	  presetChangeReq = 1;
		
      if (preset == CLIMATE_PRESET_NONE) {
		  rq_preset = 0;
      } 
      else if (preset == CLIMATE_PRESET_BOOST) {
		  rq_preset = 3;
	  }
      else if (preset == CLIMATE_PRESET_ECO) {
		  rq_preset = 2;
	  }
      else if (preset == CLIMATE_PRESET_COMFORT) {
		  rq_preset = 1;
	  }
	}

	if (call.get_swing_mode().has_value()) {
	  ClimateSwingMode swingMode = *call.get_swing_mode();
	  swingChangeReq = 1;
		
      if (swingMode == CLIMATE_SWING_OFF) {
		  rq_swing = 0;
      }
      else if (swingMode == CLIMATE_SWING_VERTICAL) {
		  rq_swing = 2;
	  }
	}

    if (call.get_target_temperature().has_value()) {
      // User requested target temperature change
	  tempChangeReq = 1;
      float temp = *call.get_target_temperature();
	  rq_target_temperature = (int)temp;
      // Send target temp to climate
      // ...
    }
  }
  
  void save_AC_State() {
	  saved_Temp = this->target_temperature;
	  saved_Fan_Mode = act_fan_mode;
	  ESP_LOGD("save_AC_State", "Saved Temp: %d", (int)this->target_temperature);
	  ESP_LOGD("save_AC_State", "Saved Fan Mode_: %d", act_fan_mode);
  }
  
  void load_AC_State() {
	  load_AC_State_Sequence = 1;
  }

  void commands() {
	if (powerModeChange == 1) {
		powerModeChange = 0;
		ESP_LOGD("loop", "Power mode");
		if (rq_power_mode == 1) {
			createMessage(44, AC_ON);
		}
		else
		{
			createMessage(44, AC_OFF);
		}
	} else if ((modeChangeReq == 1) & (AC_ON_Sequence == 0) & (load_AC_State_Sequence == 0)) {
		modeChangeReq = 0;
		ESP_LOGD("loop", "Mode");
		switch(rq_mode) {
		  case 0x00: createMessage(44, AC_FAN_MODE);
			break;
		  case 0x10: createMessage(44, AC_HEAT_MODE);
			break;
		  case 0x20: createMessage(44, AC_COOL_MODE);
			break;
		  case 0x30: createMessage(44, AC_DRY_MODE);
			break;
		  case 0x60: createMessage(44, AC_AUTO_MODE);
			break;
		}
	} else if (tempChangeReq == 1) {
		  tempChangeReq = 0;
		  ESP_LOGD("loop", "Temperature. Target: %d", rq_target_temperature);
		  uint8_t ac_temp_msg[44] = {0};
		  memcpy(ac_temp_msg, AC_SET_TEMP, 44);
		  ac_temp_msg[17] = rq_target_temperature * 2 + 1;
		  createMessage(44, ac_temp_msg);
//			  ESP_LOGD("loop", "New target temperature set: %d, sending value: %d", rq_target_temperature, ac_temp_msg[17]);
	} else if (fanChangeReq == 1) {
		fanChangeReq = 0;
		ESP_LOGD("loop", "Fan mode");
		switch(rq_fan) {
		  case 0x01: createMessage(44, AC_AUTO_FAN);
			break;
		  case 0x02:
		  case 0x0A: createMessage(44, AC_EXTRA_LOW_FAN);
			break;
		  case 0x0C: createMessage(44, AC_LOW_FAN);
			break;
		  case 0x0E: createMessage(44, AC_NORMAL_FAN);
			break;
		  case 0x10: createMessage(44, AC_HIGH_FAN);
			break;
		  case 0x12: createMessage(44, AC_EXTRA_HIGH_FAN);
			break;
		}
	} else if (swingChangeReq == 1) {
		swingChangeReq = 0;
		ESP_LOGD("loop", "Swing mode");
		if (rq_swing == 0) {
			createMessage(44, AC_SWING_OFF);
		}
		else{
			createMessage(44, AC_SWING_ON);
		}
	} else if (presetChangeReq == 1) {
		presetChangeReq = 0;
		ESP_LOGD("loop", "Preset");
		if (rq_preset == 0) {
			if (last_rq_preset != 0) {
				load_AC_State();
			}
			last_rq_preset = 0;
		}
		else
		{
			if (last_rq_preset == 0) {
				save_AC_State();
			}
			last_rq_preset = rq_preset;
			switch(rq_preset) {
				case 1: switch(act_preset) {
							case 0: createMessage(44, AC_SILENT_ON);
								break;
							case 2: createMessage(44, AC_ECO_OFF);
								break;
							case 3: createMessage(44, AC_BOOST_OFF);
								break;
						}					
					break;
				case 2: switch(act_preset) {
							case 0: createMessage(44, AC_ECO_ON);
								break;
							case 1: createMessage(44, AC_SILENT_OFF);
								break;
							case 3: createMessage(44, AC_BOOST_OFF);
								break;
						}					
					break;
				case 3: switch(act_preset) {
							case 0: createMessage(44, AC_BOOST_ON);
								break;
							case 1: createMessage(44, AC_SILENT_OFF);
								break;
							case 2: createMessage(44, AC_ECO_OFF);
								break;
						}					
					break;
			}
		}
	} 	
  }
    
  void loop() override {
	while (available()) { //Bejövő üzenet kiolvasása / feldolgozása
		prevByte = currentByte;
		currentByte = read();

		if ((prevByte == 0xF4) & (currentByte == 0xFB)) {
		  msgIsComoing = 0;
		  inMsg[inMsgCnt] = 0xFB;
		  processMsg(inMsgCnt, inMsg);
		}
		
		if ((prevByte == 0xF4) & (currentByte == 0xF5)) {
		  msgIsComoing = 1;
		  inMsgCnt = 1;
		  inMsg[0] = 0xF4;
		}
		
		if (msgIsComoing == 1) {
		  inMsg[inMsgCnt] = currentByte;
		  inMsgCnt++;
		}
	}
	
	if (load_AC_State_Sequence != 0) {
		uint8_t ac_temp_msg2[44] = {0};
		switch (load_AC_State_Sequence) {
			case 1:
					ESP_LOGD("load_AC_State_Sequence", "State: 1, OFF Preset");
					switch(act_preset) {
						case 1: createMessage(44, AC_SILENT_OFF);
							break;
						case 2: createMessage(44, AC_ECO_OFF);
							break;
						case 3: createMessage(44, AC_BOOST_OFF);
							break;
					}
					load_AC_State_Sequence++;			
					break;
			case 3:
					//send saved Temperature
					ESP_LOGD("load_AC_State_Sequence", "Temperature. Target: %d", saved_Temp);
					memcpy(ac_temp_msg2, AC_SET_TEMP, 44);
					ac_temp_msg2[17] = saved_Temp * 2 + 1;
					createMessage(44, ac_temp_msg2);
					load_AC_State_Sequence++;			
					break;
			case 5:
					//send saved Custom Fan mode
					ESP_LOGD("load_AC_State_Sequence", "send saved Custom Fan mode. Mode: %d", saved_Fan_Mode);
					switch(saved_Fan_Mode) {
					  case 0x01: createMessage(44, AC_AUTO_FAN);
						break;
					  case 0x0A: createMessage(44, AC_EXTRA_LOW_FAN);
						break;
					  case 0x0C: createMessage(44, AC_LOW_FAN);
						break;
					  case 0x0E: createMessage(44, AC_NORMAL_FAN);
						break;
					  case 0x10: createMessage(44, AC_HIGH_FAN);
						break;
					  case 0x12: createMessage(44, AC_EXTRA_HIGH_FAN);
						break;
					}
					load_AC_State_Sequence++;			
					break;
			case 8:
					//saved state restored
					load_AC_State_Sequence = 0;
					ESP_LOGD("load_AC_State_Sequence", "End Sequence");
					break;
		}
	}
	
	if (AC_ON_Sequence != 0) {
		switch (AC_ON_Sequence) {
			case 1:
					ESP_LOGD("loop", "AC ON Sequence is 1. Request AC ON");
					powerModeChange = 1;
					rq_power_mode = 1;
					AC_ON_Sequence++;
					break;
			case 4:
					ESP_LOGD("loop", "AC ON Sequence is 4. Check if mode change is neccesary.");
					if (act_hvac_mode != rq_mode) {
						ESP_LOGD("loop", "AC ON Sequence is 4. Mode change is neccesary!");
						switch (rq_mode) {
						  case 0x00: createMessage(44, AC_FAN_MODE);
							ESP_LOGD("loop", "AC ON Sequence is 4. FAN mode is selected!");
							break;
						  case 0x10: createMessage(44, AC_HEAT_MODE);
							ESP_LOGD("loop", "AC ON Sequence is 4. HEAT mode is selected!");
							break;
						  case 0x20: createMessage(44, AC_COOL_MODE);
							ESP_LOGD("loop", "AC ON Sequence is 4. COOL mode is selected!");
							break;
						  case 0x30: createMessage(44, AC_DRY_MODE);
							ESP_LOGD("loop", "AC ON Sequence is 4. DRY mode is selected!");
							break;
						  case 0x60: createMessage(44, AC_AUTO_MODE);
							ESP_LOGD("loop", "AC ON Sequence is 4. AUTO mode is selected!");
							break;
						}
					}
					modeChangeReq = 0;
					AC_ON_Sequence = 0;
					ESP_LOGD("loop", "AC ON Sequence is 0.");
					break;
		}
	}
	
	/*
		commProcess: sendMessage-nél bele kerül a commandCode (65,66,1E), processMsg-nél és Communication Timeout-nál kinullázásra kerül
		commandProcess: 65-ös command küldésekor sendMessage-nél 1-be kerül, 66-os küldésnél 0-ba
	*/
	if ((commProcess == 0) & (startSequence == 99) & (commandProcess == 0)) { //Nincs aktuális üzenetváltás, első 1E status lekérdezés már megvolt és nincs aktuális command üzenetváltás se
		commands();
	}

	/*
		reqSend: CreateMessage-nél 1,2 v. 3 kerül bele (65, 66, 1E command-tól függően), sendMessage előtt kinullázásra kerül
		Process: 	CretaeMessage-nél reqSend-be érték
					Ha reqSend nem 0, akkor üzenet kiküldése és reqSend nullázása, es commProcess-be commandCode (65, 66, 1E)
					Ha commProcess nem 0 (ki lett küldve egy üzenet), és eltelt 1000msec a küldés óta válasz nélkül (a commProcess még nem 0 újra), akkor timeout van.
	*/
	
	if (commProcess == 0){
		if (reqSend != 0){
//			ESP_LOGD("loop", "reqSend = %d", reqSend);
			reqSend = 0;
			sendMessage(outLen, outBuf);			
		}
	} else {
		if ((millis() - sentTime) > 2000) {
			ESP_LOGW("Loop", "Communication Timeout");
			switch (startSequence) {
				case 99:	
					if (commProcess == 0x1E) {
						createMessage(15, AC_GET_STATUS_66);
					} else {
						createMessage(22, AC_GET_STATUS_1E);;
					}
					commProcess = 0;
					break;
				case 1:
					startSequence++;
					receivedCommandCode = 0;
					commProcess = 0;
					pause = 1;
					pauseEnd = millis();
					break;
				case 2:
					startSequence++;
					receivedCommandCode = 0;
					commProcess = 0;
					pause = 1;
					pauseEnd = millis();
					break;
				case 3:
					startSequence = 99;
					receivedCommandCode = 0x1E;
					commProcess = 0;
					pause = 1;
					pauseEnd = millis();
					break;
			}
		}
	}
	
	if (receivedCommandCode == 0x1E) {
//		ESP_LOGW("Loop", "received 0x1E");
		receivedCommandCode = 0;
		commProcess = 0; //	commandProcess: 65-ös command küldésekor sendMessage-nél 1-be kerül, 66-os küldésnél 0-ba
		pause = 1;
		pauseEnd = millis() + 1000;
		switch (startSequence) {
			case 99:
				lastMessage = 0x1E;
				break;
			case 1:
				startSequence++;
				break;
			case 2:
				startSequence++;
				break;
			case 3:
				startSequence = 99;
				lastMessage = 0x1E;
				break;				
		} 
	}

	if (receivedCommandCode == 0x66) {
//		ESP_LOGW("Loop", "received 0x66");
		receivedCommandCode = 0;
		commProcess = 0;
		pause = 1;
		pauseEnd = millis() + 1000;
		switch (startSequence) {
			case 99:
				lastMessage = 0x66;
				break;
			case 1:
				startSequence++;
				break;
		} 
		if (AC_ON_Sequence == 3) {
			AC_ON_Sequence++;
			ESP_LOGD("loop", "AC_ON_Sequence is 3. 0x66 message came.");
		}
		
		if (load_AC_State_Sequence == 7) {
			load_AC_State_Sequence++;
			ESP_LOGD("loop", "AC_ON_Sequence is 3. 0x66 message came.");
		}
		
	}

	if (receivedCommandCode == 0x65) {
//		ESP_LOGW("Loop", "received 0x65");
		receivedCommandCode = 0;
		lastMessage = 0x1E;
		commProcess = 0;
		pause = 1;
		pauseEnd = millis() + 200;
		lastMessage = 0x65;
		if (AC_ON_Sequence == 2) {
			AC_ON_Sequence++;
			ESP_LOGD("loop", "AC_ON_Sequence is 2. 0x65 message came.");
		}
		
		if (load_AC_State_Sequence == 2) {
			load_AC_State_Sequence++;
			ESP_LOGD("loop", "load_AC_State_Sequence is 2. 0x65 message came.");
		}

		if (load_AC_State_Sequence == 4) {
			load_AC_State_Sequence++;
			ESP_LOGD("loop", "load_AC_State_Sequence is 4. 0x65 message came.");
		}

		if (load_AC_State_Sequence == 6) {
			load_AC_State_Sequence++;
			ESP_LOGD("loop", "load_AC_State_Sequence is 6. 0x65 message came.");
		}

	}
	
	if ((millis() > startTime) & (startSequence == 0)){
		pause = 1;
		pauseEnd = millis() - 1000;
//		ESP_LOGW("Loop", "Firts Comm start");
		startSequence = 1;
	}
	
	if ((pause == 1) & (millis() > pauseEnd)) {
		pause = 0;
//		ESP_LOGW("Loop", "Pause End: %d", lastMessage);
		switch (startSequence) {
			case 99:
				switch (lastMessage) {
					case 0x1E:  createMessage(15, AC_GET_STATUS_66);
//								ESP_LOGW("Loop", "Create 0x66 Message");
								break;
					case 0x65: 	createMessage(22, AC_GET_STATUS_1E);
//								ESP_LOGW("Loop", "0x65 came. Create 0x0E Message");
								break;
					case 0x66:	createMessage(22, AC_GET_STATUS_1E);
//								ESP_LOGW("Loop", "0x66 came. Create 0x1E Message");
								break;
				}
				break;
			case 1: 	createMessage(14, AC_START_COMM1);
//						ESP_LOGW("Loop", "Start Comm 1");
						break;
			case 2: 	createMessage(22, AC_START_COMM2);
//						ESP_LOGW("Loop", "Start Comm 2");
						break;
			case 3: 	createMessage(22, AC_START_COMM2);
//						ESP_LOGW("Loop", "Start Comm 3");
						break;	
			default:	startSequence = 0;
						break;
		}
		
	}
	
  }
   
  ClimateTraits traits() override {
    // The capabilities of the climate device
	auto traits = climate::ClimateTraits();
    traits.set_supports_current_temperature(true);
	traits.set_supported_modes({climate::CLIMATE_MODE_OFF, climate::CLIMATE_MODE_AUTO, climate::CLIMATE_MODE_COOL,	
								climate::CLIMATE_MODE_HEAT, climate::CLIMATE_MODE_FAN_ONLY, climate::CLIMATE_MODE_DRY}	);	
    traits.set_supports_two_point_target_temperature(false);

	traits.set_supported_custom_fan_modes({"1 Super Low", "2 Low", "3 Normal", "4 High", "5 Super High", "6 Auto", "7 Quiet", "8 OFF", "0 AC ON"});	

	traits.set_supported_swing_modes({climate::CLIMATE_SWING_OFF, climate::CLIMATE_SWING_VERTICAL});	
	traits.set_supported_presets({climate::CLIMATE_PRESET_NONE, climate::CLIMATE_PRESET_BOOST, climate::CLIMATE_PRESET_ECO,
								  climate::CLIMATE_PRESET_COMFORT});	
    traits.set_visual_min_temperature(16);
    traits.set_visual_max_temperature(32);
    traits.set_visual_temperature_step(1.f);
    return traits;
  }
};