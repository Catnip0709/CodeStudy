/*
Author: Catnip
Date: 2020/02/01
From: 剑指offer
Link: https://www.nowcoder.com/practice/d77d11405cc7470d82554cb392585106?tpId=13&tqId=11174&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/

/* Q
输入两个整数序列
第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序
序列4,5,3,2,1是该压栈序列对应的一个弹出序列
但4,3,5,1,2就不可能是该压栈序列的弹出序列
（注意：这两个序列的长度是相等的）
*/

/* A
入栈1,2,3,4,5
出栈4,5,3,2,1
首先1入辅助栈，此时栈顶1≠4，继续入栈2
此时栈顶2≠4，继续入栈3
此时栈顶3≠4，继续入栈4
此时栈顶4＝4，出栈4，弹出序列向后一位，此时为5，辅助栈里面是1,2,3
此时栈顶3≠5，继续入栈5
此时栈顶5=5，出栈5，弹出序列向后一位，此时为3，辅助栈里面是1,2,3
….
依次执行，最后辅助栈为空。
如果不为空说明弹出序列不是该栈的弹出顺序。
*/

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
	if (pushV.empty() || popV.empty())
		return false;
	stack<int> helpStack;
	for (int pushPoint = 0, popPoint = 0; pushPoint < pushV.size();) {
		helpStack.push(pushV[pushPoint++]);
		while (popPoint < popV.size() && helpStack.top() == popV[popPoint]) {
			helpStack.pop();
			popPoint++;
		}
	}
	return helpStack.empty();
}
int main() {
	vector<int> pushV = { 1,2,3,4,5 };
	vector<int> popV = { 4,5,3,2,1 };
	cout << IsPopOrder(pushV, popV) << endl;
}