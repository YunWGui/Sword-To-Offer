/*
地址：
	acwing : acwing.com/problem/content/58/
	牛客 : https://www.nowcoder.com/practice/6aa9e04fc3794f68acf8778237ba065b
题目：
	49 丑数  P240
描述：
	我们把只包含因子 2、3 和 5 的数称作丑数（ Ugly Number）。
	求按从小到大的顺序的第 1500 个丑数。
	例如，6、8 都是丑数，但 14 不是，因为它包含因子 7。
	习惯上我们把 1 当作第一个丑数。
备注：
    同 LeetCode-264 题
    https://leetcode-cn.com/problems/ugly-number-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 解决方案一：
class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if ( index <= 0 )
            return 0;
        vector<int> dp;
        dp.push_back( 1 );
        int M2 = 0, M3 = 0, M5 = 0;
        while ( dp.size() < index ) {
            int minValue = min( dp[M2]*2, min( dp[M3]*3, dp[M5]*5) );
            dp.push_back( minValue );
            while ( dp[M2]*2 <= dp[dp.size()-1] )
                ++M2;
            while ( dp[M3]*3 <= dp[dp.size()-1] )
                ++M3;
            while ( dp[M5]*5 <= dp[dp.size()-1] )
                ++M5;
        }
        return dp[dp.size()-1];
    }
};

// 解决方案二：
	class Solution_2 {
	public:
	    int getUglyNumber(int n) {
	        int count = 0;

	        if ( n <= 0 )
	            return 0;

	        for ( int i = 1; i < INT_MAX; ++i ) {
	            if ( IsUglyNumber(i) )
	                ++count;

	            if ( n == count )
	                return i;
	        }
	    }
	    bool IsUglyNumber(int number) {
	        while ( number % 2 == 0 )
	            number /= 2;
	        while ( number % 3 == 0 )
	            number /= 3;
	        while ( number % 5 == 0 )
	            number /= 5;

	        if ( number == 1 )
	            return true;
	        else
	            return false;
	    }
	};

// 方法三：
class Solution_3 {
public:
    int nthUglyNumber(int n) {
        if ( n <= 0 )
            return -1;
        
        int M2 = 1, M3 = 1, M5 = 1;  // M2, M3, M5 起始下标
        // int* dp = new int[n + 1];
        // vector<int> dp( n+1, 0 );
        int dp[n+1];
        // dp[0] = 0;  // 从下标为 1 处开始计算，故无需赋值，可忽略
        dp[1] = 1;
        for ( int i = 2; i <= n; ++i ) {
            int next2 = dp[M2] * 2;
            int next3 = dp[M3] * 3;
            int next5 = dp[M5] * 5;

            dp[i] = min( next2, min( next3, next5 ) );            
            
            if ( dp[i] == next2 )
                ++M2;
            if ( dp[i] == next3 )
                ++M3;
            if ( dp[i] == next5 )
                ++M5;
        }

        return dp[n];
    }
};


int main()
{


	return 0;
}
