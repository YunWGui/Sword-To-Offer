/*
题目：
	29. 顺时针打印矩阵，P161
地址：
	acwing : https://www.acwing.com/problem/content/39/
	牛客 :
描述：
	输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
备注：
	同 LeetCode-54 题
    https://leetcode-cn.com/problems/spiral-matrix/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        
        if ( matrix.empty() )
            return res;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        while ( rows > start * 2 && cols > start * 2 ) {
            printMatrixInCircle( matrix, res, start );
            ++start;
        }

        return res;        
    }
    void printMatrixInCircle( vector<vector<int>>& matrix, vector<int>& vec, int start ) {
        int endX = matrix[0].size() - 1 - start;
        int endY = matrix.size() - 1 - start;

        // 上：从左到右
        for ( int i = start; i <= endX; ++i )
            vec.push_back( matrix[start][i] );
        
        // 左：从上到下
        if ( start < endY ) 
            for ( int i = start + 1; i <= endY; ++i )
                vec.push_back( matrix[i][endX] );

        // 下：从右到左
        if ( start < endX && start < endY ) 
            for ( int i = endX - 1; i >= start; --i )
                vec.push_back( matrix[endY][i] );
        
        // 右：从下到上
        if ( start < endX && start < endY - 1 ) 
            for ( int i = endY - 1; i >= start + 1; --i )
                vec.push_back( matrix[i][start] );
    }
};


int main()
{
	

	return 0;
}

