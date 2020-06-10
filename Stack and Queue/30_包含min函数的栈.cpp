/*
题目：
	30. 包含 min 函数的栈，P165
地址：
	acwing : https://www.acwing.com/problem/content/90/
	牛客 :
描述：
	定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数。
	在该栈中，调用 min、push and pop 的时候复杂度都是 O(1).
备注：
    同 LeetCode-115 题
*/

#include <iostream>
#include <stack>
using namespace std;

// 方法一：
// 思路：除了维护基本的栈结构之外；还需要维护一个单调栈，来实现返回最小值的操作。
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stackValue;  // 实现栈的基本功能
    stack<int> stackMin;  // 返回栈的最小值
     
    MinStack() { }
    
    void push(int x) {
        stackValue.push( x );
        if ( stackMin.empty() || stackMin.top() >= x )
            stackMin.push( x );
    }
    
    void pop() {
        if ( stackValue.top() == stackMin.top() )
            stackMin.pop();
        stackValue.pop();
    }
    
    int top() {
        return stackValue.top();        
    }
    
    int getMin() {
        return stackMin.top();
    }
};

int main()
{
	

	return 0;
}