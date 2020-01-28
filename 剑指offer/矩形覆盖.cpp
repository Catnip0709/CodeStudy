/*
Author: Catnip
Date: 2020/01/28
From: 剑指offer
Link: https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?tpId=13&tqId=11163&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
*/

/* A
1）n = 1时，大矩形是日字型，只有一种摆法，return 1
2）n = 2时，大矩形是田字型，有两种摆法，return 2
3) n = 3时，可以分割为日+田or田+日，因此return f(3-1)+f(3-2)
4) 可以看出来是一个斐波那契数列
*/

#include<iostream>
using namespace std;

// 优化递归、优化存储
int rectCover(int number) {
	if (number <= 2)
		return number;
	int sum = 0;
	int one = 1, two = 2;
	for (int i = 3; i <= number; i++) {
		sum = two + one;
		one = two;
		two = sum;
	}
	return sum;
}