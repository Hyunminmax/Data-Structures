#include <stdio.h>
#include "DequeBaseQueue.h"

int main(){
    Queue q;
    QueueInit(&q);
    
    for(int i=0; i<10; i++){
        Enqueue(&q, i);
    }

    while(!QIsEmpty(&q)){
        printf("%d\n", Dequeue(&q));
    }
    return 0;
}