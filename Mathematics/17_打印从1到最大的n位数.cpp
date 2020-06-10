/*
地址：
	牛客：
	acwing：
题目：
	17. 打印从 1 到最大的 n 位数
描述：
	输入数字 n，按顺序打印出从 1 到最大的 n 位十进行数。比如输入 3，则打印出 1、2、3
	一直到最大的 3 位数 999。
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        if ( n <= 0 )
            return res;
        
        unsigned int limit = 1;
        while ( n-- ) {
            limit *= 10;
        }          

        unsigned int i = 1; 
        while ( i < limit ) {
            res.push_back( i++ );
        }

        return res;
    }
};
