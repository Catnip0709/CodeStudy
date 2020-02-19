/*
Author: Catnip
Date: 2020/02/19
From: 剑指offer
Link: https://www.nowcoder.com/practice/c61c6999eecb4b8f88a98f66b273a3cc?tpId=13&tqId=11218&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
如果一条路径经过了矩阵中的某一个格子，则该路径不能再进入该格子。
例如
a b c e
s f c s
a d e e
矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径
因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。
*/

/* A
递归
*/

#include<iostream>
using namespace std;

bool hasPath(char* matrix, int rows, int cols, char* str) {
    bool* flag = new bool[strlen(matrix)]; //flag记录是否已经走过这个格子

    //尝试所有起点，有一个成功则返回true
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (helper(matrix, rows, cols, i, j, str, 0, flag)) {
                return true;
            }
        }
    }
    return false;
}

bool helper(char* matrix, int rows, int cols, int i, int j, char* str, int k, bool* flag) {
    // i, j为当前格子的行和列
    int index = i * cols + j;
    if (i < 0 || i >= rows || j < 0 || j >= cols || //判断i和j的合法性
        matrix[index] != str[k] || // 当前格子不符合要求
        flag[index] == true) { //当前格子已经被走过了
        return false;
    }

    if (k == strlen(str) - 1) { // 目标str全部走完
        return true;
    }

    flag[index] = true;
    if (helper(matrix, rows, cols, i - 1, j, str, k + 1, flag) ||
        helper(matrix, rows, cols, i + 1, j, str, k + 1, flag) ||
        helper(matrix, rows, cols, i, j - 1, str, k + 1, flag) ||
        helper(matrix, rows, cols, i, j + 1, str, k + 1, flag)) {
        return true;
    }
    // 此路不通
    flag[index] = false;
    return false;
}