/*
地址：
	acwing :
	LeetCode : https://leetcode-cn.com/problems/dui-lie-de-zui-da-zhi-lcof/
题目：
	59.2 队列的最大值  P292
描述：
	请定义一个队列并实现函数 max 得到队列里的最大值。
	要求函数 max、push_back and pop_back 的时间复杂度都是 O(1).
*/

#include <iostream>
#include <queue>
#include <deque>
using namespace std;

class MaxQueue {
public:
    queue<int> Q;
    deque<int> D;  // 双端队列

    MaxQueue() { }

    int max_value() {
        if ( D.empty() )
            return -1;

        return D.front();
    }

    void push_back(int value) {
        Q.push( value );
        while ( !D.empty() && D.back() < value )
            D.pop_back();
        D.push_back( value );
    }

    int pop_front() {
        if ( Q.empty() )
            return -1;

        if ( !D.empty() && D.front() == Q.front() )
            D.pop_front();

        int temp = Q.front();
        Q.pop();

        return temp;
    }
};


int main()
{


	return 0;
}
