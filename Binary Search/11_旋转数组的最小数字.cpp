/*
题目：
    11. 旋转数组的最小数字
描述：  
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
    例如，数组{ 3, 4, 5, 1, 2 } 为 { 1, 2, 3, 4, 5 } 的一个旋转，该数组的最小值为 1。
地址：
    https://leetcode-cn.com/problems/xuan-zhuan-shu-zu-de-zui-xiao-shu-zi-lcof/
备注：
    同 LeetCode-154 寻找旋转排序数组中的最小值 II
    https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/submissions/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        if ( nums.empty() )
            return 0;
        
        int left = 0, right = nums.size() - 1;
        while ( left < right ) {
            int mid = left + ( ( right - left ) >> 1 );
            if ( nums[mid] < nums[right] )
                right = mid;
            else if ( nums[mid] == nums[right] )
                --right;
            else if ( nums[left] <= nums[mid] )
                left = mid + 1;
        }

        return nums[left];
    }
};

int main()
{
    Solution solve;
    vector<int> target{ 2, 2, 2, 0, 1 };

    cout << solve.findMin(target) << endl;   
     
    return 0;
}