/*
Author: Catnip
Date: 2020/01/30
From: 剑指offer
Link: https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011?tpId=13&tqId=11171&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
操作给定的二叉树，将其变换为源二叉树的镜像。
二叉树的镜像定义：源二叉树
			8
		   /  \
		  6   10
		 / \  / \
		5  7 9   11
		镜像二叉树
			8
		   /  \
		  10   6
		 / \  / \
		11 9 7   5
*/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void Mirror(TreeNode* pRoot) {
	if (pRoot == NULL)
		return;
	TreeNode* left = pRoot->left;
	TreeNode* right = pRoot->right;

	pRoot->left = right;
	pRoot->right = left;

	if (pRoot->right != NULL)
		Mirror(pRoot->right);
	if (pRoot->left != NULL)
		Mirror(pRoot->left);
}