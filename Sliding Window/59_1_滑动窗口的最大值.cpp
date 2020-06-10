/*
地址：
	acwing : https://www.acwing.com/problem/content/75/
	牛客 :
题目：
	59.1 滑动窗口的最大值  P288
描述：
	给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。
备注：
	同 LeetCode-239 题
	https://leetcode-cn.com/problems/sliding-window-maximum/
*/


#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// 方法二：维护一个「双向单调队列」，队列中放元素的「下标」。
// 依次遍历数组，每次队头就是每个滑动窗口的最大值所在「下标」。
// https://www.acwing.com/solution/acwing/content/853/
class Solution_2 {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> Q;

        for ( int i = 0; i < (int)nums.size(); ++i ) {
            // 判断队头是否需要「出队」
            if ( !Q.empty() && i - k >= Q.front() )
                Q.pop_front();
            // 维护队列单调递减性：最大值的下标位于队首
            while ( !Q.empty() && nums[Q.back()] < nums[i] )
                Q.pop_back();

            Q.push_back( i );

            if ( i >= k-1 )
                res.push_back( nums[Q.front()] );  // 取队首元素作为窗口最大元素
        }

        return res;
    }
};

// 方法一：
class Solution {
public:
    vector<int> maxInWindows(vector<int>& nums, int k) {
        vector<int> maxInWindows;

        if ( nums.size() >= k && k >= 1 ) {
            deque<int> index;

            for ( size_t i = 0; i < k; ++i ) {
                while ( !index.empty() && nums[i] >= nums[index.back()] )
                    index.pop_back();

                index.push_back( i );
            }

            for ( size_t i = k; i < nums.size(); ++i ) {
                maxInWindows.push_back( nums[index.front()] );

                while ( !index.empty() && nums[i] >= nums[index.back()] )
                    index.pop_back();

                if ( !index.empty() && index.front() <= (int)(i - k) )
                    index.pop_front();

                index.push_back( i );
            }
            maxInWindows.push_back( nums[index.front()] );
        }

        return maxInWindows;
    }
};

int main()
{


	return 0;
}
