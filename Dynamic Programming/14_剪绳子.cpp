/*
题目：
	14. 剪绳子

描述：
	给你一根长度为 n 的绳子，请把绳子剪成 m 段（m、n都是整数，n > 1 并且 m > 1），每段
绳子的长度记为 k[0], k[1],...,k[m]。
	请问 k[0] X k[1] X .. X k[m] 可能的最大乘积是多少？
	例如，当绳子的长度是 8 时，我们把它剪成长度分别为 2、3、3 的三段，此时得到的最大乘积
是 18。

备注：
	同 LeetCode-343 题
*/

#include <iostream>
#include <cmath>
using namespace std;

// 方法一：动态规划
int maxProductAfterCutting_solution1(int length){
	if(length < 2)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;

	int* products = new int[length+1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;


	for(int i = 4; i <= length; ++i){
		int max = 0;
		for(int j = 1; j <= i/2; ++j){
			int product = products[j] * products[i - j];
			if(max < product)
				max = product;
		}
		products[i] = max;
	}
	int max = products[length];
	delete[] products;

	return max;
}


// 方法二：贪心算法
int maxProductAfterCutting_solution2(int length){
	if(length < 2)
		return 0;
	if(length == 2)
		return 1;
	if(length == 3)
		return 2;

	// 尽可能多地剪去长度为 3 的绳子段
	int timesOf3 = length / 3;

	// 当绳子最后长度为 4，不能再剪去长度为3的绳子段。
	// 此时更好的方法是把绳子剪成长度为2的两段，因为 2 X 2 > 3 X 1
	if(length - timesOf3 * 3 == 1)
		--timesOf3;

	int timesOf2 = (length - timesOf3 * 3) / 2;

	return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));

}

// 方法三：贪心算法
class Solution_3 {
public:
    int maxProductAfterCutting(int length) {
        if(length < 2)
            return 0;
        if(length == 2)
            return 1;
        if(length == 3)
            return 2;

        int area = 1;
        while(4 < length){
            length -= 3;
            area *= 3;
        }
        if(length == 4)
            area *= 4;
        else
            area *= length;

        return area;
    }
};

int main()
{
	cout << maxProductAfterCutting_solution2( 8 ) << endl;

	return 0;
}
