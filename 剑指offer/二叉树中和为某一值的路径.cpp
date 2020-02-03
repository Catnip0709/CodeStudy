/*
Author: Catnip
Date: 2020/02/03
From: 剑指offer
Link: https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca?tpId=13&tqId=11177&tPage=2&rp=1&ru=%2Fta%2Fcoding-interviews&qru=%2Fta%2Fcoding-interviews%2Fquestion-ranking
*/

/* Q
输入两个整数序列
第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
假设压入栈的所有数字均不相等。
例如序列1,2,3,4,5是某栈的压入顺序
序列4,5,3,2,1是该压栈序列对应的一个弹出序列
但4,3,5,1,2就不可能是该压栈序列的弹出序列
（注意：这两个序列的长度是相等的）
*/

/* A
递归进行深度遍历
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

vector<vector<int>> listAll;
vector<int> list;
vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
    if (root == NULL)
		return listAll;

    list.push_back(root->val);
	expectNumber -= root->val;

	if (expectNumber == 0 && root->left == NULL && root->right == NULL) {
		listAll.push_back(vector<int>(list));
	}
    FindPath(root->left, expectNumber);
    FindPath(root->right, expectNumber);

    list.pop_back(); //移除最后一个元素，深度遍历完一条路径后要回退

    return listAll;
}