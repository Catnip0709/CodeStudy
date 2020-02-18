/*
Author: Catnip
Date: 2020/02/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/ff05d44dfdb04e1d83bdbdab320efbcb?tpId=13&tqId=11211&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
请实现一个函数，用来判断一颗二叉树是不是对称的。
注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
*/

/* A
递归判断
*/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool symmetrical(TreeNode* left, TreeNode* right) {
	if (left == NULL && right == NULL)
		return true;
	if ((left == NULL && right != NULL) || (left != NULL && right == NULL))
		return false;
	if (left->val != right->val)
		return false;
	return symmetrical(left->left, right->right) && symmetrical(left->right, right->left);
}
bool isSymmetrical(TreeNode* pRoot) {
	if (pRoot == NULL)
		return true;
	return symmetrical(pRoot->left, pRoot->right);
}