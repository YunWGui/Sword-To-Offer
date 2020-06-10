/*
地址：
	acwing : https://www.acwing.com/problem/content/description/73/
	牛客 :
题目：
	58.1 翻转单词顺序  P284
描述：
	输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
	为简单起见，标点符号和普通字母一样处理。
	例如，输入字符串"I am a student."，则输出"student. a am I"。
备注：
	同 LeetCode-151 题
	https://leetcode-cn.com/problems/reverse-words-in-a-string/
*/

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

// 方法二：「从后往前」遍历字符串 s，将每个单词不断拼接到 res 的尾部。
class Solution_2 {
public:
    string reverseWords(string s) {
        string res = "";
        int low, high = s.size() - 1;

        while ( high >= 0 ) {
            while ( high >= 0 && s[high] == ' ' )
                --high;
            if ( high < 0 )
                return res;

            low = high - 1;
            while ( low >= 0 && s[low] != ' ' )
                --low;

            if ( res != "" )
                res += " ";
            res += s.substr( low+1, high-low );
            high = low - 1;
        }

        return res;
    }
};

// 方法三：就地修改。先将整个字符串整个翻转一次，再分别翻转每一个单词。
class Solution_3 {
public:
    string reverseWords(string s) {
        reverse( s.begin(), s.end() );
        int len = 0;

        for ( size_t i = 0; i < s.size(); ++i ) {
            if ( s[i] != ' ' ) {
                if ( len != 0 )
                    s[len++] = ' ';

                size_t j = i;
                while ( j < s.size() && s[j] != ' ' )
                    s[len++] = s[j++];
                reverse( s.begin() + len - (j - i), s.begin() + len );
                i = j;
            }
        }
        s.resize(len);

        return s;
    }
};

// 方法一：
class Solution {
public:
    string reverseWords(string s) {
        stack<string> strStack;
        string str = "";

        for ( size_t i = 0; i < s.size(); ++i ) {
            if ( s[i] != ' ' )
                str += s[i];
            else if ( str != "" ) {  // 禁止 "" 入栈
                strStack.push( str );
                str = "";
            }
        }
        if ( str != "" )
            strStack.push( str );

        str = "";
        while ( !strStack.empty() ) {
            str += strStack.top();
            strStack.pop();

            if ( !strStack.empty() )
                str += " ";
        }

        return str;
    }
};

int main()
{


	return 0;
}
