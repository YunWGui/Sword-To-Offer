/*
地址：
	acwing : https://www.acwing.com/problem/content/57/
	LeetCode : https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
题目：
	48 最长不含重复字符的子字符串
描述：
	请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
	假设字符串中只包含 'a'~'z' 的字符。
	例如，在字符串 'arabcacfr' 中，最长的不含重复字符的子字符串是 'acfr'，长度为 4。
备注：
	同 LeetCode-3 题
	https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
*/

#include <iostream>
#include <map>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> M;
        int maxLen = 0;
        int lastRepeatPos = -1;

        for ( int i = 0; i < s.size(); ++i ) {
            if ( M.find(s[i]) != M.end() && lastRepeatPos < M[s[i]] )  // M 中存在字符 s[i]，且 lastRepeatPos 在字符 s[i] 之前
                lastRepeatPos = M[s[i]];
            if ( maxLen < i - lastRepeatPos )
                maxLen = i - lastRepeatPos;
            M[s[i]] = i;
        }

        return maxLen;
    }
};

// 方法二：滑动窗口




int main()
{


	return 0;
}
