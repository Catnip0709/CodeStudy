/*
Author: Catnip
Date: 2020/02/16
From: 剑指offer
Link: https://www.nowcoder.com/practice/59ac416b4b944300b617d4f7f111b215?tpId=13&tqId=11201&tPage=3&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、*、/四则运算符号。
*/

/* A
以5 + 7 = 12为例
【十进制】三步走
第一步：相加各位的值，不算进位，得到2。
第二步：计算进位值，得到10. 如果这一步的进位值为0，那么第一步得到的值就是最终结果。
第三步：重复上述两步，只是相加的值变成上述两步的得到的结果2和10，得到12。

【二进制】 5 = 101，7 = 111
第一步：相加各位的值，不算进位，得到010，二进制每位相加就相当于各位做异或操作，101^111。
第二步：计算进位值，得到1010，相当于各位做与操作得到101，再向左移一位得到1010，(101&111)<<1。
第三步：重复上述两步，各位相加 010^1010=1000，进位值为100=(010&1010)<<1。     
继续重复上述两步：1000^100 = 1100，进位值为0，跳出循环，1100为最终结果。
*/

#include<iostream>
using namespace std;

int Add(int num1, int num2) {
	while (num2 != 0) {
		int temp = num1 ^ num2;
		num2 = (num1 & num2) << 1;
		num1 = temp;
	}
	return num1;
}