// CommunicationDevice.h

#ifndef _COMMUNICATIONDEVICE_h
#define _COMMUNICATIONDEVICE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include <Arduino_FreeRTOS.h>
#include <queue.h>
#include <semphr.h>
#include "ScopedLock.h"

#include "IDispatcher.h"

class GlobalContext;

typedef GlobalContext* GlobalContextPtr;

class CommunicationThreadDispatcher: public IDispatcher
{
 protected:


 public:
    CommunicationThreadDispatcher(GlobalContextPtr context)
        : m_internalCount(0)
        , m_context(context)
    {
        void(*functionHandle)(void* context);
        m_communicationQueue = xQueueCreate(5, sizeof(struct QueuedFunction *));
        m_mutex = xSemaphoreCreateMutex();
    }


    void Dispatch(QueuedFunctionPtr queuedFunction)
    {
        ScopedLock lock(m_mutex);
        xQueueSendToBack(m_communicationQueue, &queuedFunction, (TickType_t)10);

    }

    void Execute(void)
    {
        ScopedLock lock(m_mutex);
        struct QueuedFunction * queuedFunction;
        if (xQueueReceive(m_communicationQueue, &queuedFunction, (TickType_t)10) == pdTRUE)
        {
            void(*functionHandle)(GlobalContextPtr context);
            queuedFunction->functionHandle(m_context);
        }
    }

private:
    QueueHandle_t m_communicationQueue;
    SemaphoreHandle_t m_mutex;
    GlobalContextPtr m_context;

private:
    uint8_t m_internalCount;
};

typedef CommunicationThreadDispatcher* CommunicationThreadDispatcherPtr;

#endif

