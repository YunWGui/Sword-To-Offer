/*
地址：
	牛客：https://www.nowcoder.com/practice/1a834e5e3e1a4b7ba251417554e07c00
	acwing：https://www.acwing.com/problem/content/26/
题目：
	16. 数值的整数次方  P110
描述：
	实现函数 double Power(double base, int exponent)，求 base 的 exponent 次方。
	不得使用库函数，同时不需要考虑大数问题。
备注：
    同 LeetCode-50 题
    https://leetcode-cn.com/problems/powx-n/
*/

#include <iostream>
using namespace std;

// 方法二: 递归 
class Solution_2 {
public:
    double myPow(double x, int n) {
        if ( abs(x) < 0.00001 )
            return 0;
        if ( n == 0 )
            return 1;

        double res = helper( x, abs( long(n) ) );  // 递归调用
        
        if ( n < 0 )
            res = 1.0 / res;

        return res;
    }

    double helper(double x, long long n ) {
        if ( n == 1 )
            return x;
        
        double res = helper( x, n>>1 );

        res *= res;
        if ( (n & 1) == 1 )
            res *= x;
        
        return res;
    }
};

// 方法一：
class Solution {
public:
    double Power(double base, int exponent) {
        if ( abs(base) < 0.00001 )
            return 0;
        if ( exponent == 0 )
            return 1;

        int absExponent = abs(exponent);
        double res = 1.0;
        for ( int i = 0; i < absExponent; ++i )
            res *= base;

        if ( exponent < 0 )  // 置反
            res = 1.0 / res;

        return res;
    }
};
