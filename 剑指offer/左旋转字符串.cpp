/*
Author: Catnip
Date: 2020/02/15
From: 剑指offer
Link: https://www.nowcoder.com/practice/12d959b108cb42b1ab72cef4d36af5ec?tpId=13&tqId=11196&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
汇编语言中有一种移位指令叫做循环左移（ROL），现在用字符串模拟这个指令的运算结果。
对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
*/

#include<iostream>
using namespace std;

string LeftRotateString(string str, int n){
	if (str.empty() || (n %= str.size()) == 0) {
		return str;
	}

	string help;
	for (int i = 0; i < n; ++i) {
		help.push_back(str[i]);
	}

	for (int i = 0; i < str.size() - n; ++i) {
		str[i] = str[i + n];
	}

	int pos = -1;
	for (int i = str.size() - n; i < str.size(); ++i){
		str[i] = help[++pos];
	}
	return str;
}