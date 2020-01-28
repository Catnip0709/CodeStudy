/*
Author: Catnip
Date: 2020/01/28
From: 剑指offer
Link: https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?tpId=13&tqId=11160&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking&tPage=1*/

/* Q
大家都知道斐波那契数列。
现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
*/

/* A
斐波那契数列的标准公式为：F(0) = 0, F(1) = 1，F(2) = 1, F(n) = F(n-1) + F(n-2)（n>=3，n∈N*）
法1：递归。时间复杂度：O(2^n)，空间复杂度：O(1)
法2：优化递归。把每次算出的结果存起来，从而不用每次都递归到底。时间复杂度 = 空间复杂度=O(n)
法3：优化存储。法2中其实每次就用到了最近的两个数，所以我们可以只存储最近的两个数。sum = 第 n 项，one = 第 n-1 项，two = 第 n-2 项。时间复杂度：O(n)，空间复杂度：O(1)
*/

#include<iostream>
#include<vector>
using namespace std;

// 法1：递归版
int Fibonacci1(int n) {
	if (n <= 1)
		return n;
	return Fibonacci1(n - 1) + Fibonacci1(n - 2);
}
// 法2：优化递归
int Fibonacci2(int n) {
	if (n <= 1)
		return n;
	vector<int> save;
	save.push_back(1);
	save.push_back(1);
	for (int i = 2; i < n; ++i) {
		save.push_back(save[i - 1] + save[i - 2]);
	}
	return save[save.size() - 1];
}
// 法3：优化存储。
int Fibonacci3(int n) {
	if (n <= 1)
		return n;
	int sum = 0;
	int two = 0;
	int one = 1;
	for (int i = 2; i <= n; i++) {
		sum = two + one;
		two = one;
		one = sum;
	}
	return sum;
}