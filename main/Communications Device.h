// Communications Device.h

#ifndef _COMMUNICATIONS DEVICE_h
#define _COMMUNICATIONS DEVICE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

class Communications DeviceClass
{
 protected:


 public:
	void init();
};

extern Communications DeviceClass Communications Device;

#endif

