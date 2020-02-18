/*
Author: Catnip
Date: 2020/02/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0?tpId=13&tqId=11212&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
请实现一个函数按照之字形打印二叉树
即第一行按照从左到右的顺序打印，第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印
其他行以此类推。
*/

/* A
用2个栈相继存储
*/

#include<iostream>
#include<vector>
#include<stack>
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
	stack<TreeNode*> leftToRight;
	stack<TreeNode*> rightToLeft;

	TreeNode* first = pRoot;
	leftToRight.push(first);
	while (!leftToRight.empty() || !rightToLeft.empty()) {
		vector<int> left;
		while (!leftToRight.empty()) {
			if (leftToRight.top()->left) {
				rightToLeft.push(leftToRight.top()->left);
			}
			if (leftToRight.top()->right) {
				rightToLeft.push(leftToRight.top()->right);
			}
			left.push_back(leftToRight.top()->val);
			leftToRight.pop();
		}
		if (!left.empty()) {
			result.push_back(left);
		}

		vector<int> right;
		while (!rightToLeft.empty()) {
			if (rightToLeft.top()->right) {
				leftToRight.push(rightToLeft.top()->right);
			}
			if (rightToLeft.top()->left) {
				leftToRight.push(rightToLeft.top()->left);
			}
			right.push_back(rightToLeft.top()->val);
			rightToLeft.pop();
		}
		if (!right.empty()) {
			result.push_back(right);
		}
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