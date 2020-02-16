/*
Author: Catnip
Date: 2020/02/15
From: 剑指offer
Link: 
*/
/* Q
首先让小朋友们围成一个大圈。
随机指定一个数m,让编号为0的小朋友开始报数。
每次喊到m-1的那个小朋友要出列唱首歌并且不再回到圈中
从他的下一个小朋友开始,继续0...m-1报数
这样下去直到剩下最后一个小朋友
小朋友的编号是从0到n-1，求最后剩下的小朋友的编号
如果没有小朋友，请返回-1
*/

/* A
约瑟夫环问题
法1：直接法，用数组模拟环，时间复杂度O(mn)
法2：递推法，递推公式理解链接 https://blog.nowcoder.net/n/81a858b422804183a1a51dbfd4084ebc
递推关系式为
f(1,m) = 0                (n=1)
f(n,m) = (f(n-1,m)+m)%n  （n>1）
*/

#include<iostream>
using namespace std;

//直接法：数组模拟环
int LastRemaining_Solution1(int n, int m) {
    if (n < 1 || m < 1) {
        return -1;
    }

    int* flag = new int[n];
    int i = -1, step = 0, count = n;
    while (count > 0) { //跳出循环时将最后一个元素也设置为了-1
        i++; //指向上一个被删除对象的下一个元素。
        if (i >= n) {
            i = 0;  //模拟环。
        }
        if (flag[i] == -1) {
            continue; //跳过被删除的对象。
        }

        step++; //记录已走过的步子。
        if (step == m) { //找到待删除的对象。
            flag[i] = -1;
            step = 0;
            count--;
        }
    }
    return i;//返回跳出循环时的i,即最后一个被设置为-1的元素
}

//递推法：循环方式写递归
int LastRemaining_Solution2(int n, int m) {
    if (n <= 0 || m <= 0) {
        return -1;
    }
    int last = 0;
    for (int i = 2; i <= n; ++i) {
        last = (last + m) % i;
    }
    return last;
}