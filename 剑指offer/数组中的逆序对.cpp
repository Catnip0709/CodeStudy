/*
Author: Catnip
Date: 2020/02/14
From: 剑指offer
Link: https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5?tpId=13&tqId=11188&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组,求出这个数组中的逆序对的总数P。
并将P对1000000007取模的结果输出。
即输出P%1000000007
*/

/* A
法1：遍历+依次对比，时间复杂度O(n^2)
法2：归并排序思路。拆分，先组内对比，再排序，再和临组对比并不断合并。直到最后得到一个有序数组。归并排序时间复杂度O(nlogn)
*/

#include<iostream>
#include<vector>
using namespace std;

int InversePairs(vector<int> data) {
    if (data.size() <= 1) {
        return 0;
    }

    vector<int> copy;
    for (int i = 0; i < data.size(); i++) {
        copy.push_back(data[i]);
    }
    long long count = InversePairsCore(data, copy, 0, data.size() - 1);

    return count % 1000000007;
}

long long InversePairsCore(vector<int>& data, vector<int>& copy, int start, int end) {
    if (start == end) {
        copy[start] = data[start];
        return 0;
    }
    int length = (end - start) / 2;

    //不断拆分，left为左侧的逆序对数量，right为右侧的逆序对数量
    long long left = InversePairsCore(copy, data, start, start + length);
    long long right = InversePairsCore(copy, data, start + length + 1, end);

    int i = start + length;
    int j = end;
    int indexCopy = end;
    long long count = 0;
    //统计合并左右的新逆序对数量
    while (i >= start && j >= start + length + 1) {
        if (data[i] > data[j]){
            copy[indexCopy--] = data[i--];
            count = count + j - start - length;
        }
        else {
            copy[indexCopy--] = data[j--];
        }
    }

    //合并
    while (i >= start) {
        copy[indexCopy--] = data[i--];
    }
    while (j >= start + length + 1) {
        copy[indexCopy--] = data[j--];
    }

    //返回当前总逆序对数量
    return left + right + count;
}