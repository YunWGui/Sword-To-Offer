/*
题目：
    11. 旋转数组的最小数字
描述：  
    把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
    输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。
    例如，数组{ 3, 4, 5, 1, 2 } 为 { 1, 2, 3, 4, 5 } 的一个旋转，该数组的最小值为 1。
备注：
    同 LeetCode-154 题
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：二分查找
int rotateArray(vector<int>& nums){
    int left = 0, right = nums.size() - 1;
    while(right - left > 1){
        int mid = (right + left) >> 1;
        if(nums[left] <= nums[mid])
            left = mid;
        else 
            right = mid;            
    }
    return nums[right];
}

int main()
{
    vector<int> target{ 2, 2, 2, 0, 1 };

    cout << rotateArray(target) << endl;   
     
    return 0;
}