/*
Author: Catnip
Date: 2020/01/28
From: 剑指offer
Link: https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
给定一个double类型的浮点数base，和int类型的整数exponent。
求base的exponent次方。
保证base和exponent不同时为0
*/

/* A
快速幂：快速算底数的n次幂，时间复杂度为 O(log₂N)
实现示例：11的二进制是1011 = 2^3 + 2^1 + 2^0，则a^11 = a^(2^3 + 2^1 + 2^0)
*/

#include<iostream>
using namespace std;

double Power(double base, int exponent) {
	if (exponent == 0) // 指数 = 0
		return 1;
	if (exponent < 0) { //指数 < 0
		//指数<0时，底数不能为0
		if (base == 0) {
			cout << "分母不能为0" << endl;
            return -1;
		}
		base = 1 / base;
		exponent = -exponent;
	}
	//指数 > 0
	double res = 1, curr = base;
	while (exponent != 0) {
		if ((exponent & 1) == 1)
			res *= curr;
		curr *= curr;// 翻倍
		exponent >>= 1;// 右移一位
	}
	return exponent >= 0 ? res : (1 / res);
}