/*
题目：
    12. 矩阵中的路径
描述：
    请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
    路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。
地址：
    https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
备注：
    同 LeetCode-79 题
    https://leetcode-cn.com/problems/word-search/
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// 方法一：回溯法、深度优先搜索
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
		if ( board.empty() || word.empty() )
			return false;

        for ( int row = 0; row < board.size(); ++row )
            for ( int col = 0; col < board[0].size(); ++col )
                if ( dfs( board, word, row, col, 0 ) )
                    return true;

        return false;
    }

    bool dfs( vector<vector<char>>& board, string& word, int row, int col, int index ) {
        if ( row < 0 || row >= board.size() || col < 0 || col >= board[0].size() )  // 越界
            return false;

		if ( board[row][col] != word[index] )
			return false;
        
		// 由上一个 if 推断出，此时 board[row][col] == word[index]
        if ( index == word.size() - 1 )  // 全部字符串比对完成
            return true;

        char temp = board[row][col];
        board[row][col] = '*';  // 做选择，表示已经访问过了
        bool res = dfs( board, word, row - 1, col, index + 1 )  // 上
                || dfs( board, word, row + 1, col, index + 1 )  // 下
                || dfs( board, word, row, col - 1, index + 1 )  // 左
                || dfs( board, word, row, col + 1, index + 1 );  // 右
        board[row][col] = temp;  // 撤销选择

        return res;
    }
};


int main()
{


	return 0;
}
