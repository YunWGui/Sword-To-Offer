/*
地址：
    acwing : https://www.acwing.com/problem/content/48/
    牛客 : https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163

题目：
    39. 数组中出现次数超过一半的数字  P205

描述：
    数组中一个数字出现的次数超过数组长度的一半，请找出这个数字。
    例如，输入一个长度为 9 的数组 {1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字 2 在数组中
出现了 5 次，超过数组长度的一半，因此输出 2。如果不存在，则输出 0

备注：
    同 LeetCode-169 题
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;


// 方法二：哈希表
class Solution_2 {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> hashMap;

        for ( int i: nums ) {
            ++hashMap[i];
            if ( hashMap[i] == ( (nums.size() + 1)>>1) ) 
                return i;
        }

        return -1;
    }
};

// 方法一：
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if ( numbers.size() == 1 )
            return numbers[0];

        int length = numbers.size() / 2;
        int count = 1;

        sort ( numbers.begin(), numbers.end() );

        for ( size_t i = 0; i < numbers.size() - 1; ++i )
            for ( size_t j = i + 1; j < numbers.size(); ++j ) {
                if ( numbers[i] == numbers[j] ) {
                    ++count;
                    continue;
                }
                if ( length < count )
                    return numbers[i];
                else
                    count = 1;
            }
        return 0;  // 如果不存在，则输出 0
    }
};


int main()
{


	return 0;
}
