/*
地址：
	acwing :
	牛客 :
题目：
	61. 扑克牌中的顺子  P298
描述：
	从扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这 5 张牌是不是连续的。
	2~10 为数字本身，A 为 1，J 为 11，Q 为 12，K 为 13，而大、小王可以看成任意数字。
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

/*
方法二：非排序

有一串连续的数字（无重复），这串数字中最大值为 m ，最小值为 n ，问你这串数字中一共有多少个数字？
答案：m - n + 1

同样，如果我们能够知道 5 张扑克牌中的最大值 maxValue 和最小值 minValue，
那我们就知道，要使它为顺子需要 maxValue - minValue + 1 张牌。
	在查找 maxValue 和 minValue 过程中，跳过大小王 0。
	如果 maxValue - minValue + 1 > 5，说明题目给的 5 张牌不足以构成顺子，返回 false。
		即使里面有大小王，也不够用来填补使它构成顺子。
	如果 maxValue - minValue + 1 <= 5，说明 5 张牌足以构成顺子，返回 true。
		里面的大小王填补在合适位置即可。
同时，我们再定义一个标志数组判断是否有重复数字，发现重复数字直接返回 false 即可。
*/
class Solution_2 {
public:
    bool isStraight(vector<int>& nums) {
        bool res[15];
        memset( res, 0, sizeof(res) );

        int maxValue = 0, minValue = 14;
        for ( int x: nums ) {
            if ( 0 == x )
                continue;

            if ( res[x] )
                return false;

            res[x] = true;
            maxValue = max( maxValue, x );
            minValue = min( minValue, x );
        }

        return maxValue - minValue + 1 <= 5;
    }
};

// 方法一：排序
class Solution {
public:
    bool isStraight(vector<int>& nums) {
		sort( nums.begin(), nums.end() );
		int zero = 0;
		for ( size_t i = 0; i < nums.size()-1; ++i ) {
			if ( 0 == nums[i] ) {
				++zero;
				continue;
			}
			if ( nums[i] == nums[i+1] )
				return false;

			zero -= nums[i+1] - nums[i] - 1;
		}

		return zero >= 0;
	}
};

int main()
{


	return 0;
}
