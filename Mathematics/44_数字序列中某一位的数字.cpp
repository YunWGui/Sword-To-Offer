/*
地址：
	acwing : https://www.acwing.com/problem/content/52/
	LeetCode : https://leetcode-cn.com/problems/shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof/
题目：
	44 数字序列中某一位的数字  P225
描述：
	数字以 0123456789101112131415... 的格式序列化到一个字符序列中。在这个序列中，第
	5 位（从 0 开始计数）是 5，第 13 位是 1，第 19 位是 4，等待。
	请写出一个函数，求任意第 n 位对应的数字。
相同题型：
	LeetCode-400 第 N 个数字
	https://leetcode-cn.com/problems/nth-digit/
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// 解法一：
// https://www.acwing.com/solution/acwing/content/1166/
class Solution {
public:
    int digitAtIndex(int n) {
        long long i = 1, s = 9, base = 1;
        while ( n > i*s ) {
            n -= i * s;
            ++i;
            s *= 10;
            base *= 10;
        }
        int number = base + ( n + i - 1 ) / i - 1;
        int r = (n % i) ? (n % i) : i;

        for ( int j = 0; j < i - r; ++j )
            number /= 10;

        return number % 10;
    }
};

// 解法二：推荐
// https://www.acwing.com/solution/acwing/content/2587/
class Solution_2 {
public:
    int digitAtIndex(int n) {
        long long len = 1, nums = 9;
        --n;
        while ( true ) {
            if ( n >= len*nums )
                n -= len * nums;
            else
                break;

            ++len;
            nums *= 10;
        }
        long long val = pow(10, len-1) + n / len;
        string tem = to_string( val );

        return tem[n % len] - '0';
    }
};

int main()
{


	return 0;
}
