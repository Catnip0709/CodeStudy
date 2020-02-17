/*
Author: Catnip
Date: 2020/02/17
From: 剑指offer
Link: https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2?tpId=13&tqId=11206&rp=3&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
*/

/* A
考虑全部特殊情况
*/

#include<iostream>
#include<string>
using namespace std;

bool isNumeric(char* str)
{
    // 标记符号、小数点、e是否出现过
    bool sign = false, decimal = false, hasE = false;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'e' || str[i] == 'E') {
            if (i == strlen(str) - 1 || i == 0) return false; // e不能位于首位和末尾
            if (str[i - 1] == '.') return false;  //e不能直接接在.后面一位
            if (hasE) return false;  // 不能同时存在两个e
            hasE = true;
        }
        else if (str[i] == '+' || str[i] == '-') {
            // 第二次出现+-符号，则必须紧接在e之后
            if (sign && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
            // 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
            if (!sign && i > 0 && str[i - 1] != 'e' && str[i - 1] != 'E') return false;
            sign = true;
        }
        else if (str[i] == '.') {
            // e后面不能接小数点，小数点不能出现两次
            if (hasE || decimal) return false;
            decimal = true;
        }
        else if (str[i] < '0' || str[i] > '9') // 不合法字符
            return false;
    }
    return true;
}