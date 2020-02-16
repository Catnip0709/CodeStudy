/*
Author: Catnip
Date: 2020/02/16
From: 剑指offer
Link: https://www.nowcoder.com/practice/762836f4d43d43ca9deb273b3de8e1f4?tpId=13&tqId=11198&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/
/* Q
LL去买了一副扑克牌,发现里面居然有2个大王,2个小王(一副牌原本是54张)
他随机从中抽出了5张牌,想测测自己的手气,看看能不能抽到顺子
“红心A,黑桃3,小王,大王,方片5”,不是顺子
LL不高兴了,他想了想,决定大\小王可以看成任何数字,并且A看作1,J为11,Q为12,K为13。
上面的5张牌就可以变成“1,2,3,4,5”(大小王分别看作2和4)
如果牌能组成顺子就输出true，否则就输出false。
为方便起见可以认为大小王是0。
*/

/* A
需要满足条件 
1）max - min < 5
2）除0外没有重复的数字(牌)
3）数组长度=5
*/

#include<iostream>
#include<vector>
using namespace std;

bool IsContinuous(vector<int> numbers) {
	if (numbers.size() != 5) {
		return false;
	}
	int min = 14, max = -1;
	bool flag[13]; // 记录某一张牌是否出现多次
	memset(flag, false, sizeof(flag)); //全都初始化为false

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0) {
			continue;
		}

		if (flag[numbers[i]]) {
			return false;
		}
		flag[numbers[i]] = true;
		
		if (numbers[i] > max) {
			max = numbers[i];
		}
		if (numbers[i] < min) {
			min = numbers[i];
		}
	}
	if (max - min < 5) {
		return true;
	}
	return false;
}

int main() {
	vector<int> a = {1, 3, 2, 6, 4};
	cout << IsContinuous(a);
}

