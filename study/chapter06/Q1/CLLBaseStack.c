#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"
#include "CLLBaseStack.h"

void StackInit(Stack * pstack){
	//스택 구조체의 요소인 리스트 선언
	pstack->plist = (List*)malloc(sizeof(List));
	//리스트 초기화
	ListInit(pstack->plist);
}

int SIsEmpty(Stack * pstack){
	//리스트의 카운트 확인
	if(LCount(pstack->plist)==0){
		return TRUE;
	}else{
		return FALSE;
	}
}

void SPush(Stack * pstack, Data data){
	LInsertFront(pstack->plist, data);
}

Data SPop(Stack * pstack){
	Data data;
	//head 방향으로 추가되었기 때문에 읽어오는 자료는 항상 LFirst
	LFirst(pstack->plist, &data);
	LRemove(pstack->plist);
	return data;
}

Data SPeek(Stack * pstack){
	Data data;
	//head 방향으로 추가되었기 때문에 읽어오는 자료는 항상 LFirst
	LFirst(pstack->plist, &data);
	return data;
}