/*
Author: Catnip
Date: 2020/02/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/94a4d381a68b47b7a8bed86f2975db46?tpId=13&tqId=11204&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
给定一个数组A[0,1,...,n-1]
请构建一个数组B[0,1,...,n-1]
其中B中的元素B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]。
不能使用除法。（注意：规定B[0]和B[n-1] = 1）
*/

/* A
B[i]的值可以看作下图的矩阵中每行的乘积。
B0     =  1   A1  A2   ...    A(n-2)  A(n-1)
B1     =  A0  1   A2   ...    A(n-2)  A(n-1)
B2     =  A0  A1  1    ...    A(n-2)  A(n-1)
...    =  A0  A1  ...  1      A(n-2)  A(n-1)
B(n-2) =  A0  A1  ...  A(n-3) A(n-2)  A(n-1)
B(n-1) =  A0  A1  ...  A(n-3) A(n-2)  1

对于下三角（B[i]中的一部分）：B[i] = B[i-1] * A[i-1];
然后倒过来按上三角中的分布规律，把另一部分也乘进去。
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> multiply(const vector<int>& A) {
    int length = A.size();
    vector<int> B;
    if (length != 0) {
        B.push_back(1);

        //从上向下，计算下三角连乘
        for (int i = 1; i < length; i++) {
            B.push_back(B[i - 1] * A[i - 1]);
        }
        //从下向上，补充上三角连乘
        int temp = 1;
        for (int j = length - 2; j >= 0; j--) {
            temp *= A[j + 1];
            B[j] *= temp;
        }
    }
    return B;
}