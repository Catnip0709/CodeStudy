/*
Author: Catnip
Date: 2020/02/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4?tpId=13&tqId=11208&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
*/

/* A
1、设置快慢指针，假如有环，他们最后一定相遇。
2、两个指针分别从链表头和相遇点继续出发，每次走一步，最后一定相遇于环入口。
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

ListNode* EntryNodeOfLoop(ListNode* pHead) {
    //0个结点
    if (pHead == NULL) {
        return NULL;
    }
    //1个结点
    if (pHead->next == pHead) {
        return pHead;
    }

    //多个结点
    //1、设置快慢指针，假如有环，他们最后一定相遇。
    ListNode* slow = pHead, * fast = pHead;
    ListNode* meet = NULL;
    while (1) {
        if (fast->next != NULL) {
            fast = fast->next; //fast的第一步
        }
        else {
            return NULL;
        }
        if (fast->next != NULL) {
            fast = fast->next;//fast的第二步
        }
        else {
            return NULL;
        }

        slow = slow->next;

        if (slow == fast) {
            meet = slow;
            break;
        }
    }

    //2、两个指针分别从链表头和相遇点继续出发，每次走一步，最后一定相遇于环入口。
    ListNode* p1 = pHead;
    ListNode* p2 = meet;
    while (1) {
        if (p1 == p2) {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
}