/*
地址：
    acwing : https://www.acwing.com/problem/content/47/
    牛客 : https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7
    LeetCode : https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/
题目：
    38. 字符串的排列  P197
描述：
    输入一个字符串，打印出该字符串中字符的所有排列。
补充：
	与 LeetCode-47 相似
	https://leetcode-cn.com/problems/permutations-ii/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/hui-su-suan-fa-java-by-liweiwei1419/

// 方法二：回溯法
class Solution_2 {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        backTrack( res, s, 0 );

        return res;
    }

    void backTrack( vector<string>& res, string& s, int pos ) {
        if ( pos == s.size() ) {
            res.push_back( s );
            return;
        }

        for ( int i = pos; i < s.size(); ++i ) {
            // 如果区间 [pos, i) 内有字符等于 s[i]，则跳过
            if ( judge( s, pos, i ) )
                continue;

            swap( s[pos], s[i] );
            backTrack( res, s, pos + 1 );
            swap( s[pos], s[i] );
        }
    }

    bool judge( string& s, int start, int end ) {
        for ( int i = start; i < end; ++i )
            if ( s[i] == s[end] )
                return true;

        return false;
    }
};


// 方法一：回溯法 - 全排列、DFS
class Solution {
public:
    vector<string> permutation(string s) {
        vector<string> res;
        if ( s.empty() )
            return res;
        // 排序：方便「去重」
        sort( s.begin(), s.end() );

        _permutation( "", s, res );

        return res;
    }

    void _permutation( string prefix, string str, vector<string>& res ) {
        if ( str.size() == 0 ) {
            res.push_back( prefix );
            return;
        }

        for ( int i = 0; i < str.size(); ++i ) {
            // 重复方案 - 剪枝
            if ( i != 0 && str[i] == str[0] )
                continue;

            swap( str[0], str[i] );

            string newPrefix = prefix + str[0];
            string newStr = str.substr( 1 );

            _permutation( newPrefix, newStr, res );
        }
    }
};

int main()
{


    return 0;
}
