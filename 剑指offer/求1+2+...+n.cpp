/*
Author: Catnip
Date: 2020/02/16
From: 剑指offer
Link: https://www.nowcoder.com/practice/7a0da8fc483247ff8800059e12d7caf1?tpId=13&tqId=11200&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
求1+2+3+...+n
要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
*/

/* A
等差数列求和公式
*/

#include<iostream>
using namespace std;

int Sum_Solution(int n) {
    return n*(1+n)/2;
}