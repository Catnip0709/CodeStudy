/*
Author: Catnip
Date: 2020/01/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/d0267f7f55b3412ba93bd35cfa8e8035?tpId=13&tqId=11156&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个链表，按链表从尾到头的顺序返回一个ArrayList。
*/

/* A
法1、栈
法2、计算出替换后的字符串总长度
法3、递归
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
	val(x), next(NULL) {
	}
};

// 压栈法解决
vector<int> printListFromTailToHead(ListNode* head) {
	vector<int> result;
	if (head == NULL) {
		return result;
	}

	stack<ListNode *> help;
	while (head != NULL) {
		help.push(head);
		head = head->next;
	}
	while (help.empty() == false) {
		result.push_back(help.top()->val);
		help.pop();
	}
	return result;
}