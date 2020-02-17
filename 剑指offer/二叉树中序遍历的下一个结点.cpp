/*
Author: Catnip
Date: 2020/02/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e?tpId=13&tqId=11210&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
*/

/* A
中序遍历：左根右
	    A
	 /	    \
   B	      C
 /	 \	   /	\
 D	  E	  F		 G
  \	 / \   \	/ \
   H I	J   K  L   M
  /
 N

结合图，我们可发现分成两大类：
1、有右子树的，那么下个结点就是右子树最左边的点（eg：D，B，E，A，C，G）
2、没有右子树的，也可以分成两类
   (a)是父节点左孩子（eg：N，I，L） ，那么父节点就是下一个节点
   (b)是父节点的右孩子（eg：H，J，K，M）找他的父节点的父节点的父节点...直到当前结点是其父节点的左孩子位置。
   如果没有eg：M，那么他就是尾节点。
*/

#include<iostream>
using namespace std;

struct TreeLinkNode {
	int val;
	struct TreeLinkNode* left;
	struct TreeLinkNode* right;
	struct TreeLinkNode* next; //指向父节点
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

	}
};

TreeLinkNode * GetNext(TreeLinkNode * pNode) {
    //1.二叉树为空，则返回空；
    if (pNode == NULL) {
        return NULL;
    }
    //2.节点右孩子存在，则设置一个指针从该节点的右孩子出发
    //一直沿着指向左子结点的指针找到的叶子节点即为下一个节点；
    if (pNode->right != NULL) {
        pNode = pNode->right;
        while (pNode->left != NULL)
            pNode = pNode->left;
        return pNode;
    }

    //3.节点没有右孩子不是根节点。
    //如果该节点是其父节点的左孩子，则返回父节点；
    //否则继续向上遍历其父节点的父节点，重复之前的判断，返回结果。
    while (pNode->next != NULL) {
        TreeLinkNode* proot = pNode->next;
        if (proot->left == pNode) {
            return proot;
        }
        pNode = pNode->next;
    }
    return NULL;
}