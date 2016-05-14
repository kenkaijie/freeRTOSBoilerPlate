// 
// 
// 

#include "PacketModule.h"

const uint8_t PacketModuleClass::s_SOH = 0x7E;
const uint8_t PacketModuleClass::s_packetHeaderSize = 5;

uint32_t PacketModuleClass::GeneratePacket(uint8_t destAddr, std::vector<uint8_t>& src, std::vector<uint8_t>& data)
{

	uint32_t packetSize;

	// clear the vector
	src.empty();

	src.resize(s_packetHeaderSize, 0);

	// insert SOH
	src[0] = s_SOH;

	// we first generate the SOH
	packetSize = data.size();

	// insert Packet ID
	src[1] = m_packetID;
	// insert Source address
	src[2] = m_sourceAddress;
	// insert Destination
	src[3] = destAddr;
	// length

	packetSize = data.size();

	if (packetSize > 0xFF)
	{
		return Device::System::Error::PACKET_OUT_OF_RANGE;
	}

	src[4] = data.size();
	// lower byte of packet size
	src[5] = ;

}


PacketModuleClass PacketModule;

