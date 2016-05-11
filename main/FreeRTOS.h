#pragma once
#ifndef SETTINGS_RTOS_H
#define SETTINGS_RTOS_H

/*
* Include the generic headers required for the FreeRTOS port being used.
*/
#include <stddef.h>

/*
* If stdint.h cannot be located then:
*   + If using GCC ensure the -nostdint options is *not* being used.
*   + Ensure the project's include path includes the directory in which your
*     compiler stores stdint.h.
*   + Set any compiler options necessary for it to support C99, as technically
*     stdint.h is only mandatory with C99 (FreeRTOS does not require C99 in any
*     other way).
*   + The FreeRTOS download includes a simple stdint.h definition that can be
*     used in cases where none is provided by the compiler.  The files only
*     contains the typedefs required to build FreeRTOS.  Read the instructions
*     in FreeRTOS/source/stdint.readme for more information.
*/
#include <stdint.h> /* READ COMMENT ABOVE. */

#ifdef __cplusplus
extern "C" {
#endif

#ifndef INCLUDE_pcTaskGetTaskName
	#define INCLUDE_pcTaskGetTaskName 1
#endif



#ifdef __cplusplus
}
#endif

#include <Arduino_FreeRTOS.h>

#endif /* SETTINGS_RTOS_H */

