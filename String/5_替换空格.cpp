// 请实现一个函数，把字符串中的每个空格替换成 "%20"。
// 例如，输入 "We are happy.", 则输出 "We%20are%20happy."。

// 分析：直接插入 %20 会越界。

#include <iostream>
using namespace std;

// 方法一：不产生额外空间，O(n)
class Solution {
public:
	string replaceSpaces(string& str){
		int len = 0;  // 扩容后的数组长度
		for(auto x: str)
			if(x == ' ')
				len += 3;
			else
				++len;
		int orLen = str.size();  // 数组原始长度
		str.resize(len);  // 扩容
		while(orLen >= 0 && len > orLen){
			if(str[orLen] == ' '){
				str[len--] = '0';
				str[len--] = '2';
				str[len--] = '%';
			}
			else
				str[len--] = str[orLen];
			--orLen;
		}
		return str;
	}
};

// 方法二：会产生额外空间
class Solution_2 {
public:
	string replaceSpaces(string& str){
		string res;
		for(auto x: str)
			if(x == ' ')
				res += "%20";
			else
				res += x;
		return res;
	}
};


int main()
{
	string st = "We are happy.";

	Solution solve;

	cout << solve.replaceSpaces(st) << endl;

	return 0;
}
