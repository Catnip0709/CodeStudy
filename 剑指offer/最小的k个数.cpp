/*
Author: Catnip
Date: 2020/02/12
From: 剑指offer
Link: https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf?tpId=13&tqId=11182&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入n个整数，找出其中最小的K个数。
例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
*/

/* A
利用C++的STL priority_queue 建立小根堆
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
	if (k == input.size()) {
		return input;
	}

	vector<int> result;
	if (k == 0 || input.empty() || k > input.size()) {
		return result;
	}
	
	priority_queue<int, vector<int>, greater<int> > temp; //建小根堆，堆顶是最小的数字
	for (int i = 0; i < input.size(); i++) {
		temp.push(input[i]);
	}
	for (int i = 0; i < k; i++) {
		result.push_back(temp.top());
		temp.pop();
	}
	return result;
}