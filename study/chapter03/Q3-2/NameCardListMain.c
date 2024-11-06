#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(){
	List list;
	NameCard * card; // 여기가 이해가 잘 안되네.. 구조체 변수 선언이다 이놈아. 
	ListInit(&list);
	char tName[30];
	char newNum[30];

	// 3명의 정보입력
	card = MakeNameCard("하하", "111");
	LInsert(&list, card);

	card = MakeNameCard("aa", "222");
	LInsert(&list, card);

	card = MakeNameCard("33", "333");
	LInsert(&list, card);

	// 특정 이름 탐색, 출력
	printf("검색할 이름은:");
	scanf("%s", &tName);
	if(LFirst(&list, &card)){
		if(!strcmp(card->name, tName))
		printf("이름: %s, 번호: %s\n", card->name, card->phone);
		while(LNext(&list, &card)){
			if(!strcmp(card->name, tName))
			printf("이름: %s, 번호: %s\n", card->name, card->phone);
		}
	}

	// 특정이름 탐색, 번호 변경
	printf("변경할 이름은:");
	scanf("%s", &tName);
	printf("신규 번호는:");
	scanf("%s", &newNum);

	if(LFirst(&list, &card)){
		if(!strcmp(card->name, tName)){
			printf("변경 전 이름: %s, 번호: %s\n", card->name, card->phone);
			strcpy(card->phone, newNum);	
			printf("변경 후 이름: %s, 번호: %s\n", card->name, card->phone);
		}
		while(LNext(&list, &card)){
			if(!strcmp(card->name, tName)){
				printf("변경 전 이름: %s, 번호: %s\n", card->name, card->phone);
				strcpy(card->phone, newNum);	
				printf("변경 후 이름: %s, 번호: %s\n", card->name, card->phone);
			}
		}
	}

	// 특정 이름 탐색, 삭제
	printf("삭제할 이름은:");
	scanf("%s", &tName);
	
	if(LFirst(&list, &card)){
		if(!strcmp(card->name, tName)){
			printf("삭제대상 이름: %s, 번호: %s\n", card->name, card->phone);
			LRemove(&list);
		}
		while(LNext(&list, &card)){
			if(!strcmp(card->name, tName)){
				printf("삭제대상 이름: %s, 번호: %s\n", card->name, card->phone);
				LRemove(&list);
			}
		}
	}

	// 남은 사람을 출력
	printf("남은 리스트 요소는: %d\n", LCount(&list));
	if(LFirst(&list, &card)){
		if(!strcmp(card->name, tName))
		printf("이름: %s, 번호: %s\n", card->name, card->phone);
		while(LNext(&list, &card)){
			if(!strcmp(card->name, tName))
			printf("이름: %s, 번호: %s\n", card->name, card->phone);
		}
	}

	return 0;
}