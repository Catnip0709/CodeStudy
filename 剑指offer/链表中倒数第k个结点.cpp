/*
Author: Catnip
Date: 2020/01/30
From: 剑指offer
Link: https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a?tpId=13&tqId=11167&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个链表，输出该链表中倒数第k个结点。
*/

/* A
设置2个指针，first领先second k-1个节点
两个指针同时往前走
当first走到最后一个节点时，second指向目的节点
*/

#include<iostream>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
	if (pListHead == NULL) {
		return NULL;
	}
	ListNode* first = pListHead;
	ListNode* second = pListHead;
	
	//设置first指针领先second k-1步
	for (int i = 0; i < k - 1; i++) {
		if (first->next == NULL) {
			return NULL;
		}
		first = first->next;
	}

	//两个指针同时往前走，直到first指向最后一个节点
	while (first->next != NULL) {
		first = first->next;
		second = second->next;
	}
	return second;
}