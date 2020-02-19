/*
Author: Catnip
Date: 2020/02/18
From: 剑指offer
Link: https://www.nowcoder.com/practice/1624bc35a45c42c0bc17d17fa0cba788?tpId=13&tqId=11217&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3
那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}
针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个
{[2,3,4],2,6,2,5,1} 
{2,[3,4,2],6,2,5,1} 
{2,3,[4,2,6],2,5,1} 
{2,3,4,[2,6,2],5,1} 
{2,3,4,2,[6,2,5],1}
{2,3,4,2,6,[2,5,1]}
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    vector<int> result;
    deque<int> s; // 双端队列，存的是下标，不是值
    for (int i = 0; i < num.size(); ++i) {
        //从后面依次弹出队列中比当前num值小的元素，同时也能保证队列首元素为当前窗口最大值下标
        while (s.size() && num[s.back()] <= num[i]) {
            s.pop_back();
        }
        //窗口已经移出队首元素所在的位置
        //即队首元素坐标对应的num不在窗口中，需要弹出
        while (s.size() && i - s.front() + 1 > size) {
            s.pop_front();
        }
        s.push_back(i);//把每次滑动的num下标加入队列
        if (size && i + 1 >= size) { //当滑动窗口首地址i大于等于size时才开始写入窗口最大值
            result.push_back(num[s.front()]);
        }
    }
    return result;
}