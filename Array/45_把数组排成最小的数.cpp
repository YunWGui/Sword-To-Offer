/*
地址：
    acwing : https://www.acwing.com/problem/content/54/
    牛客 : https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993
题目：
    45 把数组排成最小的数  P227
描述：
    输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中
最小的一个。
    例如，输入数组 {3, 32, 321}，则打印出这 3 个数字能排成的最小数字 321323。
备注：
	同 LeetCode-264 题
	https://leetcode-cn.com/problems/ugly-number-ii/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：
class Solution {
public:

    static bool strCmp(int& a, int& b) {
        if ( (to_string(a) + to_string(b) ) < ( to_string(b) + to_string(a) ) )
            return true;
        else
            return false;
    }
    string PrintMinNumber(vector<int> numbers) {
        string str;

        if ( numbers.size() == 0 )
            return str;

        sort(numbers.begin(), numbers.end(), strCmp);

        for ( size_t i = 0; i < numbers.size(); ++i ) {
            str += to_string(numbers[i]);
        }

        return str;
    }
};

// 方法二：
class Solution_2 {
public:
    string minNumber(vector<int>& nums) {
        string str;
        vector<string> vec;

        if ( !nums.size() )
            return str;

        for ( auto x: nums )
            vec.push_back( to_string(x) );
        sort( vec.begin(), vec.end(), [] (const string& a, const string& b)
             { return a + b < b + a; } );
        for ( size_t i = 0; i < vec.size(); ++i ) {
            str += vec[i];
        }

        return str;
    }
};

int main()
{


	return 0;
}
