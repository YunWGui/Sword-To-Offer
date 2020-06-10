/*
题目：
	15. 二进制中 1 的个数
描述：  
	请实现一个函数，输入一个整数，输出该数二进行表示中 1 的个数。
备注：
	同 LeetCode-191 题
*/

#include <iostream>
using namespace std;

// 方法三：
class Solution_3 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while ( n ) {
            ++count;
            n = n & ( n - 1 );  // 把一个速度减去 1，再和原整数做「与运算」，会把
								// 该整数最右边的 1 变成 0。
        }

        return count;
    }
};

// 方法二：
class Solution_2 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        unsigned int flag = 1;
        while ( flag ) {
            if ( n & flag )
                ++count;
            flag = flag << 1;
        }

        return count;
    }
};

// 方法一：
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while ( n > 0 ) {
            if ( n & 1 )
                ++count;
            n >>= 1;
        }

        return count;
    }
};

int main()
{
	

	return 0;
}
