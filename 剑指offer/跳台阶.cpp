/*
Author: Catnip
Date: 2020/01/28
From: 剑指offer
Link: https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1
*/

/* Q
一只青蛙一次可以跳上1级台阶，也可以跳上2级。
求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*/

/* A
本质上是一个斐波那契数列
	   | 1, (n=1)
f(n) = | 2, (n=2)
	   | f(n-1)+f(n-2) ,(n>2,n为整数)
*/

#include<iostream>
#include<vector>
using namespace std;

// 法1：递归版
int jumpFloor1(int number) {
	if (number <= 2)
		return number;
	return jumpFloor1(number - 1) + jumpFloor1(number - 2);
}

// 法2：优化递归、优化存储
int jumpFloor2(int number) {
	if (number <= 2)
		return number;
	int one = 1, two = 2, sum = 3;
	for (int i = 3; i <= number; i++) {
		sum = two + one;
		one = two;
		two = sum;
	}
	return sum;
}