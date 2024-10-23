#include <stdio.h>
#include "CLLBaseStack.h"

int main(){
	//stack 초기화
	Stack stack;
	StackInit(&stack);

	//데이터 넣기
	for(int i=1;i<10;i++){
		SPush(&stack, i);
	}

	//데이터 조회
	printf("peek: %d\n", SPeek(&stack));

	//데이터 조회 및 꺼내기
	while(!SIsEmpty(&stack)){
		printf("%d ", SPop(&stack));
	}
	printf("\n");
	return 0;
}