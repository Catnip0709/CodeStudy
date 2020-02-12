/*
Author: Catnip
Date: 2020/02/12
From: 剑指offer
Link: https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484?tpId=13&tqId=11183&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
在古老的一维模式识别中,常常需要计算连续子向量的最大和
当向量全为正数的时候,问题很好解决。
但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
给一个数组，返回它的最大连续子序列的和(子向量的长度至少是1)
*/

/* A
【动态规划】
F(i)：以array[i]为末尾元素的子数组的和的最大值，子数组的元素的相对位置不变
F(i) = max(F(i-1) + array[i]，array[i])
res：所有子数组的和的最大值
res = max(res，F(i))

如数组[6, -3, -2, 7, -15, 1, 2, 2]
初始状态：F(0)= 6, res = 6
i=1：
	F(1) = max(F(0) - 3, -3) = max(6 - 3, 3) = 3
	res = max(F(1), res) = max(3, 6) = 6
i=2：
	F(2) = max(F(1) - 2, -2）= max(3 - 2, -2) = 1
	res = max(F(2), res) = max(1, 6) = 6
i=3：
	F(3) = max(F(2) + 7, 7) = max(1 + 7, 7) = 8
	res = max(F(2), res）= max(8, 6) = 8
以此类推
最终res的值为8
*/

#include<iostream>
#include<vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array) {
	int Fi = array[0];   //包含array[i]的连续数组最大值
	int res = array[0];  //记录当前所有子数组的和的最大值
	for (int i = 1; i < array.size(); i++) {
		Fi  = max(Fi + array[i], array[i]);
		res = max(Fi, res);
	}
	return res;
}