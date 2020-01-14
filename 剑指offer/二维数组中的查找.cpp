/*
Author: Catnip
Date: 2020/01/14
From: 剑指offer 
Link: https://www.nowcoder.com/practice/abc3fe2ce8e146608e868a70efebf62e?tpId=13&tqId=11154&tPage=1&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
在一个二维数组中（每个一维数组的长度相同）
每一行都按照从左到右递增的顺序排序。
每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/

/* A
矩阵是有序的，从左下角来看，向上数字递减，向右数字递增。
因此从左下角开始查找，要查找数字比左下角数字小时，上移。
*/

/* Key
关键是【每一行】和【每一列】
每次移动都会更新所谓的【左下角】数字
*/

#include <iostream>
#include <vector>
using namespace std;

bool Find(int target, vector<vector<int> > array) {
	int rows = array.size();
	if (rows == 0)
		return false;
	int cols = array[0].size();
	if (cols == 0)
		return false;

	int curRow = rows - 1;
	int curCol = 0;
	while (curRow > -1 && curCol < cols) {
		int myTarget = array[curRow][curCol];
		if (target == myTarget)
			return true;
		if (target < myTarget)
		{
			curRow--;
			continue;
		}
		if (target > myTarget)
		{
			curCol++;
			continue;
		}
	}
	return false;
}

int main() {
	vector<vector<int>> test = { {1,5,7},{2,6,8},{3,7,9} };
	cout << Find(7, test) << endl;
}

