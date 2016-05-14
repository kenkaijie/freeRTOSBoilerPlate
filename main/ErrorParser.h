// ErrorParser.h

#ifndef _ERRORPARSER_h
#define _ERRORPARSER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

namespace Device
{
namespace System
{

enum ErrorEnum
{
DEVICE_COMM_PACKETMODULE_INVALIDSIZE = 0xFFFFFFFF
};

class EventRaiser
{
	RaiseEvent
};

}
}

#endif

