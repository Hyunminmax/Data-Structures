#include <stdio.h>
#include <stdlib.h>
#include "DequeBaseQueue.h"

void QueueInit(Queue * pq){
    // pq->head = NULL;
    // pq->tail = NULL;
    DequeInit(pq);
}

int QIsEmpty(Queue * pq){
    return DQIsEmpty(pq);
}

void Enqueue(Queue * pq, Data data){
    DQAddFirst(pq, data);
}
Data Dequeue(Queue * pq){
    DQRemoveLast(pq);
}
Data QPeek(Queue * pq){
    DQGetLast(pq);
}