#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

//가독성과 컴파일 오류를 줄이기 위해 main 앞단에 함수명시, 구현은 main 후에.
Employee * WhoIsNextNightDuty(List * plist, char * name, int day);
void ShowEmployeeInfo(Employee * emp);

int main(){
    //임플로이 구조체 빈 변수 선언
    Employee * pemp;
    //리스트 빈 변수 선언
    List list;
    //리스트 변수의 주소로 리스트 초기화
    ListInit(&list);

    //사원등록 반복문
    for(int i=111; i<555; i+=111){
        //구조체 변수에 임플로이 구조체 크기의 메모리 할당
        pemp = (Employee*)malloc(sizeof(Employee));
        //사번
        pemp->empNum = i;
        //사원명
        sprintf(pemp->name, "John Doe %d", i);
        //리스트에 구조체 추가
        LInsert(&list, pemp);
    }

    //"John Doe 111"의 당직 3일 후는 누구의 당직인가?
    printf("Who is on NightDuty 3 days after John Doe 111?\n");
    pemp = WhoIsNextNightDuty(&list, "John Doe 111", 3);
    ShowEmployeeInfo(pemp);
    
    //"John Doe 222"의 당직 13일 후는 누구의 당직인가?
    printf("Who is on NightDuty 13 days after John Doe 222?\n");
    pemp = WhoIsNextNightDuty(&list, "John Doe 222", 13);
    ShowEmployeeInfo(pemp);

    //할당된 메모리 소거
    if(LFirst(&list, &pemp)){
        //원형연결리스트라서 리스트의 첫 노드를 소거하고 LNext가 가능
        free(pemp);
        for(int i=0; i<LCount(&list)-1;i++){
            if(LNext(&list, &pemp)){
                free(pemp);
            }
        }
    }
    return 0;
}

Employee * WhoIsNextNightDuty(List *plist, char * name, int day){
    int num;
    //당직자를 반환 할 임플로이 포인터선언
    Employee *duty;
    //당직 후보자의 수
    num = LCount(plist);

    //첫당직자 검색
    LFirst(plist, &duty);
    //입력받은 검색기준 당직자 검색
    if(strcmp(duty->name, name)!=0){
        int i;
        for(i=0;i<num-1;i++){
            LNext(plist, &duty);
            if(strcmp(duty->name, name)==0){
                break;
            }
        }
        //리스트 전체를 검색해도 없으면 NULL반환
        if(i>num-1)
            return NULL;
    }

    //기준 당직자로부터 입력받은 day만큼 지나면 누가 당직인가?
    for(int i=0;i<day;i++){
        LNext(plist, &duty);
    }
    return duty;
}

void ShowEmployeeInfo(Employee * emp){
    printf("Employee Name is %s\n", emp->name);
    printf("Employee Number is %d\n", emp->empNum);
}