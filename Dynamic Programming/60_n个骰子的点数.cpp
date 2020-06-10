/*
地址：
	acwing :
	牛客 :
题目：
	60. n 个骰子的点数  P294
描述：
	把 n 个骰子扔在地上，所有骰子朝上一面的点数之和为 s。
	输入 n ，打印出 s 的所有可能的值出现的概率。
*/


#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


// 方法一：动态规划


// 方法二：
class Solution {
public:
    vector<double> twoSum(int n) {
        std::map<int, int> map;
        for (int i = 1; i <= 6; ++i)
            ++map[i];

        std::map<int, int> temp;
        for (int i = 2; i <= n; i++) {
            for (const auto& p : map)
                for (int j = 1; j <= 6; ++j)
                    temp[p.first + j] += p.second;
            map = temp;
            temp.clear();
        }

        vector<double> result;
        for (const auto& p : map)
            result.emplace_back(p.second / pow(6, n));

        return result;
    }
};


int main()
{


	return 0;
}
