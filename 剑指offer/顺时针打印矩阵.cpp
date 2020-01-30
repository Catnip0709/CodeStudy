/*
Author: Catnip
Date: 2020/01/30
From: 剑指offer
Link: https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个矩阵
按照从外向里以顺时针的顺序依次打印出每一个数字
例如，如果输入如下4 X 4矩阵
1  2  3  4 
5  6  7  8 
9  10 11 12 
13 14 15 16
则依次打印出数字
1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.
*/

/* A
用左上和右下的坐标定位出一次要旋转打印的数据，一次旋转打印结束后，往对角分别前进和后退一个单位。
需要加入条件判断，防止出现单行或者单列的情况。
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
	int row = matrix.size();
	int col = matrix[0].size();
	vector<int> res;

	// 输入的二维数组非法，返回空的数组
	if (row == 0 || col == 0)  
		return res;

	// 定义四个关键变量，表示左上和右下的打印范围
	int left = 0, top = 0, right = col - 1, bottom = row - 1;
	while (left <= right && top <= bottom) {
		for (int i = left; i <= right; ++i) {  // 从左到右
			res.push_back(matrix[top][i]);
		}
		for (int i = top + 1; i <= bottom; ++i) { // 从上到下
			res.push_back(matrix[i][right]);
		}
		if (top != bottom) {
			for (int i = right - 1; i >= left; --i) { // 从右到左
				res.push_back(matrix[bottom][i]);
			}
		}
		if (left != right)
			for (int i = bottom - 1; i > top; --i) { // 从下到上
				res.push_back(matrix[i][left]);
			}
		left++, top++, right--, bottom--;
	}
	return res;
}
