/*
Author: Catnip
Date: 2020/01/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13&tqId=11157&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。
假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}
则重建二叉树并返回。
*/

/* A
递归构造法
不断拆分左右子树，构造左右子树各自的先序、中序遍历数组
*/

#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
	TreeNode* root = new TreeNode(-1);
	if (!pre.empty()) {
		root->val = pre[0];
	}
	else {
		return NULL;
	}
	vector<int> vin_left, vin_right, pre_left, pre_right;
	if (!vin.empty()) {
		int i = 1;
		for (i = 0; i < vin.size(); ++i) {
			if (vin[i] == root->val)
				break;
			vin_left.push_back(vin[i]);
		}
		for (int j = 1; j <= i; ++j) {
			pre_left.push_back(pre[j]);
		}
		for (int j = i + 1; j < pre.size(); ++j) {
			pre_right.push_back(pre[j]);
		}

		for (++i; i < vin.size(); ++i) {
			vin_right.push_back(vin[i]);
		}

		if (vin_left.empty()) {
			root->left = NULL;
		}
		else {
			root->left = reConstructBinaryTree(pre_left, vin_left);
		}
		if (vin_right.empty()) {
			root->right = NULL;
		}
		else {
			root->right = reConstructBinaryTree(pre_right, vin_right);
		}
	}
	else { //中序为空，root左右均为NULL
		root->left = NULL;
		root->right = NULL;
	}
	return root;
}