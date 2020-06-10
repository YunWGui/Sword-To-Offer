/*
题目：
	31. 栈的压入、弹出序列
描述：
	输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序。
	假设压入栈的所有数字均不相等。
	1.如果下一个弹出的数字刚好是栈顶数字，那么直接弹出
	2.如果下一个弹出的数字不在栈顶，则把压栈序列中还没有入栈的数字压入辅助栈，直到把下一
	个需要弹出的数字压入栈顶为止
	3.如果所有数字都压入栈后仍然没有找到下一个弹出的数字，那么该序列不可能是一个弹出序列。
备注：
	同 LeetCode-946 题
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 方法一：
class Solution {
public:
	bool isPopOrder(vector<int> pushV, vector<int> popV){
		if(pushV.empty() || popV.empty())
			return pushV.empty() && popV.empty();
		if(pushV.size()!=popV.size())
			return false;

		int popId = 0;
		stack<int> stackData;

		for(int pushId = 0; pushId < pushV.size(); ++pushId){
			stackData.push(pushV[pushId]);
			while(!stackData.empty() && stackData.top() == popV[popId]){
				stackData.pop();
				++popId;
			}
		}
		
		return stackData.empty() ? true : false;
	}
};


int main()
{
	// vector<int> pushV {1, 2, 3, 4, 5};
	// vector<int> popV {4, 5, 3, 2, 1};
	// vector<int> popV {4, 3, 5, 1, 2};
	vector<int> pushV, popV;  // 当 pushV, popV 均为空时
	Solution solve;

	cout << solve.isPopOrder(pushV, popV) << endl;

	return 0;
}
