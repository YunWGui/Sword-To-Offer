/*
地址：
	acwing :
	牛客 :
题目：
	57.1 和为 S 的数字  P280
描述：
	输入一个递增排序的数组和一个数字s，在数组中查找两个数，使用它们的和正好是s。
	如果有多对数字的和等于s，则输出任意一对即可。
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;

        while ( left < right ) {
            int sum = nums[left] + nums[right];
            if ( sum < target )
                ++left;
            else if ( target < sum )
                --right;
            else
                break;
        }

        return vector<int> { nums[left], nums[right] };
    }
};

// 方法二：
class Solution_2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {  // 双指针
        vector<int> result;

		if ( nums.size() < 2 )
			return result;

        for ( int left = 0, right = nums.size()-1; left < right; ) {
            int sum = nums[left] + nums[right];
            if ( sum < target )
                ++left;
            else if ( target < sum )
                --right;
            else {
                result.push_back( nums[left] );
                result.push_back( nums[right] );
                break;
            }
        }

        return result;
    }
};


int main()
{


	return 0;
}
