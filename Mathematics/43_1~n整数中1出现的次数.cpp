/*
地址：
	acwing : https://www.acwing.com/problem/content/51/
	牛客 : https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6
题目：
	43 1~n 整数中 1 出现的次数  P221
描述：
	输入一个整数 n，求 1 ~ n 这 n 个整数的十进制表示中 1 出现的次数。
	例如，输入 12, 1 ~ 12 这些整数中包含 1 的数字有 1、10、11 和 12，1 一共出现 5次
备注：
	同 LeetCode-233 题
	https://leetcode-cn.com/problems/number-of-digit-one/
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int count = 0;
        for ( long long i = 1; i <= n; i *= 10 ) {
            long long divider = i * 10;
            count += ( n / divider ) * i + min( max(n % divider - i + 1, 0LL), i);
        }

        return count;
    }
};

int main()
{


	return 0;
}
