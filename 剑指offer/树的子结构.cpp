/*
Author: Catnip
Date: 2020/01/30
From: 剑指offer
Link: https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88?tpId=13&tqId=11170&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入两棵二叉树A，B，判断B是不是A的子结构。
（ps：我们约定空树不是任意一个树的子结构）
*/

#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSubtree(TreeNode* pRootA, TreeNode* pRootB) {
	if (pRootB == NULL) return true;
	if (pRootA == NULL) return false;
	if (pRootB->val != pRootA->val) return false;

	return isSubtree(pRootA->left, pRootB->left) && isSubtree(pRootA->right, pRootB->right);
}
bool HasSubtree(TreeNode* pRootA, TreeNode* pRootB)
{
	if (pRootA == NULL || pRootB == NULL) return false;

	return isSubtree(pRootA, pRootB)        ||
		   HasSubtree(pRootA->left, pRootB) ||
		   HasSubtree(pRootA->right, pRootB);
}