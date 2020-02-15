/*
Author: Catnip
Date: 2020/02/15
From: 剑指offer
Link: https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2?tpId=13&tqId=11190&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
统计一个数字在排序数组中出现的次数。
*/

/* A
有序数组，故二分查找找到target，再向左右两边扩充统计次数。
*/

#include<iostream>
#include<vector>
using namespace std;

//二分查找循环版
int Search(const vector<int> vec, int target) {
    int left = -1;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (vec[mid] == target)
            return mid;
        if (vec[mid] > target) {
            right = mid - 1;
        }
        else if (vec[mid] < target) {
            left = mid + 1;
        }
    }
    if (left > right) {
        return -1;
    }
}
int GetNumberOfK(vector<int> data, int k) {
    if (data.size() == 0) {
        return 0;
    }
    int pos = Search(data, k);          
    if (pos == -1) {
        return 0;
    }
    int count = 1;
    int posRight = pos + 1, posLeft = pos - 1;
    while (posRight < data.size()) {
        if (data[posRight++] == k) {
            count++;
        }
        else {
            break;
        }
    }
    while (posLeft >= 0) {
        if (data[posLeft--] == k) {
            count++;
        }
        else {
            break;
        }
    }
    return count;
}

int main() {
    vector<int> a = { 1,2,2,2,3,4,4,5 };
    cout << GetNumberOfK(a,5) << endl;
}