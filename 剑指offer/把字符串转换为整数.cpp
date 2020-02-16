/*
Author: Catnip
Date: 2020/02/16
From: 剑指offer
Link: https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&tqId=11202&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

#include<iostream>
using namespace std;

int StrToInt(string str) {
    int n = str.size(), s = 1;
    long long res = 0;
	if (!n) {
		return 0;
	}
	if (str[0] == '-') {
		s = -1;
	}

	int i = (str[0] == '-' || str[0] == '+') ? 1 : 0;
    for (; i < n; ++i) {
		if (!('0' <= str[i] && str[i] <= '9')) {
			return 0;
		}
		//res = res * 10 + str[i] - '0';
		//(res << 1) + (res << 3) = res * 2 + res * 8 = res * 10，考虑位运算比乘法效率稍高一些
        res = (res << 1) + (res << 3) + (str[i] & 0xf);
    }
	// 溢出判断
	if (!(res * s >= -2147483648 && res * s <= 2147483647)) { //int [-2^31,2^31-1]
		return 0;
	}

    return res * s;
}