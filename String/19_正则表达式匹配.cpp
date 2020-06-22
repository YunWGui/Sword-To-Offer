/*
地址：
	acwing:
	牛客:
	LeetCode : https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/
题目：
	19. 正则表达式匹配
描述：
	请实现一个函数用来匹配包含 '.' 和 '*' 的正则表达式。
	模式中 '.' 表示任意一个字符，而 '*' 表示它前面的字符可以出现任意次（含0次）。
	在本题中，匹配是指字符串的所有字符匹配整个模式。
备注：
	同 LeetCode-10
	https://leetcode-cn.com/problems/regular-expression-matching/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// https://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/hui-su-fa-dong-tai-gui-hua-by-luo-jing-yu-yu/
// 方法一：递归
class Solution {
public:
    bool isMatch(string s, string p) {
        if ( p.empty() )
            return s.empty();
        
        // 匹配第一个字符
        bool first_match = ( !s.empty() && ( s[0] == p[0] || p[0] == '.' ) );

        // 匹配第二个字符
        if ( p.size() >= 2 && p[1] == '*' )  // 第二个字符是 '*'
            return ( isMatch( s, p.substr(2) ) )  // s 第一个字符出现 0 次
                || ( first_match && isMatch( s.substr(1), p ) );  // s 第一个字符出现「任意」次
        else  // 第二个字符不是 '*' 或 p 只有一个字符
            return first_match && isMatch( s.substr(1), p.substr(1) );
    }
};

 
// 方法二：动态规划
class Solution_2 {
public:
    bool isMatch(string s, string p) {
        if (p.empty()) {
            return s.empty();
        }

        // 前面加某一相同字符，
        // 防止 (ab, c*ab) 这样的匹配，
        // 避免复杂的初始化操作
        s = " " + s;
        p = " " + p;
        int m = s.size(), n = p.size();

        // 定义记忆数组，并初始化为false
        std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

        // 设添加的字符为真
        dp[0][0] = true;

        // 记忆数组能保持字符串上一个字符的状态
        // 因此可以对下一个字符进行判断
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                // 不带 '*' 号时的匹配
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    // 考虑 '*' 时的两种情况
                    if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
                        dp[i][j] = dp[i][j - 2];
                    } else {
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    }
                }
            }
        }

        // 返回最后字符的匹配状态
        return dp[m][n];
    }
};

int main()
{


	return 0;
}
