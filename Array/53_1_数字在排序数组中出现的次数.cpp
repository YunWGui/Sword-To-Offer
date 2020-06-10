/*
地址：
	acwing : https://www.acwing.com/problem/content/description/63/
	牛客 : https://www.nowcoder.com/practice/70610bf967994b22bb1c26f9ae901fa2
题目：
	53. 数字在排序数组中出现的次数  P263
描述：
	统计一个数字在排序数组中出现的次数。
备注：
	同 LeetCode-34 题
	https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：二分查找
class Solution_2 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int index = -1;

        while ( right >= left ) {
            int mid = ( left + right ) / 2;

            if ( nums[mid] > target )
                right = mid - 1;
            else if ( nums[mid] == target ) {
                index = mid;
                break;
            }
            else
                left = mid + 1;
        }

        if ( index == -1 )
            return 0;

        int low = index, high = index;
        while ( low >= 0 && nums[low] == target )
            --low;
        while ( high < nums.size() && nums[high] == target )
            ++high;

        return ( high - low - 1 );

    }
};


// 方法二：
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if ( nums.empty() )
            return 0;

        int count = 0;

        for ( size_t i = 0; i < nums.size(); ++i ) {
            if ( target == nums[i] )
                ++count;
            if ( target < nums[i] )
                break;
        }

        return count;
    }
};

int main()
{


	return 0;
}
