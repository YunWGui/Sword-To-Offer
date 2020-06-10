/*
地址：
    acwing : https://www.acwing.com/problem/content/55/
    LeetCode : https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
题目：
    46 把数字翻译成字符串  P231
描述：
    给定一个数字，我们按照如下规则把它翻译成为字符串：0 翻译成 "a"， 1 翻译成 "b"...，
	11 翻译成 "l"，...，25 翻译成 "z"。
    一个数可能有多个翻译。例如，12258 有 5 种不同的翻译，分别是 "bccfi"、"bwfi"、
	"bczi"、"mcfi" 和 "mzi"。
    请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
备注：
	同 LeetCode-91 题
	https://leetcode-cn.com/problems/decode-ways/
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 方法二：递归
class Solution_2 {
public:
    int translateNum(int num) {
        if ( num < 10 )  // 递归基
            return 1;
        
        int temp = num % 100;
        if ( 10 <= temp && temp <= 25 ) {
            return translateNum( num / 10 ) + translateNum( num / 100 );
        }
        else 
            return translateNum( num / 10 );
    }
};

// 方法一：动态规划
/*
https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/solution/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-hui-su-dong-tai/
思路：与「10.青蛙跳台(P77)」一样。
青蛙跳台问题：青蛙一次可以跳 1 阶，也可以跳 2 阶，求有多少种不同的方法。而这道题换成了，
每次可以选择一个数字或两个数字，用来合并成一个字符，求可以合成多少种字符串。
*/
class Solution {
public:
    int translateNum(int num) {
        string str = to_string( num );
        int len = str.size();

        int dp[len + 1];
        dp[0] = 1;
        dp[1] = 1;
        // 写法一：
        for ( int i = 2; i <= len; ++i ) {
            if ( str[i-2] == '0' || str.substr(i-2, 2) > "25" )  // 不存在 01, 02...这样的编码方式
                dp[i] = dp[i-1];
            else
                dp[i] = dp[i-1] + dp[i-2];
        }
        // 写法二：
        for ( int i = 2; i <= len; ++i ) {
            string temp = str.substr( i-2, 2 );
            if ( "10" <= temp && temp <= "25" )
                dp[i] = dp[i-1] + dp[i-2];
            else
                dp[i] = dp[i-1];
        }

        return dp[len];
    }
};


int main()
{


	return 0;
}
