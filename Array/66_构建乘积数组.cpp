/*
地址：
	acwing :
	牛客 :
	LeetCode : https://leetcode-cn.com/problems/gou-jian-cheng-ji-shu-zu-lcof/
题目：
	66. 构建乘积数组  P312
描述：
	给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i] 
	= A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
	不能使用「除法」。
备注：
	同 LeetCode238
	https://leetcode-cn.com/problems/product-of-array-except-self/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：暴力法（超时）
/* 时间复杂度：O(n^2) */
class Solution {
public:
    vector<int> constructArr(vector<int>& a) {
        vector<int> B;

        for ( int i = 0; i < (int)a.size(); ++i ) {
            int res = 1;
            for ( int j = 0; j < (int)a.size(); ++j ) {
                if ( j == i )
                    continue;
                res *= a[j];
            }
            B.push_back( res );
        }

        return B;
    }
};

// 方法二：
/* 时间复杂度：O(n) 
思路：由定义 B[i] = A[0] X A[1] X ... X A[i - 1] X A[i + 1] X ... X[n - 1]
      将上式拆解，有：C[i] = A[0] X A[i] X ... A[i - 1], D[i] = A[i + 1] X A[i + 2] X ... X[n - 1]
*/

class Solution_2 {
public:
    vector<int> constructArr(vector<int>& a) {
        if ( a.empty() )
            return vector<int>{};
            
        int length = a.size();  
        // 创建「辅助数组」
        vector<int> C( length );  // C[i] = C[i - 1] x A[i - 1]
        vector<int> D( length );  // D[i] = D[i + 1] X A[i + 1]

        C[0] = 1;
        for ( int i = 1; i < length; ++i ) 
            C[i] = C[i - 1] * a[i - 1];

        D[length - 1] = 1;
        for ( int j = length - 2; j >= 0; --j ) 
            D[j] = D[j + 1] * a[j + 1];

        vector<int> B( length );
        for ( int i = 0; i < length; ++i ) 
            B[i] = C[i] * D[i];
        
        return B;        
    }
};


int main()
{
	

	return 0;
}
