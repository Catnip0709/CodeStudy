/*
Author: Catnip
Date: 2020/02/14
From: 剑指offer
Link: https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?tpId=13&tqId=11185&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
1~13中包含1的数字有1、10、11、12、13因此共出现6次
把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1到n中1出现的次数）。
*/

/* A
核心：重写sort函数cmp
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool cmp(int str1, int str2) {
    string s1 = to_string(str1) + to_string(str2);
    string s2 = to_string(str2) + to_string(str1);
    return s1 <= s2;
}

string PrintMinNumber(vector<int> numbers) {
    string result = "";
    vector<int> list;
    for (int i = 0; i < numbers.size(); i++) {
        list.push_back(numbers[i]);
    }
    
    sort(list.begin(), list.end(), cmp);

    for (int i = 0; i < list.size(); i++) {
        result += to_string(list[i]);
    }
    return result;
}

int main() {
    vector<int> a = { 3, 32, 321 };
    string result = PrintMinNumber(a);
    cout << result << endl;
}