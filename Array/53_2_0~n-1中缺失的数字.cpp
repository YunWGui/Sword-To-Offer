/*
地址：
	acwing : https://www.acwing.com/problem/content/64/
	牛客 :
题目：
	53.2 0 ~ n-1 中缺失的数字  P266
描述：
	一个长度为 n-1 的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围 0 ~ n-1
之内。
	在范围 0 ~ n-1 内的 n 内的 n 个数字中有具只有一个数字不在该数组中，请找出这个数字。
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        if ( nums.empty() )
            return 0;

        int length = nums.size();
        for ( int i = 0; i < length; ++i ) {
            if ( nums[i] != i )
                return i;
        }
		// 当 nums[length-1] == length-1 即 最后一个数缺失时
		// [0, 1, 2, 3, 4] 缺失 5
        return length;
    }
};

// 方法二：二分查找
class Solution_2 {
public:
    int missingNumber(vector<int>& nums) {
        if ( nums.empty() )
            return -1;

        int start = 0;
        int length = nums.size();
        int end = length - 1;
        while ( start <= end ) {
            int mid = ( start + end ) >> 1;
            if ( nums[mid] != mid ) {
                if ( mid == 0 || nums[mid-1] == mid-1)
                    return mid;
                else
                    end = mid - 1;
            }
            else
                start = mid + 1;
        }

        if ( start == length )
            return length;

        return -1;

    }
};

int main()
{


	return 0;
}
