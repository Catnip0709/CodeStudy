/*
Author: Catnip
Date: 2020/02/11
From: 剑指offer
Link: https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
如果不存在则输出0。
*/

/* A
【思路一】数组排序后，如果符合条件的数存在，则一定是数组中间那个数。快排时间复杂度O(nlogn)
【思路二】如果有符合条件的数字，则它出现的次数比其他所有数字出现的次数和还要多。
在遍历数组时保存两个值：一是数组中一个数字，一是次数。
遍历下一个数字时，若它与之前保存的数字相同，则次数加1，否则次数减1；
若次数为0，则保存下一个数字，并将次数置为1。
遍历结束后，所保存的数字即为所求。然后再判断它是否符合条件即可。
时间复杂度O(n),空间复杂度0(1)
*/

#include<iostream>
#include<vector>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.empty()) {
		return 0;
	}
	int time_count = 1, target_number = numbers[0];
	for (int i = 1; i < numbers.size(); i++) {
		if (numbers[i] == target_number) {
			time_count++;
		}
		else {
			time_count--;
		}

		if (time_count == 0) {
			time_count = 1;
			target_number = numbers[i];
		}
	}

	//结果确认（防止出现[1,2,3,4,5,5]，结果是5却不超过一般的情况
	time_count = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (target_number == numbers[i]) {
			time_count++;
		}
	}
    
	return time_count * 2 >= numbers.size() ? target_number : 0;
}
int main() {
	vector<int> a = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int b = MoreThanHalfNum_Solution(a);
}