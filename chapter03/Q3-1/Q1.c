#include <stdio.h>
#include "ArrayList.h"
// 리스트 전체의 합
// 헤더 파일에 추가해보는 것도 재미있을듯.
void Ltotal(List * list){
    int data;
    int total;

    if(LFirst(list, &data)){
            total = data;
        while(LNext(list, &data)){
            total += data;
        }
    }
    printf("리스트 요소의 합은: %d\n", total);
}

int main(void){

    List list;
    int data;
    int cnt;
    int total;

    ListInit(&list);

// 1~9까지 추가
    for(int i = 1; i<10; i++){
        LInsert(&list, i);
    }
    printf("리스트 요소의 수는: %d\n", LCount(&list));

// 리스트 전체의 합
    Ltotal(&list);

// 리스트 요소 중 2배수와 3배수 삭제
    if(LFirst(&list, &data)){
            if(data%2==0 || data%3==0){
                LRemove(&list);
            }
        while(LNext(&list, &data)){
            if(data%2==0 || data%3==0){
                LRemove(&list);
            }
        }
    }
    
// 리스트 전체의 합
    Ltotal(&list);

// 리스트에 저장 된 데이터를 순차 출력
    if(LFirst(&list, &data)){
        printf("리스트의 요소는: %d", data);
        while(LNext(&list, &data)){
            printf(", %d", data);
        }
        printf("\n");
    }
    
    return 0;
}