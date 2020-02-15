/*
Author: Catnip
Date: 2020/02/15
From: 剑指offer
Link: https://www.nowcoder.com/practice/390da4f7a00f44bea7c2f3d19491311b?tpId=13&tqId=11195&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输出所有和为S的连续正数序列。
序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

/* A
数列满足递增，设两个头尾两个指针i和j，
若ai + aj == sum，就是答案（相差越远乘积越小）
若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
O(n)
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum) {
	int left = 0, right = array.size() - 1;
	vector<int> result;
	while (left <= right) {
		if (array[left] + array[right] == sum) {
			result.push_back(array[left]);
			result.push_back(array[right]);
			return result;
		}
		else if (array[left] + array[right] > sum) {
			right--;
		}
		else {
			left++;
		}
	}
	return result;
}