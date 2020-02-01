/*
Author: Catnip
Date: 2020/02/01
From: 剑指offer
Link: https://www.nowcoder.com/practice/4c776177d2c04c2494f2555c9fcc1e49?tpId=13&tqId=11173&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。
*/

/* A
用一个栈data保存数据，用另外一个栈min保存依次入栈最小的数
比如，data中依次入栈5, 4, 3, 8, 10, 11, 12, 1
	  则min依次入栈 5, 4, 3，no,no, no, no, 1
*/

#include<iostream>
#include<stack>
using namespace std;

stack<int> mainStack, minStack;

void push(int value) {
	mainStack.push(value);
	if (minStack.empty() || value <= minStack.top()) {
		minStack.push(value);
	}
}
void pop() {
	if (minStack.top() == mainStack.top()) {
		minStack.pop();
	}
	mainStack.pop();
}
int top() {
	return mainStack.top();
}
int min() {
	return minStack.top();
}
