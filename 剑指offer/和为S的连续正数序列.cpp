/*
Author: Catnip
Date: 2020/02/15
From: 剑指offer
Link: https://www.nowcoder.com/practice/c451a3fd84b64cb19485dad758a55ebe?tpId=13&tqId=11194&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking*/

/* Q
输出所有和为S的连续正数序列。
序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序
*/

/* A
用左右动态窗口窗口+等差数列求和公式来简化穷举
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    //存放结果
    vector<vector<int> > result;

    //动态窗口的两边，根据其窗口内的值的和来确定窗口的位置和大小
    int pLow = 1, pHigh = 2;

    while (pHigh > pLow) {
        //由于是连续的，差为1的一个序列，那么等差数列求和公式为(a0 + an) * n / 2
        int cur = (pHigh + pLow) * (pHigh - pLow + 1) / 2;
        
        if (cur == sum) { //相等，那么就将窗口范围的所有数添加进结果集
            vector<int> list;
            for (int i = pLow; i <= pHigh; i++) {
                list.push_back(i);
            }
            result.push_back(list);
            pLow++;
        }
        else if (cur < sum) {  //如果当前窗口内的值之和小于sum，那么右边窗口右移一下
            pHigh++;
        }
        else { //如果当前窗口内的值之和大于sum，那么左边窗口右移一下
            pLow++;
        }
    }
    return result;
}