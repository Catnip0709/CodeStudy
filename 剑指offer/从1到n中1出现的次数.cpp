/*
Author: Catnip
Date: 2020/02/12
From: 剑指offer
Link: https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
*/

/* Q
求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
1~13中包含1的数字有1、10、11、12、13因此共出现6次
把问题更加普遍化,可以很快的求出任意非负整数区间中1出现的次数（从1到n中1出现的次数）。
*/

/* A
法1：枚举
法2：
设定整数点（如1、10、100等等）作为位置点i（对应n的个位、十位、百位等等）
分别对每个数位上有多少包含1的点进行分析
根据设定的整数位置，对n进行分割，分为两部分，高位n/i，低位n%i
【当i表示百位且百位对应的数>=2】
如n=31456,i=100，则a=314,b=56
此时百位为1的次数有a/10+1=32（最高两位0~31）
每一次都包含100个连续的点，即共有(a%10+1)*100个点的百位为1
【当i表示百位且百位对应的数为1】
如n=31156,i=100，则a=311,b=56
此时百位对应的就是1，则共有a%10(最高两位0-30)次是包含100个连续点，当最高两位为31（即a=311）
本次只对应局部点00~56，共b+1次，所有点加起来共有（a%10*100）+(b+1)，这些点百位对应为1
【当i表示百位且百位对应的数为0】
如n=31056,i=100，则a=310,b=56
此时百位为1的次数有a/10=31（最高两位0~30）

综合以上三种情况，当百位对应0或>=2时，有(a+8)/10次包含所有100个点，还有当百位为1(a%10 == 1)，需要增加局部点b+1
之所以补8，是因为当百位为0，则a/10==(a+8)/10，当百位>=2，补8会产生进位位，效果等同于(a/10+1)
*/

#include<iostream>
#include<string>
using namespace std;

int count1(string target) {
	int count = 0;
	for (int i = 0; i < target.size(); i++) {
		if (target[i] == '1') {
			count++;
		}
	}
	return count;
}

// 法1：枚举法
int NumberOf1Between1AndN_Solution1(int n) {
	if (n < 1) {
		return 0;
	}
	if (n <= 9) {
		return 1;
	}
    int count = 1;
    for (long long i = 10; i <= n; i++) {
		count += count1(to_string(i));
    }
    return count;
}

// 法2
int NumberOf1Between1AndN_Solution2(int n) {
    int count = 0;
    for (long long i = 1; i <= n; i *= 10) {
        //i表示当前分析的是哪一个数位
        int a = n / i, b = n % i;
        count = count + (a + 8) / 10 * i + (a % 10 == 1) * (b + 1);
    }
    return count;
}