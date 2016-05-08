// GlobalContext.h

#ifndef _GLOBALCONTEXT_h
#define _GLOBALCONTEXT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <semphr.h>

#include "CommunicationThreadDispatcher.h"

/*! @brief GlobalContext handles the queueing
 */
class GlobalContext
{

public:
    GlobalContext()
    {
        m_communicationThreadDispatcher = new CommunicationThreadDispatcher(this);
    }

private:
     GlobalContext(const GlobalContext &);
     GlobalContext & operator = (const GlobalContext &);

 public:
     CommunicationThreadDispatcherPtr GetCommunicationThreadDispatcher() { return m_communicationThreadDispatcher; }




private:
    CommunicationThreadDispatcherPtr m_communicationThreadDispatcher;
    
};

typedef GlobalContext* GlobalContextPtr;

#endif

