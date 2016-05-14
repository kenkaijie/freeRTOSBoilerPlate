// IPacketProtocol.h

#ifndef _IPACKETPROTOCOL_h
#define _IPACKETPROTOCOL_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


/* @brief	A slightly smart packet protocol interface which provides encapsulation of a packet
			as well as getters, and setters, we write a class for the protocol so that checked
			packets can be implemented internally, all sets will return bools to indicate 
			success or failure
*/
class IPacketProtocol
{

public:
	/*
	*/
	virtual uint8_t GetPacketID(void) = 0;
	virtual bool SetPacketID(uint8_t ID) = 0;

	virtual uint8_t GetSourceAddress(void) = 0;
	virtual bool SetSourceAddress(uint8_t address) = 0;

	virtual uint8_t GetDestinationAddress(void) = 0;
	virtual bool SetDestinationAddress(uint8_t address) = 0;

	virtual const char* Stringify(void) = 0;

};

#endif

