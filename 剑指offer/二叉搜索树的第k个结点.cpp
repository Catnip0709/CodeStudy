/*
Author: Catnip
Date: 2020/02/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a?tpId=13&tqId=11215&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
给定一棵二叉搜索树，请找出其中的第k小的结点。
例如(5, 3, 7, 2, 4, 6, 8)中，按结点数值大小顺序第三小结点的值为4。
*/

/* A
二叉搜索树按照中序遍历的顺序打印出来正好就是排序好的顺序。
所以按照中序遍历顺序找到第k个结点就是结果。
*/

#include<iostream>
#include<stack>
using namespace std; 

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* KthNode(TreeNode* pRoot, int k) {
	if (!pRoot || k <= 0) {
		return NULL;
	}
	TreeNode* nowNode = pRoot;
	stack<TreeNode*> sta;
	int count = 0;
	while (nowNode || !sta.empty()) {
		while (nowNode) {
			sta.push(nowNode);
			nowNode = nowNode->left;
		}
		if (!sta.empty()) {
			nowNode = sta.top();
			if (++count == k) {
				return nowNode;
			}
			sta.pop();
			nowNode = nowNode->right;
		}
	}

	return NULL;
}