#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if(num==1)    // 이동할 원반의 수가 1개라면
	{
		printf("원반%d을 %c에서 %c로 이동 \n", num, from, to);
	}
	else
	{   
		HanoiTowerMove(num-1, from, to, by);    // 3단계 중 1단계
		printf("원반%d을(를) %c에서 %c로 이동 \n", num, from, to);  // 3단계 중 2단계
		printf("%d", num);
		HanoiTowerMove(num-1, by, from, to);    // 3단계 중 3단계
	}
}


int main(void)
{
	int num = 12;
	// 막대A의 원반 3개를 막대B를 경유하여 막대C로 옮기기
	HanoiTowerMove(num, 'A', 'B', 'C');
	printf("%d", num);

	return 0;
}

// 위 코드는 하노이 타워 해결 코드이다. 
// 12개로 문제를 시도하면 11번 원반은 최소 2번 움직여야 한다. 
// 하지만 11번 원반과 12번 원반은 출력문을 통해 출력되지 않는다.
// 이유는 무엇일까?