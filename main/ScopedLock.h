// ScopedLock.h

#ifndef _SCOPEDLOCK_h
#define _SCOPEDLOCK_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "RTOSSetting.h"
#include <semphr.h>

namespace Device
{
namespace Utils
{

class ScopedLock
{
private:
    SemaphoreHandle_t & m_mutex;


 public:
     ScopedLock(SemaphoreHandle_t & mutex)
         : m_mutex(mutex)
    {
        xSemaphoreTake(m_mutex, portMAX_DELAY);
    }

    ~ScopedLock()
    {
        xSemaphoreGive(m_mutex);
    }
};

}
}
#endif

