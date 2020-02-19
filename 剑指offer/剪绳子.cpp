/*
Author: Catnip
Date: 2020/02/19
From: 剑指offer
Link: https://www.nowcoder.com/practice/57d85990ba5b440ab888fc72b0751bf8?tpId=13&tqId=33257&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
给你一根长度为n的绳子，请把绳子剪成整数长的m段（m、n都是整数，n>1并且m>1）
每段绳子的长度记为k[0],k[1],...,k[m]
请问k[0]*k[1]*...*k[m]可能的最大乘积是多少？
例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
*/

/* A
法1：动态规划
法2：乘方运算规律，O(nlogn)
先举几个例子，可以看出规律来。
4 ：2*2
5 ：2*3
6 ：3*3
7 ：2*2*3 或者4*3
8 ：2*3*3
9 ：3*3*3
10：2*2*3*3 或者4*3*3
11：2*3*3*3
12：3*3*3*3
13：2*2*3*3*3 或者4*3*3*3
下面是分析：
首先判断k[0]到k[m]可能有哪些数字，实际上只可能是2或者3。
当然也可能有4，但是4=2*2，我们就简单些不考虑了。
5<2*3,6<3*3,比6更大的数字我们就更不用考虑了，肯定要继续分。
其次看2和3的数量，2的数量肯定小于3个，为什么呢？因为2*2*2<3*3，那么题目就简单了。
直接用n除以3，根据得到的余数判断是一个2/两个2/没有2就行了。
由于题目规定m>1，所以2只能是1*1，3只能是2*1，这两个特殊情况直接返回。
*/

#include<iostream>
#include<math.h>
using namespace std;

// 动态规划
int cutRope1(int number) {
    // number<=3的情况，m>1必须要分段，例如：3必须分成1+2；1+1+1 
    // number=3最大分段乘积是2,
    if (number == 2)
        return 1;
    if (number == 3)
        return 2;

    int* dp = new int[number + 1];
    /*
    n>=4的情况跟n<=3不同，4可以分很多段，比如分成1+3
    这里的3可以不需要再分了，因为3分段最大才2，不分就是3。记录最大的。
     */
    dp[1] = 1; //number=1
    dp[2] = 2; //number=2
    dp[3] = 3; //number=3
    int res = 0;//记录最大的
    for (int i = 4; i <= number; i++) {
        for (int j = 1; j <= i / 2; j++) {
            res = max(res, dp[j] * dp[i - j]);
        }
        dp[i] = res;
    }
    return dp[number];
}

//乘方运算规律
int cutRope2(int number) {
    if (number == 2) {
        return 1;
    }
    if (number == 3) {
        return 2;
    }
    int x = number % 3, y = number / 3;
    if (x == 0) {
        return pow(3, y); //pow(x,y)求 x 的 y 次方的值。
    }
    else if (x == 1) {
        return 2 * 2 * pow(3, y - 1);
    }
    else {
        return 2 * pow(3, y);
    }
}