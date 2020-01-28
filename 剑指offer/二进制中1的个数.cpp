/*
Author: Catnip
Date: 2020/01/28
From: 剑指offer
Link: https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?tpId=13&tqId=11164&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个整数，输出该数二进制表示中1的个数。
其中负数用补码表示。
*/

/* A
普通：用1（1自身左移运算，其实后来就不是1了）和n的每位进行位与，来判断1的个数。
优化：不断把把最右边的一个1变成0，再与自己做与
【优化举例】
一个二进制数1100，从右边数起第三位是处于最右边的一个1。
减去1后，第三位变成0，它后面的两位0变成了1，而前面的1保持不变，因此得到的结果是1011
我们发现减1的结果是：把最右边的一个1开始的所有位都取反了。
这个时候如果我们再把原来的整数和减去1之后的结果做与
则从原来整数最右边一个1那一位开始所有位都会变成0
如1100&1011=1000
也就是说，把一个整数减去1，再和原整数做与运算，会把该整数最右边一个1变成0
那么一个整数的二进制有多少个1，就可以进行多少次这样的操作。
*/

#include<iostream>
using namespace std;

// 普通解法
int NumberOf1_1(int n) {
	int count = 0;
	int flag = 1;
	while (flag != 0) {
		if ((n & flag) != 0) {
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

// 优化解法
int NumberOf1_2(int n) {
	int count = 0;
	while (n != 0) {
		++count;
		n = (n - 1) & n;
	}
	return count;
}