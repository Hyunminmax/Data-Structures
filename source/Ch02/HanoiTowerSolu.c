#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if(num==1)    // �̵��� ������ ���� 1�����
	{
		printf("����1�� %c���� %c�� �̵� \n", from, to);
	}
	else
	{   
		HanoiTowerMove(num-1, from, to, by);    // 3�ܰ� �� 1�ܰ�
		printf("����%d��(��) %c���� %c�� �̵� \n", num, from, to);  // 3�ܰ� �� 2�ܰ�
		HanoiTowerMove(num-1, by, from, to);    // 3�ܰ� �� 3�ܰ�
	}
}


int main(void)
{
	int num = 12;
	// ����A�� ���� 3���� ����B�� �����Ͽ� ����C�� �ű��
	HanoiTowerMove(num, 'A', 'B', 'C');
	// printf("%d", num);

	return 0;
}