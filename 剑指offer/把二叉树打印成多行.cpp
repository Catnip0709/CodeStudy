/*
Author: Catnip
Date: 2020/02/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/445c44d982d04483b04a54f298796288?tpId=13&tqId=11213&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
从上到下按层打印二叉树，同一层结点从左至右输出。
每一层输出一行。
*/

/* A
用两个变量oldCount和newCount记录新旧两行的结点个数
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > Print(TreeNode* pRoot) {
	vector<vector<int>> result;
	if (!pRoot) {
		return result;
	}
	TreeNode* first = pRoot;
	queue<TreeNode*> que;
	que.push(first);
	int oldCount = 0, newCount = 1;
	while (!que.empty()) {
		vector<int> tempResult;
		oldCount = newCount;
		newCount = 0;
		while (oldCount > 0) {
			if (que.front()->left) {
				que.push(que.front()->left);
				newCount++;
			}
			if (que.front()->right) {
				que.push(que.front()->right);
				newCount++;
			}
			tempResult.push_back(que.front()->val);
			que.pop();
			oldCount--;
		}
		result.push_back(tempResult);
	}
	return result;
}

int main() {
	TreeNode* n1 = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	n1->left = n2;
	n1->right = n3;
	n2->left = n4;
	n2->right = n5;
	n3->left = n6;
	n3->right = n7;
	n4->left = n8;
	vector<vector<int>> result = Print(n1);
}