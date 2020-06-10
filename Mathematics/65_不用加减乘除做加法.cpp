/*
地址：
	acwing :
	牛客 :
    LeetCode : https://leetcode-cn.com/problems/bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof/
题目：
	65. 不用加减乘除做加法  P310
描述：
	写一个函数，求两个整数之和，要求在函数体内不得使用「加」、「减」、「乘」、「除」
    四则运算符号。
*/

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


// 方法二：递归
class Solution_2 {
public:
    int add(int a, int b) {
        int carry = (unsigned int)( a & b ) << 1;
        int sum = ( a ^ b );
        
        if (carry != 0) {
            return add(carry, sum);  // 递归调用 
        }

        return sum;
    }
};


// 方法三：迭代
class Solution_3 {
public:
    int add(int a, int b) {
        int sum, carry;
        do {
            sum = a ^ b;
            carry = (unsigned int)( a & b ) << 1;
            a = sum;
            b = carry;
        } while ( b != 0 );

        return a;
    }
};


// 方法一：容器
class Solution {
public:
    int add(int a, int b) {
        vector<int> v{ a, b };

        return accumulate( v.begin(), v.end(), 0 );
    }
};


int main()
{
    int a = 2, b = 3;
    Solution_3 solve;
    cout << solve.add(a, b) << endl;

	return 0;
}
