/*
Author: Catnip
Date: 2020/02/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/9be0172896bd43948f8a32fb954e1be1?tpId=13&tqId=11216&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
如何得到一个数据流中的中位数？
如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。
*/

/* A
大根堆用来存较小的数，从大到小排列
小根堆存较大的数，从小到大的顺序排序
显然中位数就是大顶堆的根节点与小顶堆的根节点和的平均数。
*/

#include<iostream>
#include<queue>
using namespace std;

priority_queue<int, vector<int>, less<int> > bigHeap; //大根堆存较小的数字，堆顶最大
priority_queue<int, vector<int>, greater<int> > smallHeap; //小根堆存较大的数字，堆顶最小

void Insert(int num) {
	// 插入新值
	if (bigHeap.empty() || num <= bigHeap.top()) {
		bigHeap.push(num);
	}
	else {
		smallHeap.push(num);
	}

	// 平衡2个堆的元素数量
	// 大根堆的大小最多可以比小顶堆大1（奇数次输入）
	if (bigHeap.size() == smallHeap.size() + 2) {
		smallHeap.push(bigHeap.top());
		bigHeap.pop();
	}
	// 因为最后返回的只有可能是大根堆的堆顶，所以小根堆的大小不能比大顶堆大
	if (bigHeap.size() + 1 == smallHeap.size()) {
		bigHeap.push(smallHeap.top());
		smallHeap.pop();
	}
}
double GetMedian() {
    return bigHeap.size() == smallHeap.size() ? (bigHeap.top() + smallHeap.top()) / 2.0 : bigHeap.top();
}