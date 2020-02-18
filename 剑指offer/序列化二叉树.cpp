/*
Author: Catnip
Date: 2020/02/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/cf7e25aa97c04cc1a68c8f040e71fb84?tpId=13&tqId=11214&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
请实现两个函数，分别用来序列化和反序列化二叉树

【序列化】
把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串
从而使得内存中建立起来的二叉树可以持久保存。
序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改
序列化的结果是一个字符串，序列化时通过#表示空节点，以！表示一个结点值的结束（value!）。

【反序列化】
根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
*/

/* A
【序列化】层次遍历，统计每一层应该有的结点个数，补充空节点
【反序列化】解析序列化，结果存在一个vector中，再通过vector实现树
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

string serializeResult = "";
char* Serialize(TreeNode* root) {
	char* result = NULL;
	if (!root) {
		return result;
	}

	//层次遍历
	queue<TreeNode*> que;
	que.push(root);

	int curLayerNodeCount = 1, nextLayerNodeCount = 1;
	while (1) {
		curLayerNodeCount = nextLayerNodeCount * 2; // 当前行的结点数量 = 上一行的结点数量 * 2
		nextLayerNodeCount *= 2; //更新记录
		int addNodeNum = 0; //手动补充的新增空结点

		//处理每一行
		while (curLayerNodeCount > 0) {
			TreeNode* curNode = que.front();

			//处理当前结点：序列化
			if (curNode->val == -1) {
				serializeResult.push_back('#');
			}
			else {
				serializeResult += to_string(curNode->val);
				serializeResult.push_back('!');
			}

			// 处理当前结点的左节点
			if (curNode->left != NULL) {
				que.push(curNode->left);
				--curLayerNodeCount;
			}
			else { // 无左节点，新建一个-1结点补充
				TreeNode* addNode = new TreeNode(-1);
				curNode->left = addNode;
				que.push(addNode);
				--curLayerNodeCount;
				++addNodeNum;
			}

			// 处理当前结点的右节点
			if (curNode->right != NULL) {
				que.push(curNode->right);
				--curLayerNodeCount;
			}
			else { // 无右节点，新建一个-1结点补充
				TreeNode* addNode = new TreeNode(-1);
				curNode->right = addNode;
				que.push(addNode);
				--curLayerNodeCount;
				++addNodeNum;
			}

			//弹出当前结点
			que.pop();
		}

		// 下一行全都是新建的补充结点，结束while。
		if (nextLayerNodeCount == addNodeNum) {
			break;
		}
	}

	return &serializeResult[0];
}

TreeNode* Deserialize(char* str) {
	if (str == NULL) {
		return NULL;
	}

	//将序列化拆分，存到vector中
	vector<TreeNode*> tempVecSaveTree;
	string tempNodeVal;
	for (int i = 0; i < strlen(str); ++i) {
		if (str[i] == '#') {
			TreeNode* temp_node = new TreeNode(-1);
			tempVecSaveTree.push_back(temp_node);
		}
		else if (str[i] == '!') {
			int val = atoi(tempNodeVal.c_str());
			tempNodeVal.clear();
			TreeNode* temp_node = new TreeNode(val);
			tempVecSaveTree.push_back(temp_node);
		}
		else {
			tempNodeVal.push_back(str[i]);
		}
	}

	//根据vector建树
	for (int i = 0; i < tempVecSaveTree.size(); ++i) {
		if (tempVecSaveTree[i]->val == -1) {
			continue;
		}
		if (i * 2 + 1 >= tempVecSaveTree.size() || tempVecSaveTree[i * 2 + 1]->val == -1) { //当前结点左孩子为空
			tempVecSaveTree[i]->left = NULL;
		}
		else {
			tempVecSaveTree[i]->left = tempVecSaveTree[i * 2 + 1];
		}

		if (i * 2 + 2 >= tempVecSaveTree.size() || tempVecSaveTree[i * 2 + 2]->val == -1) {//当前结点右孩子为空
			tempVecSaveTree[i]->right = NULL;
		}
		else {
			tempVecSaveTree[i]->right = tempVecSaveTree[i * 2 + 2];
		}
	}

	return tempVecSaveTree[0];
}