#include <stdio.h>
#include <stdlib.h>
#include "QueueArray.h"

queue_t *myqueue = NULL;
uint32_t maxqueue = 0;
uint32_t var1 = 0x15, var2 = 0x20, var3 = 0x25, var4 = 0x30, var5 = 0x35;
void *deque_ret = NULL;
uint32_t countqueue = 0;
int main()
{
    queue_status_t status = queue_NOK;
    printf("enter the number of Queue elements:");
    scanf("%i", &maxqueue);
    myqueue = createQueue(maxqueue, &status);
    printf("status:%i\n", status);
    printf("0x%x\n", myqueue);

    status = EnqueueElement(myqueue, &var1);
    printf("status:%i\n", status);

    status = EnqueueElement(myqueue, &var2);
    printf("status:%i\n", status);
    status = EnqueueElement(myqueue, &var3);
    printf("status:%i\n", status);
    status = EnqueueElement(myqueue, &var4);
    printf("status:%i\n", status);
    status = EnqueueElement(myqueue, &var5);
    printf("status:%i\n", status);

    status = EnqueueElement(myqueue, &var5);
    printf("status:%i\n", status);

    deque_ret = DequeueElement(myqueue, &status);
    printf("status:%i\n", status);
    printf("value:0X%X\n", *((uint32_t *)deque_ret));

    deque_ret = Queuefront(&myqueue, &status);
    printf("status:%i\n", status);
    printf("value:0X%X\n", *((uint32_t *)deque_ret));

    deque_ret = Queuerear(&myqueue, &status);
    printf("status:%i\n", status);
    printf("value:0X%X\n", *((uint32_t *)deque_ret));

    status = Getqueuecount(&myqueue, &countqueue);
    printf("status:%i\n", status);
    printf("count number:%i", countqueue);

    status = queuedestroy(&myqueue);
    printf("status:%i\n", status);

    return 0;
}
