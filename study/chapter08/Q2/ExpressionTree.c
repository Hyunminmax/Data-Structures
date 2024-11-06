#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree2.h"

BTreeNode * MakeExpTree(char exp[])
{
	Stack stack;
	BTreeNode * pnode;

	int expLen = strlen(exp);
	int i;

	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		pnode = MakeBTreeNode();

		if(isdigit(exp[i]))		// 피연산자라면...
		{
			SetData(pnode, exp[i]-'0');
		}
		else					// 연산자라면...
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);
	}

	return SPop(&stack);
}

int EvaluateExpTree(BTreeNode * bt)
{
	int op1, op2;

	if(GetLeftSubTree(bt)==NULL && GetRightSubTree(bt)==NULL)
		return GetData(bt);

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch(GetData(bt))
	{
	case '+':
		return op1+op2;
	case '-':
		return op1-op2;
	case '*':
		return op1*op2;
	case '/':
		return op1/op2;
	}

	return 0;
}

void ShowNodeData(int data)
{
	if(0<=data && data<=9)
		printf("%d ", data);
	else
		printf("%c ", data);
}

void ShowPrefixTypeExp(BTreeNode * bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode * bt)
{
	// 다음 함수를 사용하는 것이 아닌 새로 생성하는 것
	// InorderTraverse(bt, ShowNodeData);

	// 주어지는 수식은 "12+7*" 후위
	// 수식 표기법은
	// 				*
	// 		+				7
	// 1		2
	// 1+2*7
	// 목표는 ((1+2)*7) 중위

	if(bt == NULL){
		return;
	}

	// 중위 순회는 bt를 기준으로 좌 중 우 순서로 확인?
	// ???? 연산자 앞에 피연산자가 하나만 있을수 있나??? 
	// ???? 왜 or 연산이지? ????
	// !!!! && 연산자로도 정상동작한다. 차이는? !!!!
	if(bt->left != NULL || bt->right != NULL){
	// if(bt->left != NULL && bt->right != NULL){
		printf("(");
	}
	
	// 재귀
	// 피연산자, 연산자 출력
	ShowInfixTypeExp(bt->left);
	ShowNodeData(bt->data);
	ShowInfixTypeExp(bt->right);

	// 
	if(bt->left != NULL || bt->right != NULL){
	// if(bt->left != NULL && bt->right != NULL){
		printf(")");
	}

} 

void ShowPostfixTypeExp(BTreeNode * bt)
{
	PostorderTraverse(bt, ShowNodeData);
}