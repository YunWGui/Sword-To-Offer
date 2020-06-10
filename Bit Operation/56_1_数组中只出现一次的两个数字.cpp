/*
地址：
	acwing : https://www.acwing.com/problem/content/69/
	牛客 : https://www.nowcoder.com/practice/e02fdb54d7524710a7d664d082bb7811
题目：
	56.1 数组中只出现一次的两个数字  P275
描述：
	一个数组里除两个数字之外，其他数字都出现了两次。
	请写程序找出这两个只出现一次的数字。
	要求时间复杂度是 O(n)，空间复杂度是 O(1)。
备注：
    同 LeetCode-260
    https://leetcode-cn.com/problems/single-number-iii/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


// 方法三：
class Solution_3 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int sum = 0;
        for ( auto x: nums )
            sum ^= x;

        int k = 0;
        while ( ((sum >> k) & 1) == 0 )
            ++k;

        int first = 0;
        for ( auto x: nums )
            if ( ( (x >> k) & 1 ) == 1)
                first ^= x;

        return vector<int>{ first, first^sum };
    }
};

// 	方法一：
class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        vector<int> res;
        unordered_map<int, int> M;

        if ( nums.size() < 2 )
            return res;

        for ( size_t i = 0; i < nums.size(); ++i ) {
            if ( M.find( nums[i] ) == M.end() )
                M[nums[i]] = 1;
            else
                M[nums[i]] += 1;
        }

        int count = 0;
        for ( size_t i = 0; i < nums.size(); ++i ) {
            if ( M[nums[i]] == 1 ) {
                res.push_back( nums[i] );
                if ( ++count == 2 )
                    break;
            }
        }

        return res;
    }
};

// 方法二：哈希表
class Solution_2 {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        int res = 0;
        for ( size_t i = 0; i < nums.size(); ++i )
            res ^= nums[i];

        int n = FindFirstBitIs1( res );
        int n1 = 0, n2 = 0;
        for ( size_t i = 0; i < nums.size(); ++i ) {
            if ( IsBit1( nums[i], n ) )
                n1 ^= nums[i];
            else
                n2 ^= nums[i];
        }

        return vector<int>{ n1, n2 };
    }

    int FindFirstBitIs1( int num ) {
        int i;
        for ( i = 0; i < 8*sizeof(int); ++i ) {
            if ( ( num & ( 1 << i ) ) == 0 )
                continue;
            else
                break;
        }

        return i;
    }

    bool IsBit1(int num, int pos) {
        return num & (1 << pos);
    }
};

int main()
{


	return 0;
}
