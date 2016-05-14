// IDispatcher.h

#ifndef _IDISPATCHER_h
#define _IDISPATCHER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

namespace Device
{
namespace System
{
	class GlobalContext;

	typedef GlobalContext* GlobalContextPtr;

	struct QueuedFunction
	{
		void(*functionHandle)(GlobalContextPtr context);
	};

	typedef QueuedFunction* QueuedFunctionPtr;

	class IDispatcher
	{


	public:
		virtual void Dispatch(QueuedFunctionPtr functionHandle) = 0;
		virtual void Execute(void) = 0;
	};

}
}
#endif

