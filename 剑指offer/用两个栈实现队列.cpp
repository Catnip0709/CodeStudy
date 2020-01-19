/*
Author: Catnip
Date: 2020/01/19
From: 剑指offer
Link: https://www.nowcoder.com/practice/54275ddae22f475981afa2244dd448c6?tpId=13&tqId=11158&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1
*/

/* Q
用两个栈来实现一个队列，完成队列的Push和Pop操作。
队列中的元素为int类型。
*/

/* A
栈1用于压入，栈2用于弹出
*/

#include<iostream>
#include<stack>
using namespace std;

stack<int> stack1, stack2;
void push(int node) {
	stack1.push(node);
}
int pop() {
	int result;
	if (stack2.empty()) {
		while (!stack1.empty()) {
			result = stack1.top();
			stack2.push(result);
			stack1.pop();
		}
	}
	result = stack2.top();
	stack2.pop();
	return result;
}