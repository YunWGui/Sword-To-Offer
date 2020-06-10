/*
题目：
	21. 调整数组顺序，使奇数位于偶数前面
描述：
	输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
	使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/


#include <iostream>
#include <vector>
using namespace std;


// 方法一：类似于起泡排序法（超时）
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int length = nums.size();
        bool sorted = false;
        while ( !sorted ) {
            sorted = true;
            for ( int i = 1; i < length; ++i ) {
                if ( nums[i-1] % 2 == 0 && nums[i] % 2 == 1 ) {
                    swap( nums[i-1], nums[i] );
                    sorted = false;
                }
            }
            --length;
        }

        return nums;
    }
};


// 方法二：「首尾」双指针
class Solution_2 {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while ( left < right ) {
            while ( left < right && nums[left] % 2 != 0 ) 
                ++left;
            while ( left < right && nums[right] % 2 == 0 )
                --right;
            if ( left < right ) {
                swap( nums[left], nums[right] );
                ++left; --right;
            }                
        }

        return nums;
    }
};

// 方法三：「快慢」双指针
class Solution_3 {
public:
    vector<int> exchange(vector<int>& nums) {
        int fast = 0, low = 0;
        while ( fast < nums.size() ) {
            if ( nums[fast] & 1 ) {  // nums[fast] 为「奇」数
                swap( nums[low], nums[fast] );
                ++low;
            }
            ++fast;
        }

        return nums;
    }
};


int main()
{
	vector<int> vec { 2,3,5,13,1,16,1,16,12,11,18,11,11,5,1,8 };

	return 0;
}
