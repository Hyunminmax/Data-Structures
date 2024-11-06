#include <stdio.h>
#include "BinaryTree2.h"

void ShowIntData(int data);

int main(void)
{
	BTreeNode * bt1 = MakeBTreeNode();
	BTreeNode * bt2 = MakeBTreeNode();
	BTreeNode * bt3 = MakeBTreeNode();
	BTreeNode * bt4 = MakeBTreeNode();
	BTreeNode * bt5 = MakeBTreeNode();
	BTreeNode * bt6 = MakeBTreeNode();

	SetData(bt1, 1);
	SetData(bt2, 2);
	SetData(bt3, 3);
	SetData(bt4, 4);
	SetData(bt5, 5);
	SetData(bt6, 6);

	MakeLeftSubTree(bt1, bt2);
	MakeRightSubTree(bt1, bt3);
	MakeLeftSubTree(bt2, bt4);
	MakeRightSubTree(bt2, bt5);
	MakeRightSubTree(bt3, bt6);

	// 				1
	// 		2				3
	// 4		5		6

	PreorderTraverse(bt1, ShowIntData); 
	printf("\n");
	InorderTraverse(bt1, ShowIntData);
	printf("\n");
	PostorderTraverse(bt1, ShowIntData);
	printf("\n");


	// Deletetree(bt1);
	// 				1
	// 		2				3
	// 4		5		6
	// 예상 동작 순서는 4, 5, 2, 6, 3, 1

	Deletetree(bt2);
	// 				1
	// 		2				3
	// 4		5		6
	// 예상 동작 순서는 4, 5, 2
	// 				1
	// 		(2)				3
	// (4)		(5)		6


	// 전위
	// PreorderTraverse(bt1, ShowIntData); 
	// printf("\n");
	// 				1
	// 		(2)				3
	// 4		5		6
	// 예상 숫자는 1, 3, 6

	// 중위
	// InorderTraverse(bt1, ShowIntData);
	// printf("\n");
	// 				1
	// 		(2)				3
	// 4		5		6
	// 예상 숫자는 1, 6, 3

	// 후위
	// PostorderTraverse(bt1, ShowIntData);
	// printf("\n");
	// 				1
	// 		(2)				3
	// 4		5		6
	// 예상 숫자는 6, 3, 1

	PreorderTraverse(bt1, ShowIntData); 
	// printf("\n");
	// InorderTraverse(bt1, ShowIntData);
	// printf("\n");
	// PostorderTraverse(bt1, ShowIntData);
	// printf("\n");


	return 0;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}
