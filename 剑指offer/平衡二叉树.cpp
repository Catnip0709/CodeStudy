/*
Author: Catnip
Date: 2020/02/15
From: 剑指offer
Link: https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222?tpId=13&tqId=11192&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
*/

/* A
递归求解，不断深入判断
*/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int TreeDepth(TreeNode* pRoot){
	if (pRoot == NULL) {
		return 0;
	}
	return max(1 + TreeDepth(pRoot->left), 1 + TreeDepth(pRoot->right));
}

bool IsBalanced_Solution(TreeNode* pRoot) {
	if (pRoot == NULL) {
		return true;
	}
	int left_deep = TreeDepth(pRoot->left);
	int right_deep = TreeDepth(pRoot->right);
	int result = left_deep - right_deep;
	if (result > -2 && result < 2) {
		return IsBalanced_Solution(pRoot->left) && IsBalanced_Solution(pRoot->right);
	}
	return false;
}