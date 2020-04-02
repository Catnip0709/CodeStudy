/*
Author: Catnip
Date: 2020/04/02
From: LeetCode
Link: https://leetcode-cn.com/problems/game-of-life/
*/
/* Q
生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。

给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。

每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：

1、如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
2、如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
3、如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
4、如果死细胞周围正好有三个活细胞，则该位置死细胞复活；

根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。
下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。
*/

/* A
节约空间：想办法复用原有数组，避免复制。
每一格中，0 = 原本死亡， 1 = 原本存活， 2 = 原本死亡后来复活， 3 = 原本存活后来死亡
*/

#include <iostream>
#include <vector>
using namespace std;

int nextStatus(vector<vector<int>> board, int row, int col) {
    int count = 0; // 计算周围的活细胞数量。

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            if (row + i < 0 || row + i >= board.size() || 
                col + j < 0 || col + j >= board[0].size() || 
                (i == 0 && j == 0) )
                continue;
            if (board[row + i][col + j] == 1 || board[row + i][col + j] == 3) {
                count++;
            }
        }
    }

    if (board[row][col] == 1 && !(count == 2 || count == 3)) {    
        return 3;
    }
    else if (board[row][col] == 0 && count == 3) { // 规则4
        return 2;
    }
    return board[row][col];
}

void gameOfLife(vector<vector<int>>& board) {
    if (board.size() <= 0 || board[0].size() <= 0) {
        return;
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            board[i][j] = nextStatus(board, i, j);
        }
    }

    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == 2) {
                board[i][j] = 1;
            }
            else if (board[i][j] == 3) {
                board[i][j] = 0;
            }
        }
    }
}

int main() {
    vector<vector<int>> test = { {0, 1, 0},{0, 0, 1},{1, 1, 1},{0, 0, 0} };
    gameOfLife(test);
}