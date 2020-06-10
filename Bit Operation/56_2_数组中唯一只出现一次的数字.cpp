/*
地址：
	acwing : https://www.acwing.com/problem/content/70/
	牛客 :
题目：
	56.2 数组中唯一只出现一次的数字  P278
描述：
	在一个数组中除了一个数字只出现一次之外，其他数组都出现了三次。
	请找出那个只出现一次的数字。
备注：
    同 LeetCode-137 题
    https://leetcode-cn.com/problems/single-number-ii/
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 方法二: 状态机 没看懂...
class Solution_2 {
public:
    int singleNumber(vector<int>& nums) {
        int one=0,two=0;
        for(auto x:nums) {
            one=(one^x)&~two;
            two=(two^x)&~one;
        }
        return one;
    }
};

// 方法一：
class Solution {
public:
    int findNumberAppearingOnce(vector<int>& nums) {
        if ( nums.size() < 4 )
            return 0;

        vector<int> counts( 32, 0 );

        for ( int i = 0; i < nums.size(); ++i ) {
            unsigned int bitMask = 1;
            for ( int j = 31; j > -1; --j ) {
                int bit = nums[i] & bitMask;
                if ( bit != 0 )
                    counts[j] += 1;
                bitMask <<= 1;
            }
        }

        int res = 0;
        for ( int i = 0; i < 32; ++i ) {
            res <<= 1;
            res += counts[i] % 3;
        }

        return res;
    }
};

// 方法三：哈希表
class Solution_3 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> M;

        if ( nums.size() < 3 )
            return 0;
        
        for ( int num : nums )
            ++M[num];
        
        int res = 0;
        for ( auto iter = M.begin(); iter != M.end(); ++iter )
            if ( iter->second == 1 ) {
                res = iter->first;
                break;
            }
                
        return res;                
    }
};


int main()
{


	return 0;
}
