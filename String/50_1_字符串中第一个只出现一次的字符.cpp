/*
地址：
	acwing :
	牛客 :
题目：
	50 字符串中第一个只出现一次的字符  P243
描述：
	在字符串中找出第一个只出现一次的字符。
	如输入 "abaccdeff"，则输出 'b'。
*/


#include <iostream>
#include <unordered_map>
using namespace std;

// 方法一：
class Solution {
public:
    char firstUniqChar(string s) {
        char res = ' ';
        
        if ( !s.size() )
            return res;
        
        unordered_map<char, int> M;
        for ( size_t i = 0; i < s.size(); ++i ) {
            M[s[i]] += 1;
        }

        for ( size_t i = 0; i < s.size(); ++i ) {
            if ( M[s[i]] == 1) 
                return s[i];                
        }

        return res;
    }
};

// 方法二：在方法一的基础上简单的改进
class Solution {
public:
    char firstUniqChar(string s) {       
        if ( !s.size() )
            return ' ';
        
        unordered_map<char, int> M;
        for ( auto x: s ) {
            ++M[x];
        }

        for ( auto x: s ) {
            if ( M[x] == 1) 
                return x;                
        }

        return ' ';
    }
};

int main()
{
	

	return 0;
}