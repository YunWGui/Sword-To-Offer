/*
地址：
	acwing : https://www.acwing.com/problem/content/50/
	牛客 : https://www.nowcoder.com/practice/459bd355da1549fa8a49e350bf3df484
	LeetCode: https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
题目：
	42 连续子数组的最大和
描述：
	输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。
求所有子数组的和的最大值。
	要求时间复杂度为 O(n)
备注：
	同 LeetCode-53 题
	https://leetcode-cn.com/problems/maximum-subarray/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：动态规划
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        for ( int i = 1; i < nums.size(); ++i ) {
            if ( nums[i-1] > 0 )
                nums[i] += nums[i-1];
            // else  // nums[i-1] <= 0, 此外可省略
            //     nums[i] = nums[i];

            res = max( res, nums[i] );
            // if ( res < nums[i] )
            //     res = nums[i];
        }

        return res;
    }
};


// 方法二：滑动窗口
class Solution_2 {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = nums[0];
        int greatestSum = nums[0];

        for ( size_t i = 1; i < nums.size(); ++i ) {
            if ( curSum <= 0 )
                curSum = nums[i];
            else  // curSum >= 0
                curSum += nums[i];

            if ( greatestSum < curSum )
                greatestSum = curSum;
        }

        return greatestSum;
    }
};

int main()
{


	return 0;
}
