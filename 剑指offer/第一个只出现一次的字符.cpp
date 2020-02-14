/*
Author: Catnip
Date: 2020/02/14
From: 剑指offer
Link: https://www.nowcoder.com/practice/1c82e8cf713b4bbeb2a5b31cf5b0417c?tpId=13&tqId=11187&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
在一个字符串(0<=字符串长度<=10000，全部由字母组成)中
找到第一个只出现一次的字符,并返回它的位置
如果没有则返回 -1（需要区分大小写）
*/

/* A
使用map
*/

#include<iostream>
#include<map>
using namespace std;

int FirstNotRepeatingChar(string str) {
	map<char, int> mp;
	for (int i = 0; i < str.size(); ++i) {
		mp[str[i]]++;
	}
	for (int i = 0; i < str.size(); ++i) {
		if (mp[str[i]] == 1) {
			return i;
		}
	}
	return -1;
}