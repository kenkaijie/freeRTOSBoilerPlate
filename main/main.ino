#include "FreeRTOS.h"
#include "ScopedLock.h"
#include <queue.h>
#include <task.h>

#include <StandardCplusplus-master\StandardCplusplus.h>
#include <StandardCplusplus-master\vector>

#include "GlobalContext.h"

// define two tasks for Blink & AnalogRead
void MainThread(void* pvParameters);
void SerialThread(void* pvParameters);
void ReadAnalog(GlobalContextPtr context);

GlobalContextPtr GetGlobalContext(void* pvParameters);

// the setup function runs once when you press reset or power the board
void setup() {

    std::vector<uint8_t> vector;

    GlobalContextPtr globalContext = new GlobalContext();

    // Now set up two tasks to run independently.
    xTaskCreate(
        MainThread
        , (const portCHAR *)"MainThread"   // A name just for humans
        , 128  // Stack size
        , globalContext
        , 2  // priority
        , NULL);

    

    xTaskCreate(
        SerialThread
        , (const portCHAR *) "SerialThread"
        , 128 // This stack size can be checked & adjusted by reading Highwater
        , globalContext
        , 1  // priority
        , NULL);

    xTaskCreate(
        UIThread
        , (const portCHAR *) "UIThread"
        , 128 // This stack size can be checked & adjusted by reading Highwater
        , globalContext
        , 1  // priority
        , NULL);

    // Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}

void loop()
{
    // Empty. Things are done in Tasks.
}

/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/

void MainThread(void* pvParameters)  // This is a task.
{

    GlobalContextPtr context = GetGlobalContext(pvParameters);

    // initialize digital pin 13 as an output.
    pinMode(13, OUTPUT);

    QueuedFunction queuedFuction;

    queuedFuction.functionHandle = &ReadAnalog;

    for (;;) // A Task shall never return or exit.
    {
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        vTaskDelay(300 / portTICK_PERIOD_MS); // wait for one second
        digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
        vTaskDelay(500 / portTICK_PERIOD_MS); // wait for one second
        context->GetCommunicationThreadDispatcher()->Dispatch(&queuedFuction);
        vTaskDelay(500 / portTICK_PERIOD_MS); // wait for one second
    }
}

void SerialThread(void* pvParameters)  // This is a task.
{

    GlobalContextPtr context = GetGlobalContext(pvParameters);

    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);

    for (;;)
    {
        context->GetCommunicationThreadDispatcher()->Execute();
    }
}

void ReadAnalog(GlobalContextPtr context)
{
    Serial.print("Came here once on the ");
    Serial.print(pcTaskGetTaskName(NULL));
    Serial.println(" thread.");
    vTaskDelay(500 / portTICK_PERIOD_MS);
}

void UIThread(void* pvParameters)
{
    GlobalContextPtr context = GetGlobalContext(pvParameters);

	context->GetCommunicationThreadDispatcher();

    for (;;)
    {

    }
}

GlobalContextPtr GetGlobalContext(void * pvParameters)
{
    configASSERT(pvParameters != NULL);

    return (GlobalContextPtr)pvParameters;
}
