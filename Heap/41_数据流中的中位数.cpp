/*
地址：
	acwing : https://www.acwing.com/problem/content/88/
	牛客 :
	LeetCode : https://leetcode-cn.com/problems/shu-ju-liu-zhong-de-zhong-wei-shu-lcof/
题目：
	41 数据流中的中位数  P214
描述：
	如何得到一个数据流中的中位数？
	如果从数据流中读出奇数个数值，那么中位数就是所有数据排序之后位于中间的数据。如果从
	数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
备注：
	同 LeetCode-295 题
	https://leetcode-cn.com/problems/find-median-from-data-stream/
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 方法一：堆
class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    void addNum(int num) {
        maxHeap.push( num );
        if ( minHeap.size() && maxHeap.top() > minHeap.top() ) {
            int maxe = maxHeap.top(), mine = minHeap.top();
            maxHeap.pop(), minHeap.pop();

            maxHeap.push(mine), minHeap.push(maxe);
        }

        if ( maxHeap.size() > minHeap.size() + 1 ) {
            minHeap.push( maxHeap.top() );
            maxHeap.pop();
        }
    }

    double findMedian() {
        if ( ( maxHeap.size() + minHeap.size() ) & 1 )
            return maxHeap.top();
        else
            return ( maxHeap.top() + minHeap.top() ) / 2.0;
    }
};

int main()
{


	return 0;
}
