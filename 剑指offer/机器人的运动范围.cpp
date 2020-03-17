/*
Author: Catnip
Date: 2020/02/19
From: 剑指offer
Link: https://www.nowcoder.com/practice/6e5207314b5241fb83f2329e89fdecc8?tpId=13&tqId=11219&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
地上有一个m行和n列的方格。
一个机器人从坐标0,0的格子开始移动
每一次只能向左，右，上，下四个方向移动一格
但是不能进入行坐标和列坐标的数位之和大于k的格子。
例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？
*/

#include<iostream>
#include<vector>
using namespace std;

//数字处理，将36变成3+6=9
int numSum(int i) {
    int sum = 0;
    do {
        sum += i % 10;
    } while ((i = i / 10) > 0);
    return sum;
}

int helper(int i, int j, int rows, int cols, bool** flag, int threshold) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || // 保证i和j的合法性
        numSum(i) + numSum(j)  > threshold || // 保证当前格子合法
        flag[i][j] == true) { // 保证当前格子没走过
        return 0;
    }

    flag[i][j] = true;
    return helper(i - 1, j, rows, cols, flag, threshold) +
           helper(i + 1, j, rows, cols, flag, threshold) +
           helper(i, j - 1, rows, cols, flag, threshold) +
           helper(i, j + 1, rows, cols, flag, threshold) + 1;
}

int movingCount(int threshold, int rows, int cols) {
    if (threshold <= 0 ||rows <= 0 || cols <= 0) {
        return 0;
    }
    bool** flag = new bool* [rows];
    for (int i = 0; i < cols; i++) {
        flag[i] = new bool[cols];
        memset(flag[i], false, cols);
    }

    return helper(0, 0, rows, cols, flag, threshold);
}

int main() {
    cout << movingCount(5,5,10) << endl;
}