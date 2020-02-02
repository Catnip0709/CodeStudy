/*
Author: Catnip
Date: 2020/02/02
From: 剑指offer
Link: https://www.nowcoder.com/practice/a861533d45854474ac791d90e447bafd?tpId=13&tqId=11176&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个整数数组
判断该数组是不是某二叉搜索树的后序遍历的结果
如果是则输出true，否则输出false。
假设输入的数组的任意两个数字都互不相同。
*/

/* A
【后序遍历】左右中
【二叉搜索树】空数，或者若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值；
若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
它的左、右子树也分别为二叉排序树。
【方法】递归
BST的后序序列的合法序列是
对于一个序列S，最后一个元素是x （也就是根）
如果去掉最后一个元素的序列为T
那么T满足：T可以分成两段
前一段（左子树）小于x，后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。
*/

#include<iostream>
#include<vector>
using namespace std;

bool judge(vector<int>& a, int left, int right) {
	if (left >= right) {
		return true;
	}
	int i = right;

    //找到前后两段的分割点，且判断后一段（右子树）大于x
	while (i > left && a[i - 1] > a[right]) {
		--i;
	}
    //判断前一段（左子树）小于x
	for (int j = i - 1; j >= left; --j) {
		if (a[j] > a[right]) {
			return false;
		}
	}
	return judge(a, left, i - 1) && (judge(a, i, right - 1));
}

bool VerifySquenceOfBST(vector<int> sequence) {
	if (sequence.empty())
		return false;
	return judge(sequence, 0, sequence.size() - 1);
}