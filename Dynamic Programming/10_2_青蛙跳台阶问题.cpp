/*
题目：
    10.2 青蛙跳台阶问题  P77
描述：
    一只青虾一次可以跳上 1 级台阶，也可以跳上 2 级台阶。
    求该青蛙跳上一个 n 级台阶共有多少种跳法。
备注：
    同 LeetCode-70 题
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划
/*
    当 n>2 时，第一次跳的时候有两种选择：1、第一次只跳 1 级，此时跳法数目等于剩下的 n-1
级台阶的跳法数目，即为 f(n-1); 2、第一次跳 2 级，此时跳法数目等于后面剩下的 n-2 级台
阶的跳法数目，即为 f(n-2)。  
*/
class Solution {
public:
    int numWays(int n) {
        if ( n == 0 || n == 1 )
            return 1;
        if ( n == 2 )
            return 2;

        int vec[n + 1];  // 似乎更快
        // int* vec = new int[n + 1];
        vec[0] = 0;
        vec[1] = 1;
        vec[2] = 2;
        
        for ( int i = 3; i <= n; ++i )
            vec[i] = ( vec[i-1] + vec[i-2] ) % 1000000007;

        return vec[n];
    }
};

int main()
{
    int x{ 100 };


    return 0;
}