/*
Author: Catnip
Date: 2020/02/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef?tpId=13&tqId=11209&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
在一个排序的链表中，存在重复的结点
请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

/* A
1、首先添加一个头节点，以方便碰到第一个和第二个节点就相同的情况，避免单独讨论
2、设置pre last 指针，pre指针指向当前确定不重复的那个节点，而last指针相当于工作指针，一直往后面搜索。
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

ListNode* deleteDuplication(ListNode* pHead) {
    if (pHead == NULL || pHead->next == NULL) { 
        return pHead; 
    }
    //1、首先添加一个头节点，以方便碰到第一个和第二个节点就相同的情况
    ListNode* Head = new ListNode(0);
    Head->next = pHead;

    //2、设置pre last 指针，pre指针指向当前确定不重复的那个节点，而last指针相当于工作指针，一直往后面搜索。
    ListNode* pre = Head;
    ListNode* last = Head->next;
    while (last != NULL) {
        if (last->next != NULL && last->val == last->next->val) {
            // 找到最后的一个相同节点
            while (last->next != NULL && last->val == last->next->val) {
                last = last->next;
            }
            pre->next = last->next;
            last = last->next;
        }
        else {
            pre = pre->next;
            last = last->next;
        }
    }
    return Head->next;
}