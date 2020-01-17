/*
Author: Catnip
Date: 2020/01/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?tpId=13&tqId=11155&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
请实现一个函数
将一个字符串中的每个空格替换成“%20”。
例如，当字符串为We Are Happy
则经过替换之后的字符串为We%20Are%20Happy
*/

/* A
1、从左向右遍历算出所有空格的数量
2、计算出替换后的字符串总长度
3、从右向左替换
*/

/* Key
计算好总长度后，从右向左，每个空格后面的字符只需要移动一次。
若从左向右，当遇到第一个空格时，要移动第一个空格后所有的字符一次；当遇到第二个空格时，要移动第二个空格后所有的字符一次；
以此类推。从左向右总的移动次数会更多。
*/

#include<iostream>
#include<string>
using namespace std;

int countBlackSpaceNum(char* str, int length) {
	int num = 0;
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ') {
			num++;
		}
	}
	return num;
}

void replaceSpace(char* str, int length) {
	if (str == NULL || length == 0) {
		return;
	}
	int blackNum = countBlackSpaceNum(str, length);
	int newLength = length + blackNum * 2;
	str[newLength] = '\0';

	int left = length - 1;
	int right = newLength - 1;
	while (left != -1) {
		if (str[left] != ' ') {
			str[right] = str[left];
			right -= 1;
		} else{
			str[right] = '0';
			str[right - 1] = '2';
			str[right - 2] = '%';
			right -= 3;
		}
		left -= 1;
	}
	cout << str << endl;
}

int main() {
	char t[200] = "We Are Happy";
	char* test = t;
	replaceSpace(test, 13);
}