/*
Author: Catnip
Date: 2020/02/11
From: 剑指offer
Link: https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba?tpId=13&tqId=11178&rp=1&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
输入一个字符串,按字典序打印出该字符串中字符的所有排列。
例如输入字符串abc
则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
输入描述:输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//判断vector的某一元素是否存在
bool is_element_in_vector(vector<string> v, string element) {
    vector<string>::iterator it = find(v.begin(), v.end(), element);
    if (it != v.end()) {
        return true;
    }
    return false;
}

//交换string的两个下标的元素
void swap(string& str, int i, int j) {
    if (i != j) {
        char t = str[i];
        str[i] = str[j];
        str[j] = t;
    }
}

void func(string ch, vector<string>& list, int i) {
    //这是递归的终止条件，就是i下标已经移到char数组的末尾的时候
    //考虑是否添加这一组字符串进入结果集中
    if (i == ch.size() - 1) {
        //判断一下是否重复
        if (!is_element_in_vector(list, ch)) {
            list.push_back(ch);
        }
        return;
    }

    //回溯法，这里以"abc"为例

    //1.第一次进到这里是ch="abc", list=[], i=0，称为【状态A】 ，即初始状态
    //那么j = 0，第一次执行swap(ch,0,0)，就是"abc"，第一次swap之后的状态称为【状态B】，进入递归后i = 1, 
    //i不等于2，来到这里，j = 1，执行第一个swap(ch,1,1)，这个状态我称为 状态C1 ,再进入fun函数，此时标记为T1，i为2，那么这时就进入上一个if，将"abc"放进list中
    //此时结果集为["abc"]

    //2.执行完list.add之后，遇到return，回退到T1处，接下来执行第二个swap(ch,1,1)，状态C1又恢复为状态B
    //恢复完之后，继续执行for循环，此时j=2,那么swap(ch,1,2),得到"acb"，这个状态我称为C2,然后执行fun，此时标记为T2,发现i+1=2,所以也被添加进结果集，此时return回退到T2处往下执行
    //此时结果集为["abc","acb"]
    //然后执行第二个swap(ch,1,2)，状态C2回归状态B,然后状态B的for循环退出回到状态A

    //             a|b|c(状态A)
    //               |
    //               |swap(0,0)
    //               |
    //             a|b|c(状态B)
    //             /  \
    //   swap(1,1)/    \swap(1,2)  (状态C1和状态C2)
    //           /      \
    //         a|b|c   a|c|b

    //3.回到状态A之后，继续for循环，j=1,即swap(ch,0,1)，即"bac",这个状态可以再次叫做状态A,下面的步骤同上
    //此时结果集为["abc","acb","bac","bca"]

    //             a|b|c(状态A)
    //               |
    //               |swap(0,1)
    //               |
    //             b|a|c(状态B)
    //             /  \
    //   swap(1,1)/    \swap(1,2)  (状态C1和状态C2)
    //           /      \
    //         b|a|c   b|c|a

    //4.再继续for循环，j=2,即swap(ch,0,2)，即"cab",这个状态可以再次叫做状态A，下面的步骤同上
    //此时结果集为["abc","acb","bac","bca","cab","cba"]

    //             a|b|c(状态A)
    //               |
    //               |swap(0,2)
    //               |
    //             c|b|a(状态B)
    //             /  \
    //   swap(1,1)/    \swap(1,2)  (状态C1和状态C2)
    //           /      \
    //         c|b|a   c|a|b

    //5.最后退出for循环，结束。

    for (int j = i; j < ch.size(); j++) {
        swap(ch, i, j);
        func(ch, list, i + 1);
        swap(ch, i, j);
    }
}

vector<string> Permutation(string str) {
	vector<string> resultList;
	if (str.empty())
		return resultList;
	//递归的初始值为（str数组，空的list，初始下标0）
	func(str, resultList, 0);
    sort(resultList.begin(), resultList.end());
	return resultList;
}

int main() {
    vector<string> result = Permutation("abc");
}