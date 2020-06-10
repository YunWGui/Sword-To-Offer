/*
地址：
	acwing : https://www.acwing.com/problem/content/61/
	牛客 : https://www.nowcoder.com/practice/96bd6684e04a44eb80e6a68efc0ec6c5
题目：
    51 数组中的逆序对  P249
描述：
    在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
    输入一个数组，求出这个数组中的逆序对的总数。
    例如，在数组 {7, 5, 6, 4} 中，一共存在 5 个逆序对，分别是 (7, 6)、(7, 5)、(7, 4)、
(6, 4) 和 (5, 4)。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：DFS，深度优先搜索
class Solution {
public:
	int reversePairs (vector<int>& nums) {
		return dfs(nums, 0, nums.size());
	}

    int dfs (vector<int> & nums, int left, int right){
        if (right - left <= 1)	return 0;

        int mid = (left + right) >> 1;
        int res = dfs(nums, left, mid) + dfs(nums, mid, right);
        sort(nums.begin() + left, nums.begin() + mid);
        for (int i = mid; i < right; ++i)
            res += nums.begin() + mid - upper_bound(nums.begin() + left, nums.begin() + mid, nums[i]);
        return res;
    }
};

// 方法二：归并排序
/*
思路：
	1、分解数组，直到全部拆分为长度为 1 的子数组
	2、一边合并相信的子数组，一边统计逆序对的数目
*/
class Solution_2 {
public:
    int reversePairs(vector<int>& nums) {
        if ( nums.empty() )
            return 0;

        vector<int> vec ( nums );

        return mergeSort( nums, vec, 0, nums.size() - 1 );
    }

    int mergeSort( vector<int>& nums, vector<int>& vec, int start, int end ) {
        if ( start == end ) {
            vec[start] = nums[start];
            return 0;
        }

        int length = (end - start)>>1;
        int left = mergeSort( vec, nums, start, start + length );  // 交换 vec, nums 的顺序！！
        int right = mergeSort( vec, nums, start + length + 1, end );

        int i = start + length;
        int j = end;
        int indexVec = end;
        int count = 0;
        while ( i >= start && j >= start + length + 1 ) {
            if ( nums[i] > nums[j] ) {
                count += j - start - length;
                vec[indexVec--] = nums[i--];
            } else {
                vec[indexVec--] = nums[j--];
            }
        }
        for ( ; i >= start; --i )
            vec[indexVec--] = nums[i];
        for ( ; j >= start + length + 1; --j )
            vec[indexVec--] = nums[j];

        return left + right + count;
    }
};


int main()
{
	vector<int> nums { 7, 5, 6, 4 };

	Solution solve;

	cout << solve.reversePairs( nums ) << endl;

	return 0;
}
