/*
Author: Catnip
Date: 2020/02/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/00de97733b8e4f97a3fb5c680ee10720?tpId=13&tqId=11207&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
请实现一个函数用来找出字符流中第一个只出现一次的字符。
例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。
当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
如果当前字符流没有存在出现一次的字符，返回#字符。
*/

/* A
时间复杂度O（1），空间复杂度O（n）
1、用一个128大小的数组统计每个字符出现的次数
2、用一个队列，如果第一次遇到ch字符，则插入队列；其他情况不在插入
3、求解第一个出现的字符，判断队首元素是否只出现一次，如果是直接返回，否则删除
继续第3步骤

分析：可以看出相同的字符只被插入一次，最多push128个，同时大多数情况会直接返回队首。
*/

#include<iostream>
#include<queue>
using namespace std;

queue<char> inputData;
int countTime[128];

void Insert(char ch)
{
    ++countTime[ch - '\0'];
	if (countTime[ch - '\0'] == 1) {
		inputData.push(ch);
	}
}

char FirstAppearingOnce()
{
	while (!inputData.empty() && countTime[inputData.front()] >= 2) {
		inputData.pop();
	}
	if (inputData.empty()) {
		return '#';
	}
    return inputData.front();
}
