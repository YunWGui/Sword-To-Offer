/*
地址：
	acwing : https://www.acwing.com/problem/content/56/
	LeetCode : https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof/
题目：
	47 礼物的最大价值  P233
描述：
	在一个 m X n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你
可以从棋盘的左上角开始拿格子里的礼物，并每次向左或向下移动一格，直到到达棋盘的右下角。
	给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 方法三：动态规划
//        相对于「方法一」，省略 if 判断，因此时间复杂度更低
class Solution_3 {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp( rows, vector<int>(cols, 0) );
        
        dp[0][0] = grid[0][0];
        for ( int j = 1; j < cols; ++j )  // 初始化 dp 的第一「行」数据
            dp[0][j] = grid[0][j] + dp[0][j-1];
        for ( int i = 1; i < rows; ++i )  // 初始化 dp 的第一「列」数据
            dp[i][0] = grid[i][0] + dp[i-1][0];

        for ( int i = 1; i < rows; ++i ) 
            for ( int j = 1; j < cols; ++j ) 
                dp[i][j] = grid[i][j] + max( dp[i-1][j], dp[i][j-1] );
            
        return dp[rows-1][cols-1];     
    }
};

// 方法一：动态规划
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> maxValues( rows, vector<int>(cols, 0) );

        for ( int i = 0; i < rows; ++i ) {
            for ( int j = 0; j < cols; ++j ) {
                int up = 0;
                int left = 0;

                if ( i > 0 )
                    up = maxValues[i-1][j];
                if ( j > 0 )
                    left = maxValues[i][j-1];
                maxValues[i][j] = max( up, left ) + grid[i][j];
            }
        }
        int maxValue = maxValues[rows-1][cols-1];

        return maxValue;
    }
};

// 解法二：动态规划
class Solution_2 {
public:
    int getMaxValue(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<int> maxValues( cols, 0 );

        for ( int i = 0; i < rows; ++i ) {
            for ( int j = 0; j < cols; ++j ) {
                int up = 0;
                int left = 0;

                if ( i > 0 )
                    up = maxValues[j];
                if ( j > 0 )
                    left = maxValues[j-1];
                maxValues[j] = max( up, left ) + grid[i][j];
            }
        }
        int maxValue = maxValues[cols-1];

        return maxValue;
    }
};


int main()
{


	return 0;
}
