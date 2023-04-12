#ifndef _QUEUE_ARRAY_H
#define _QUEUE_ARRAY_H

#include "platform_type.h"
typedef struct
{
    void **QueueArray;
    uint32_t queuemaxsize;
    uint16_t elementcount;
    sint32_t queuefront;
    sint32_t queuerear;

}queue_t;

typedef enum return_status{
    queue_NOK=0,
    queue_OK,
    queue_full,
    queue_empty,
    queue_null_pointer
}queue_status_t;

queue_t* createQueue(uint32_t maxsize , queue_status_t *ret_status);
queue_status_t EnqueueElement(queue_t* queue_obj , void* item);
void * DequeueElement (queue_t* queue_obj ,queue_status_t *ret_status );
void * Queuefront(queue_t* queue_obj , queue_status_t *ret_status);
void * Queuerear(queue_t* queue_obj , queue_status_t *ret_status);
queue_status_t Getqueuecount(queue_t* queue_obj , uint32_t *queuecount);
queue_status_t queuedestroy(queue_t* queue_obj);
#endif // _QUEUE_ARRAY_H
