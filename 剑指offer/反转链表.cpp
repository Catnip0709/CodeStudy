/*
Author: Catnip
Date: 2020/01/30
From: 剑指offer
Link: https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca?tpId=13&tqId=11168&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个链表，反转链表后，输出新链表的表头。
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

ListNode* ReverseList(ListNode* pHead) {
	if (pHead == NULL)
		return NULL;
	ListNode* left = pHead;
	ListNode* right = pHead->next;

	while (right != NULL)
	{
		pHead->next = right->next;
		right->next = left;
		left = right;
		right = pHead->next;
	}
	return left;
}