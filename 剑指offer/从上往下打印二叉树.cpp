/*
Author: Catnip
Date: 2020/02/01
From: 剑指offer
Link: https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701?tpId=13&tqId=11175&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
从上往下打印出二叉树的每个节点，同层节点从左至右打印。
*/

/* A
借助队列实现
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

vector<int> PrintFromTopToBottom(TreeNode* root) {
	vector<int> result;
	if (root == NULL)
		return result;
	TreeNode* now = root;
	queue<TreeNode*> que;
	que.push(now);
	while (!que.empty())
	{
		now = que.front();
		result.push_back(now->val);
		que.pop();
		if (now->left != NULL)
			que.push(now->left);
		if (now->right != NULL)
			que.push(now->right);
	}
	return result;
}