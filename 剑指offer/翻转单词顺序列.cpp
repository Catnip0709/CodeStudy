/*
Author: Catnip
Date: 2020/02/16
From: 剑指offer
Link: https://www.nowcoder.com/practice/3194a4f4cf814f63919d0790578d51f3?tpId=13&tqId=11197&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
牛客最近来了一个新员工Fish，每天早晨总是会拿着一本英文杂志，写些句子在本子上。
同事Cat对Fish写的内容颇感兴趣，有一天他向Fish借来翻看，但却读不懂它的意思。
例如，“student. a am I”。
后来才意识到，这家伙原来把句子单词的顺序翻转了，正确的句子应该是“I am a student.”。
Cat对一一的翻转这些单词顺序可不在行，你能帮助他么？
*/

/* A
先整体翻转，再局部翻转每一个单词
*/

#include<iostream>
using namespace std;

void ReverseWord(string& str, int left, int right) {
    while (left < right) {
        swap(str[left++], str[right--]);
    }
}

string ReverseSentence(string str) {
    //整体翻转
    ReverseWord(str, 0, str.size() - 1);

    int i = 0;
    // 遍历每一个字符
    while (i < str.size()) {
        while (i < str.size() && str[i] == ' ') { //空格跳过
            i++;
        }
        int wordStart = i; //记录单词的第一个字符的位置
        while (i < str.size() && str[i] != ' ') { //找单词最后一个字符的位置
            i++;
        }
        ReverseWord(str, wordStart, i - 1); //局部翻转
    }
    return str;
}