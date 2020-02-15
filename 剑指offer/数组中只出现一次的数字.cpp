/*
Author: Catnip
Date: 2020/02/15
From: 剑指offer
Link: https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811?tpId=13&tqId=11193&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字。
*/

/* A
异或^：相同为0，不同为1
两个相同数字异或=0，两个不同的数字异或=1，一个数和0异或还是它本身。

当只有一个数出现一次时，我们把数组中所有的数，依次异或运算，最后剩下的就是落单的数，因为成对儿出现的都抵消了。

本题中有2个只出现一次的数字，设为x和y，所有数字依次异或依次，得到是x和y异或的结果，设为z
z的二进制中为1的位，即为x和y各自的二进制中不同的位
假设z的最右位为1，则x和y的二进制的最右位不同

将原数组再次分为2组，分组标准为最右位为0还是为1
相同的数字肯定在同一组中，x和y肯定不在同一组中

在2个组中分别对组内所有的数做异或，每组得到各自的结果
*/

#include<iostream>
#include<vector>
using namespace std;

//找出z值中从右到左第一个1的位置pos
int Find1InZ(int zValue) {
	int help = 1;
	int pos = 1;
	while (1) {
		if (zValue & help) {
			break;
		}
		else {
			help *= 2;
			pos++;
		}
	}
	return pos;
}

void FindNumsAppearOnce(vector<int> data, int* num1, int* num2) {
	if (data.size() == 2) {
		*num1 = data[0];
		*num2 = data[1];
		return;
	}

	//依次异或得到z，z = x ^ y
	int zValue = 0;
	for (int i = 0; i < data.size(); i++) {
		zValue ^= data[i];
	}

	int pos = Find1InZ(zValue);

	//按从右到左的pos位是否为1进行分组
	int help = 1;
	vector<int> group1, group2;
	while (pos > 1) {
		help *= 2;
		pos--;
	}
	for (int i = 0; i < data.size(); i++) {
		if (data[i] & help) {
			group1.push_back(data[i]);
		}
		else{
			group2.push_back(data[i]);
		}
	}

	//两组各自做异或，得到结果
	for (int i = 0; i < group1.size(); i++) {
		*num1 ^= group1[i];
	}
	for (int i = 0; i < group2.size(); i++) {
		*num2 ^= group2[i];
	}

	return;
}

int main() {
	vector<int> a = { 2,4,3,6,3,2,5,5 };
	int num1 = 0, num2 = 0;
	FindNumsAppearOnce(a, &num1, &num2);
	return 0;
}