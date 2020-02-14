/*
Author: Catnip
Date: 2020/02/14
From: 剑指offer
Link: https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b?tpId=13&tqId=11186&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
*/

/* A
一个丑数的因子只有2,3,5，那么丑数p = 2 ^ x * 3 ^ y * 5 ^ z
换句话说一个丑数一定由另一个丑数乘以2或者乘以3或者乘以5得到
*/

#include<iostream>
#include<vector>
using namespace std;

int GetUglyNumber_Solution(int index) {
    if (index < 7)
        return index;
    vector<int> res(index);
    res[0] = 1;
    int t2 = 0, t3 = 0, t5 = 0;
    for (int i = 1; i < index; ++i)
    {
        res[i] = min(res[t2] * 2, min(res[t3] * 3, res[t5] * 5));
        if (res[i] == res[t2] * 2)
            t2++;
        if (res[i] == res[t3] * 3)
            t3++;
        if (res[i] == res[t5] * 5)
            t5++;
    }
    return res[index - 1];
}

int main() {
    cout << GetUglyNumber_Solution(8);
}