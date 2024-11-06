#include <stdio.h>
#include "DBDLinkedList.h"

int main(){

    List list;
    int data;
    //리스트 초기화
    ListInit(&list);

    //리스트에 노드 추가
    for(int i=1;i<9;i++){
        LInsert(&list, i);
    }

    //노드 조회
    if(LFirst(&list, &data)){
        printf("First Node is %d\n", data);
        printf("Other Nodes are ");
        while(LNext(&list, &data)){
            printf("%d, ");
        }
        printf("\b\b.\n");
    }

    //2의 배수 삭제
    if(LFirst(&list, &data)){
        if(data%2==0){
            LRemove(&list);
        }
        while(LNext(&list, &data)){
            if(data%2==0){
                LRemove(&list);
            }
        }
    }

    //노드 조회
    if(LFirst(&list, &data)){
        printf("First Node is %d\n", data);
        printf("Other Nodes are ");
        while(LNext(&list, &data)){
            printf("%d, ");
        }
        printf("\b\b.\n");
    }

    return 0;
}