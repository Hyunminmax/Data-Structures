#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * ch1, char * ch2)
{
	return strlen(ch2)-strlen(ch1);
}

int main(void)
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "ABC");
	PEnqueue(&pq, "BCDE");
	PEnqueue(&pq, "CD");
	printf("%s \n", PDequeue(&pq));

	// PEnqueue(&pq, 'A');
	// PEnqueue(&pq, 'B');
	// PEnqueue(&pq, 'C');
	// printf("%c \n", PDequeue(&pq));

	while(!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
