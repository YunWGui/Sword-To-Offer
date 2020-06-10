/*
地址：
	acwing :
	牛客 :
题目：
	57.2 和为 S 的连续正数序列  P282
描述：
	输入一个正数 S，打印出所有和为 S 的连续正数序列（至少含有两个数）。
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法三：暴力法
class Solution_3 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if ( target < 3 )
            return res;
        
        int limit = target>>1;
        int sum = 0;
        for ( int left = 1; left <= limit; ++left ) {
            for ( int right = left;  ; ++right ) {
                sum += right;
                if ( sum > target ) {
                    sum = 0;
                    break;
                } else if ( sum == target ) {
                    vector<int> vec;
                    for ( int i = left; i <= right; ++i )
                        vec.emplace_back( i );
                    res.emplace_back( vec );
                    sum = 0;
                    break;
                }
                // sum < target 的情况，直接进入下一个循环
            }
        }

        return res;
    }
};


// 方法二：数学 - 等差数列求和公式
class Solution_2 {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if ( target < 3 )
            return res;

        vector<int> vec;
        for ( int left = 1, right = 2; left < right;  ) {
            int curSum = ( (left + right) * (right - left + 1) ) / 2;  // 等差数列求和公式
            if ( curSum == target ) {
                for ( size_t i = left; i <= right; ++i ) 
                    vec.push_back( i );
                res.push_back( vec );
                vec.clear();
                ++left;
            } else if ( curSum < target ) {
                ++right;
            } else 
                ++left;
        }

        return res;
    }
};

// 方法一：滑动窗口
class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> res;
        if ( target < 3 )
            return res;
        
        int smallNum = 1, bigNum = 2;
        int curSum = smallNum + bigNum;

        while ( smallNum < bigNum ) {
            while ( curSum < target ) {
                ++bigNum;
                curSum += bigNum;
            }
            while ( target < curSum ) {
                curSum -= smallNum;
                ++smallNum;
            }
            if ( curSum == target ) {
                vector<int> vec;
                for ( int i = smallNum; i <= bigNum; ++i ) 
                    vec.push_back( i );
                res.push_back( vec );

                curSum -= smallNum;
                ++smallNum;               
            }
        }

        return res;
    }
};

int main()
{


	return 0;
}
