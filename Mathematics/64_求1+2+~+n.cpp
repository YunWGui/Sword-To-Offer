/*
地址：
	acwing :
	牛客 :
    LeetCode : https://leetcode-cn.com/problems/qiu-12n-lcof/
题目：
	64. 求 1 + 2 + ... + n
描述：
	求 1 + 2 + ... + n，要求不能使用乘除法、for、while、if、else、switch、case 等
    关键字及条件判断语句 (A ? B : C)。
*/

/* 解析：1 + 2 + ... + n = ( n * (n+1) ) / 2 */

#include <iostream>
using namespace std;


// 方法二：构造一个矩阵，返回矩阵大小的二分之一
class Solution_2 {
public:
    int sumNums(int n) {

        char a[n][n+1];  // 1 + 2 + ... + n = ( n * (n+1) ) / 2
						 // n * (n + 1) 的值始终为「偶数」
						 // sizeof( a ) = n * (n + 1)
        return ( sizeof(a) >> 1 );
    }
};


// 方法一：递归
/* 时间复杂度：O(n)  空间复杂度：O(n) */
class Solution {
public:
    int sumNums(int n) {
        int res = n;

        ( n > 0 ) && ( res += sumNums( n - 1 ) );

        return res;
    }
};


int main()
{


	return 0;
}
