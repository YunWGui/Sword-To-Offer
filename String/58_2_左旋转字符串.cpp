/*
地址：
	acwing :
	牛客 :
题目：
	58.2 左旋转字符串
描述：
	字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
*/

#include <iostream>
using namespace std;

// 方法一：
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return s.substr(n, s.length() - 1) + s.substr(0,n);
    }
};

// 方法二：
class Solution_2 {
public:
    string reverseLeftWords(string s, int n) {
        int length = s.size();
        for ( int i = 0; i < n; ++i )
            s += s[i];
        for ( int i = 0; i < length; ++i )
            s[i] = s[n+i];
        s.resize( length );

        return s;
    }
};

int main()
{


	return 0;
}
