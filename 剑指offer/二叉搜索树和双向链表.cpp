/*
Author: Catnip
Date: 2020/02/05
From: 剑指offer
Link: https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
要求不能创建任何新的结点，只能调整树中结点指针的指向。
*/

/* A
利用中序遍历的思想，加一个bool判断
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

TreeNode* Convert(TreeNode* pRootOfTree) {
    if (pRootOfTree == NULL)
        return NULL;
    stack<TreeNode*> stack;
    TreeNode* p = pRootOfTree;
    TreeNode* pre = NULL;// 用于保存中序遍历序列的上一节点
    bool isFirst = true;
    while (p != NULL || !stack.empty()) {
        while (p != NULL) {
            stack.push(p);
            p = p->left;
        }
        p = stack.top();
        stack.pop();
        if (isFirst) {
            pRootOfTree = p;// 将中序遍历序列中的第一个节点记为root
            pre = pRootOfTree;
            isFirst = false;
        }
        else {
            pre->right = p;
            p->left = pre;
            pre = p;
        }
        p = p->right;
    }
    return pRootOfTree;
}

TreeNode* Convert2(TreeNode* pRootOfTree) {
    if (pRootOfTree == NULL)
        return NULL;
    if (pRootOfTree->left == NULL && pRootOfTree->right == NULL)
        return pRootOfTree;

    // 1.将左子树构造成双链表，并返回链表头节点
    TreeNode* left = Convert2(pRootOfTree->left);
    TreeNode* p = left;
    // 2.定位至左子树双链表最后一个节点
    while (p != NULL && p->right != NULL) {
        p = p->right;
    }
    // 3.如果左子树链表不为空的话，将当前root追加到左子树链表
    if (left != NULL) {
        p->right = pRootOfTree;
        pRootOfTree->left = p;
    }
    // 4.将右子树构造成双链表，并返回链表头节点
    TreeNode* right = Convert2(pRootOfTree->right);
    // 5.如果右子树链表不为空的话，将该链表追加到root节点之后
    if (right != NULL) {
        right->left = pRootOfTree;
        pRootOfTree->right = right;
    }
    return left != NULL ? left : pRootOfTree;
}