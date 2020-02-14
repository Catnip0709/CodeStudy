/*
Author: Catnip
Date: 2020/02/14
From: 剑指offer
Link: https://www.nowcoder.com/practice/6ab1d9a29e88450685099d45c9e31e46?tpId=13&tqId=11189&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入两个链表，找出它们的第一个公共结点。
（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）
*/

/* A
长度相同有公共结点，第一次就遍历到；没有公共结点，走到尾部NULL相遇，返回NULL
长度不同有公共结点，第一遍差值就出来了，第二遍一起到公共结点；没有公共结点，一起到结尾NULL。
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

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
	ListNode* p1 = pHead1, * p2 = pHead2;
	while (p1 != p2) {
		p1 = (p1 == NULL ? pHead2 : p1->next);
		p2 = (p2 == NULL ? pHead1 : p2->next);
	}
	return p1;
}