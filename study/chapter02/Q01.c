#include <stdio.h>

void HanoiTowerMove(int num, char from, char by, char to)
{
	if(num==1)    // �̵��� ������ ���� 1�����
	{
		printf("����%d�� %c���� %c�� �̵� \n", num, from, to);
	}
	else
	{   
		HanoiTowerMove(num-1, from, to, by);    // 3�ܰ� �� 1�ܰ�
		printf("����%d��(��) %c���� %c�� �̵� \n", num, from, to);  // 3�ܰ� �� 2�ܰ�
		printf("%d", num);
		HanoiTowerMove(num-1, by, from, to);    // 3�ܰ� �� 3�ܰ�
	}
}


int main(void)
{
	int num = 12;
	// ����A�� ���� 3���� ����B�� �����Ͽ� ����C�� �ű��
	HanoiTowerMove(num, 'A', 'B', 'C');
	printf("%d", num);

	return 0;
}

// �� �ڵ�� �ϳ��� Ÿ�� �ذ� �ڵ��̴�. 
// 12���� ������ �õ��ϸ� 11�� ������ �ּ� 2�� �������� �Ѵ�. 
// ������ 11�� ���ݰ� 12�� ������ ��¹��� ���� ��µ��� �ʴ´�.
// ������ �����ϱ�?