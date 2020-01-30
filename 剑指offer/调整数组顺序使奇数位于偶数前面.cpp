/*
Author: Catnip
Date: 2020/01/30
From: 剑指offer
Link: https://www.nowcoder.com/practice/beb5aa231adc45b2a5dcc5b62c93f593?tpId=13&tqId=11166&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个整数数组
实现一个函数来调整该数组中数字的顺序
使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分
并保证奇数和奇数，偶数和偶数之间的相对位置不变。
*/

#include<iostream>
#include<vector>
using namespace std;

void reOrderArray(vector<int>& array1){
	int pos = 0;
	for (int i = 0; i < array1.size(); ++i){
		if (array1[i] % 2 == 1) { //是奇数
			int temp = array1[i];
			//从pos到i的数都往后挪
			for (int j = i; j > pos; --j) {
				array1[j] = array1[j - 1];
			}
			array1[pos] = temp;
			pos++;
		}
	}
}