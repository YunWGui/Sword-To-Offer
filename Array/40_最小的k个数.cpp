/*
地址：
	acwing : https://www.acwing.com/problem/content/49/
	牛客 : https://www.nowcoder.com/practice/6a296eb82cf844ca8539b57c23e6e9bf
题目：
	40. 最小的 K 个数  P209
描述：
	输入 n 个整数，找出其中最小的 k 个数。
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 方法一：排序
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        sort( arr.begin(), arr.end() );

        return vector<int> ( arr.begin(), arr.begin()+k );
    }
};

int main()
{

	return 0;
}
