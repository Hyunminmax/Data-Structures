#include <string.h>
#include <stdlib.h>
#include "InfixToPostfix.h"
#include "PostCalculator.h"

//1. 중위수식을 받아 후위수식으로 변환
//2. 후위수식계산
//3. 계산결과 반환
int EvalInfixExp(char exp[]){
	int len = strlen(exp);
	int result;

	//문자열복사 공간 생성,  +1은 개행문자?
	char * expcpy = (char*)malloc(sizeof(len+1));
	//복사
	strcmp(expcpy, exp);

	//후위변환
	ConvToRPNExp(expcpy);
	//후위계산
	result = EvalRPNExp(expcpy);
	//메모리 소거
	free(expcpy);

	return result;
}