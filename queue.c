#include "TheOutsider.h"

void init(u32 *head, u32 *tail)
{
    *head = *tail = 0;
}

void enqueue(u32 *q,u32 *tail, u32 element)
{
    q[(*tail)++] = element;
}

u32 dequeue(u32 *q,u32 *head)
{
    return q[(*head)++];
}

u32 full(u32 tail,const u32 size)
{
    return tail == size;
}

u32 empty(u32 head, u32 tail)
{
    return tail == head;
}

void display(u32 *q,u32 head,u32 tail)
{
    u32 i = tail - 1;
    while(i >= head)
        printf("%d ",q[i--]);
    printf("\n");
}
