#include <stdio.h>
#include <stdlib.h>
#include "DBDLinkedList.h"

void ListInit(List * plist)
{
	//리스트의 헤드와 테일 메모리 할당
	plist->head = (Node*)malloc(sizeof(Node));
	plist->tail = (Node*)malloc(sizeof(Node));

	//헤드와 테일의 앞뒤 주소 할당
	plist->head->prev = NULL;
	plist->tail->next = NULL;
	plist->head->next = plist->tail;
	plist->tail->prev = plist->head;

	//리스트 노드 수 초기화
	plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
	//신규노드 추가
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;

	//1. 신규노드의 prev, 기존 tail의 prev간의 연결, 순서중요
	newNode->prev = plist->tail->prev;
	plist->tail->prev->next = newNode;

	//2. 신규노드의 next, tail간의 연결, 순서중요
	newNode->next = plist->tail;
	plist->tail->prev = newNode;

	//리스트 노드 수 증가
	(plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
	//노드가 없다면
	if(plist->head->next == plist->tail)
		return FALSE;

	//노드가 있다면 head가 가리키는 첫 노드의 주소에 cur위치
	plist->cur = plist->head->next;
	*pdata = plist->cur->data;

	return TRUE;
}

int LNext(List * plist, Data * pdata)
{
	//다음 노드가 tail이면 리스트의 종료.
	if(plist->cur->next == plist->tail)
		return FALSE;

	//노드가 있다면 다음 노드로 이동
	plist->cur = plist->cur->next;
	*pdata = plist->cur->data;

	return TRUE;
}

Data LRemove(List * plist){
	//삭제되는 데이터 노드
	Node * rpos = plist->cur;
	Data data = rpos->data;

	//cur의 전, 후 노드의 값을 서로 연결
	plist->cur->prev->next = plist->cur->next;
	plist->cur->next->prev = plist->cur->prev;

	//cur의 위치를 cur->prev로 변경
	plist->cur = plist->cur->prev;

	//메모리 소거하고 리스트 카운드 변경
	free(rpos);
	(plist->numOfData)--;

	return data;
}

// int LPrevious(List * plist, Data * pdata)
// {
// 	//현 노드의 이전에 주소가 없으면 
// 	if(plist->cur->prev == NULL)
// 		return FALSE;

// 	plist->cur = plist->cur->prev;
// 	*pdata = plist->cur->data;

// 	return TRUE;
// }

int LCount(List * plist)
{
	return plist->numOfData;
}