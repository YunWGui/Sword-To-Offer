/*
地址：
	acwing: https://www.acwing.com/problem/content/29/
	牛客: https://www.nowcoder.com/practice/6f8c901d091949a5837e24bb82a731f2
题目：
	20. 表示数值的字符串
描述：
	请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
	例如，字符串 "+100"、"5e2"、"-123"、"3.1416" 及 "-1E-16" 都表示数值，但 "12e"、
"1a3.14"、"1.2.3"、"+-5" 及 "12e+5.4" 都不是。
注意:
	小数可以没有整数部分，例如.123等于0.123；
	小数点后面可以没有数字，例如233.等于233.0；
	小数点前面和后面可以有数字，例如233.666;
	当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
	当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4;

备注：
    同 LeetCode-65 题
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    // 数字的格式可以用 A[.[B]][e|EC] 或者 .B[e|EC] 表示，其中 A 和 C 都是
    // 整数（可以有正负号，也可以没有），而 B 是一个无符号整数
    bool isNumber(string s) {
        if ( s.empty() )
            return 0;
        
        int i = 0;
        while ( s[i] == ' ' )  // 忽略段前空格
            ++i;

        bool isValidNumber = scanInteger( s , i );

        if ( s[i] == '.' ) {
            ++i;
            // 在小数里，可能没有数值的整数部分，因此 A 部分不是必需的
            // 1. 小数可以没有整数部分，如 .123 == 0.123；
            // 2. 小数点后面可以没有数字，如 233. == 233.0；
            // 3. 小数点前面和后面可以都数字，如 233.666
            isValidNumber = scanUnsignedInteger( s, i ) || isValidNumber;
        }

        if ( s[i] == 'e' || s[i] == 'E' ) {
            ++i;
            // 下面一行代码用 && 的原因：
            // 1. 不 e or E 前面没有数字时，整个字符串不能表示数字，如 .e1, e1；
            // 2. 当 e or E 后面没有整数时，整个字符串不能表示数字，如 12e、12e+5.4
            isValidNumber = isValidNumber && scanInteger( s, i );
        }

        while ( s[i] == ' ' )  // 忽略段后空格
            ++i;

        return isValidNumber && i == s.size();
    }

    bool scanInteger( const string& s, int& i ) {
        if ( s[i] == '-' || s[i] == '+' )
            ++i;
        
        return scanUnsignedInteger( s, i );
    }

    bool scanUnsignedInteger( const string& s, int& i ) {
        int temp = i;
        while ( i < s.size() && '0' <= s[i] && s[i] <= '9' )
            ++i;
        
        return i > temp;
    }
};


int main()
{


	return 0;
}
