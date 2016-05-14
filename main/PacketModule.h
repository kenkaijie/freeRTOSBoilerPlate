// PacketModule.h

#ifndef _PACKETMODULE_h
#define _PACKETMODULE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <StandardCplusplus.h>
#include <StandardCplusplus-master\vector>

typedef std::vector<uint8_t> Packet_t;

/* @brief The Packet Module is incharge of creating and handling packets, it will be the only module that opens up packet data.

	It required functionality to decode and build packets receieved, as well as validate packets. High level packet actions, such as resending
	should be handled in a higher class
*/
class PacketModuleClass
{
 private:

	 /* @brief Generates a CRC16 with polynomial 0x1021 for the given packet. Does not append to the end of the packet

		@param packet: a packet to generate the CRC from, it will use all the bytes
	 */
	 uint16_t GenCRC16(std::vector<uint8_t>& packet);

	 /*	@brief Validates a packet using CRC16

		@param packet: a complete packet with CRC	
	 */
	 bool ValidateCRC16(std::vector<uint8_t>& packet);

 public:
	PacketModuleClass()
		: m_packetID(0)
	{ }

	void GeneratePacket(const char* string );

	/* @ brief This is the only place where a "large" copy will be performed on the packet class
	*/
	Packet_t StringToPacket(const char* str, uint16_t len);

private:
	uint32_t m_packetID; // keeps a record of for incrementing reply packets
	static const uint8_t s_SOH;
};

extern PacketModuleClass PacketModule;

#endif

