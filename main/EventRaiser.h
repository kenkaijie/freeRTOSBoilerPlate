// ErrorParser.h

#ifndef _ERRORPARSER_h
#define _ERRORPARSER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <StandardCplusplus.h>

#include "GlobalContext.h"

namespace Device
{
namespace System
{

enum class EventCodeEnum : uint32_t
{
DEVICE_COMM_PACKETMODULE_NOERROR		= 0xFF000000,
DEVICE_COMM_PACKETMODULE_INVALIDSIZE	= 0xFFFFFFFF
};

enum class EventProrityEnum : uint8_t
{
	EVENT_PRIORITY_LOW, // Low priority gets placed in the back of the communication queue
	EVENT_PRIORITY_HIGH,  // high priorty gets placed next in the communication queue
	EVENT_PRIORITY_URGENT // stops current transmission and sends this flag
};

/* @brief The Event Raiser is the primary event raising protocol for the communications port
		  
*/
class EventRaiser
{

public:
	EventRaiser(GlobalContextPtr context)
		: m_context(context)
	{}


	void RaiseEvent(System::EventCodeEnum eventCode, System::EventProrityEnum eventPriority);
	
private:

private:
	GlobalContextPtr m_context;

};

}
}

#endif

