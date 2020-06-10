/*
题目：
	4. 二维数组中的查找
描述：
	在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
	请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
备注：
	同 LeetCode-240 题
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
	bool Find(int target, vector<vector<int>> array){
		// if(array.empty() || array[0].empty())  // 必须放在第一行 ？
		// 	return false;

		if(array.size() == 0)
			return false;

		int rows = array.size();        // 维度
		int columns = array[0].size();  // 列数
		int row = 0;
		int column = columns - 1;

		while(row < rows && column >= 0){
			if(target < array[row][column])
				--column;
			else if(array[row][column] < target)
				++row;
			else
				return true;
		}
		return false;
	}
};


int main()
{
	bool mark;
	int aim{ 0 };
	vector<vector<int>> nums {  // 声明二维数组
		// {1, 2, 8, 9},
		// {2, 4, 9, 12},
		// {4, 7, 10, 13},
		// {6, 8, 11, 15},
	};

	Solution solve;

	mark = solve.Find(aim, nums);

	if(mark){
		cout << aim << " in the array" << endl;
	}
	else{
		cout << aim << " not in the array" << endl;
	}

	return 0;
}
