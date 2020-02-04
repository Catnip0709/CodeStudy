/*
Author: Catnip
Date: 2020/02/04
From: 剑指offer
Link: https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个复杂链表
每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点
返回结果为复制后复杂链表的head。
（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）
*/

/* A
1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
2、遍历链表，A1->random = A->random->next;
3、将链表拆分成原链表和复制后的链表
*/

#include<iostream>
using namespace std;

struct RandomListNode {
	int label;
	struct RandomListNode* next, * random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {
	}
};
RandomListNode* Clone(RandomListNode* pHead){
	if (!pHead) {
		return NULL;
	}
	//1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
	RandomListNode* pCur = pHead;
	while (pCur) {
		RandomListNode* newNode = new RandomListNode(pCur->label+10);
		newNode->next = pCur->next;
		pCur->next = newNode;
		pCur = newNode->next;
	}

	//2、遍历链表，A1->random = A->random->next;
	pCur = pHead;
	while (pCur) {
		if (pCur->random) {
			if (pCur->random == pCur) { // random指向本身
				pCur->next->random = pCur->next;
			}
			else { //random指向其他节点，注意等号右边要next，换成新的
				pCur->next->random = pCur->random->next;
			}
		}
		pCur = pCur->next->next;
	}

	//3、将链表拆分成原链表和复制后的链表
	RandomListNode* pClone = pHead->next;
	pCur = pClone;
	while (pCur->next != NULL) {
		pCur->next = pCur->next->next;
		pCur = pCur->next;
	}
	return pClone;
}

int main() {
	//{1,2,3,4,5,3,5,#,2,#}
	RandomListNode* a1 = new RandomListNode(1);
	RandomListNode* a2 = new RandomListNode(2);
	RandomListNode* a3 = new RandomListNode(3);
	RandomListNode* a4 = new RandomListNode(4);
	RandomListNode* a5 = new RandomListNode(5);

	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;

	a1->random = a3;
	a2->random = a5;
	a4->random = a2;

	RandomListNode* a = Clone(a1);
	return 0;
}