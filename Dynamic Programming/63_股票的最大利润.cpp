/*
地址：
	acwing : https://www.acwing.com/problem/content/79/
	牛客 :
题目：
	63. 股票的最大利润  P304
描述：
	假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润
是多少？

备注：
    同 LeetCode-121 题
    https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法二：动态规划
class Solution_2 {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.size() <= 1 )    
            return 0;
        
        int minPrice = prices[0];
        int maxDiff = prices[1] - minPrice;
        for ( size_t i = 2; i < prices.size(); ++i ) {
            if ( prices[i-1] < minPrice )
                minPrice = prices[i-1];
            
            int currentDiff = prices[i] - minPrice;
            if ( maxDiff < currentDiff )
                maxDiff = currentDiff;
        }

        return maxDiff > 0 ? maxDiff : 0;
    }
};

// 方法三：动态规划
class Solution_3 {
public:
    int maxProfit(vector<int>& prices) {
        if ( prices.empty() )
            return 0;
            
        int res = 0;
        int curMin = prices[0];
        for ( size_t cell = 1; cell < prices.size(); ++cell ) {
            curMin = min( curMin, prices[cell] );
            res = max( res, prices[cell] - curMin );
        }

        return res;
    }
};

// 方法一：蛮力法
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if ( length <= 1 )
            return 0;

        int maxValue = 0;
        for ( size_t i = 0; i < length - 1; ++i ) {
            for ( size_t j = i+1; j < length; ++j ) {
                if ( prices[i] < prices[j] )
                    maxValue = max( prices[j]-prices[i], maxValue );
            }
        }

        return maxValue;
    }
};

int main()
{


	return 0;
}
