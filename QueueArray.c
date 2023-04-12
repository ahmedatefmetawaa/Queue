#include <stdio.h>
#include "QueueArray.h"

queue_t *createQueue(uint32_t maxsize, queue_status_t *ret_status)
{
    queue_t *myqueue;
    if (NULL == ret_status)
    {
        *ret_status = queue_null_pointer;
        myqueue = NULL;
    }
    else
    {
        myqueue = (queue_t *)malloc(sizeof(queue_t));
        if (NULL == myqueue)
        {
            *ret_status = queue_NOK;
            myqueue = NULL;
        }
        else
        {
            myqueue->QueueArray = (void **)calloc(maxsize, sizeof(void *));
            if (NULL == myqueue->QueueArray)
            {
                *ret_status = queue_NOK;
                myqueue = NULL;
            }
            else
            {
                myqueue->queuemaxsize = maxsize;
                myqueue->queuefront = -1;
                myqueue->queuerear = -1;
                myqueue->elementcount = 0;
                *ret_status = queue_OK;
            }
        }
    }
    return (myqueue);
}

queue_status_t EnqueueElement(queue_t *queue_obj, void *item)
{
    queue_status_t status = queue_NOK;
    if ((NULL == queue_obj) || (NULL == item))
    {
        status = queue_null_pointer;
    }
    else
    {
        if ((queue_obj->elementcount) == (queue_obj->queuemaxsize))
        {
            status = queue_full;
        }
        else
        {
            (queue_obj->queuerear)++;
            if (queue_obj->queuerear == queue_obj->queuemaxsize)
            {
                (queue_obj->queuerear) = 0;
            }
            else
            { /*Nothing*/
            }
            queue_obj->QueueArray[queue_obj->queuerear] = item;
            if (queue_obj->elementcount == 0)
            {
                queue_obj->queuefront = 0;
                queue_obj->elementcount = 1;
            }
            else
            {
                (queue_obj->elementcount)++;
            }
            status = queue_OK;
        }
    }
    return status;
}

void *DequeueElement(queue_t *queue_obj, queue_status_t *ret_status)
{
    void *queue_ret = NULL;
    if ((NULL == queue_obj) || (NULL == ret_status)) // check_pointers
    {
        *ret_status = queue_null_pointer;
    }
    else
    {
        if (!queue_obj->elementcount) // check_empty_queue
        {
            *ret_status = queue_empty;
            queue_ret = NULL;
        }
        else
        {
            queue_ret = queue_obj->QueueArray[queue_obj->queuefront]; // insert_data
            (queue_obj->queuefront)++;
            if (queue_obj->queuefront == queue_obj->queuemaxsize)
            {
                queue_obj->queuefront = 0;
            }
            else
            { /*nothing*/
            }
            if (1 == queue_obj->elementcount)
            {
                queue_obj->queuefront = -1;
                queue_obj->queuerear = -1;
            }
            else
            { /*Nothing*/
            }

            (queue_obj->elementcount)--;
            *ret_status = queue_OK;
        }
    }
    return queue_ret;
}

void *Queuefront(queue_t *queue_obj, queue_status_t *ret_status)
{
    void *queue_ret = NULL;
    if ((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = queue_null_pointer;
        queue_ret = NULL;
    }
    else
    {
        if (!queue_obj->elementcount) // check_empty_queue
        {
            *ret_status = queue_empty;
            queue_ret = NULL;
        }
        else
        {
            queue_ret = queue_obj->QueueArray[queue_obj->queuefront]; // insert_data
            *ret_status = queue_OK;
        }
    }
    return queue_ret;
}

void *Queuerear(queue_t *queue_obj, queue_status_t *ret_status)
{
    void *queue_ret = NULL;
    if ((NULL == queue_obj) || (NULL == ret_status))
    {
        *ret_status = queue_null_pointer;
    }
    else
    {
        if (!queue_obj->elementcount) // check_empty_queue
        {
            *ret_status = queue_empty;
            queue_ret = NULL;
        }
        else
        {
            queue_ret = queue_obj->QueueArray[queue_obj->queuerear]; // insert_data
            *ret_status = queue_OK;
        }
    }
    return queue_ret;
}

queue_status_t Getqueuecount(queue_t *queue_obj, uint32_t *queuecount)
{
    queue_status_t status = queue_NOK;
    if ((NULL == queue_obj) || (NULL == queuecount))
    {
        status = queue_NOK;
    }
    else
    {
        if (!queue_obj->elementcount) // check_empty_queue
        {
            *queuecount = 0;
        }
        else
        {
            *queuecount = queue_obj->elementcount;
        }
        status = queue_OK;
    }
    return (status);
}
queue_status_t queuedestroy(queue_t *queue_obj)

{
    queue_status_t status = queue_NOK;
    if (NULL == queue_obj)
    {
        status = queue_null_pointer;
    }
    else
    {
        free(queue_obj->QueueArray);
        free(queue_obj);
        status = queue_OK;
    }
    return (status);
}
