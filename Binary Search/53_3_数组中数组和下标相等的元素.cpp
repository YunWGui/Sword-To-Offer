/*
地址：
    acwing : https://www.acwing.com/problem/content/65/
    牛客 :
题目：
    53.3 数组中数值和下标相等的元素  P267
描述：
    假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实现一个函数，找出
数组中任意一个数值等于其下标的元素。
    例如，在数组 { -3, -1, 1, 3, 5 } 中，数字 3 和它的下标相等。
*/

#include <iostream>
#include <vector>
using namespace std;


// 方法二：二分查找
class Solution_2 {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while ( left <= right ) {
            int mid = left + ( ( right - left ) >> 1 );
            
            if ( mid < nums[mid] )
                right = mid - 1;
            else if ( nums[mid] < mid )
                left = mid + 1;
            else 
                return mid;
        }
        
        return -1;
    }
};

// 方法一：顺序遍历
class Solution {
public:
    int getNumberSameAsIndex(vector<int>& nums) {
        int i = 0;
        for ( i = 0; i < (int)nums.size(); ++i ) {
            if ( i == nums[i] )
                break;
        }
        
        return i < (int)nums.size() ? i : -1;
    }
};

int main()
{
    vector<int> nums;

    return 0;
}
