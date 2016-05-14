// PacketModule.h

#ifndef _PACKETMODULE_h
#define _PACKETMODULE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <StandardCplusplus.h>
#include <vector>

#include "EventRaiser.h"

namespace Device
{
namespace Communication
{

/* @brief The Packet Module is incharge of creating and handling packets, it will be the only module that opens up packet data.

	It required functionality to decode and build packets receieved, as well as validate packets. High level packet actions, such as resending
	should be handled in a higher class
*/
class PacketModule
{
 public:
	 PacketModule();

	System::EventCodeEnum GeneratePacket(const std::vector<uint8_t> & data);

private:

	uint8_t GenCRC8(const std::vector<uint8_t> & packet);

	bool ValidateCRC8(const std::vector<uint8_t> & packet);

	static const uint8_t s_CRC8Table[256];
};



}
}
#endif

