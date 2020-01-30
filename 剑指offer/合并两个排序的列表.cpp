/*
Author: Catnip
Date: 2020/01/30
From: 剑指offer
Link: https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337?tpId=13&tqId=11169&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入两个单调递增的链表，输出两个链表合成后的链表
需要合成后的链表满足单调不减规则。
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

ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
	//新建一个头节点，用来存合并的链表。
	ListNode* head = new ListNode(-1);
	head->next = NULL;
	ListNode* root = head;

	while (pHead1 != NULL && pHead2 != NULL) {
		if (pHead1->val < pHead2->val) {
			head->next = pHead1;
			head = pHead1;
			pHead1 = pHead1->next;
		}
		else {
			head->next = pHead2;
			head = pHead2;
			pHead2 = pHead2->next;
		}
	}

	//把未结束的链表连接到合并后的链表尾部
	if (pHead1 != NULL) {
		head->next = pHead1;
	}
	if (pHead2 != NULL) {
		head->next = pHead2;
	}
	return root->next;
}