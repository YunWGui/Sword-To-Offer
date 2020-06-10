/*
地址：
	acwing : https://www.acwing.com/problem/content/78/
	牛客 : https://www.nowcoder.com/practice/f78a359491e64a50bce2d89cff857eb6
    LeetCode : https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/
题目：
	62. 圆圈中最后剩下的数字  P300
描述：
	0, 1, ... , n-1 这 n 个数字排成一个圆圈，从数字 0 开始，每次从这个圆圈里删除第 m
个数字。
	求出这个圆圈里剩下的最后一个数字。
*/

#include <iostream>
#include <list>
using namespace std;

// 方法二：模拟环形链表（超时）
class Solution_2 {
public:
    int lastRemaining(int n, int m) {
        if ( n == 0 || m == 0 )
            return -1;
            
        // 不能用 vector，因为调用 erase 后，迭代器 next 会后移
        list<int> numbers;  // 用模板库中的 std::list 来模拟一个「环形链表」
        for ( int i = 0; i < n; ++i ) 
            numbers.push_back( i );
        
        list<int>::iterator current = numbers.begin();
        while ( numbers.size() > 1 ) {
            for ( int i = 1; i < m; ++i ) {
                ++current;
                if ( current == numbers.end() )  // 当扫描到链表末尾
                    current = numbers.begin();  // 将迭代器置到链表头部
            }
            list<int>::iterator next = ++current;  // 此时，current 也向后移了一格
            if ( next == numbers.end() )
                next = numbers.begin();
            
            --current;  
            numbers.erase( current );
            current = next;
        }

        return *( current );
    }
};


// 方法一：数学：约瑟夫环问题
// https://leetcode-cn.com/problems/yuan-quan-zhong-zui-hou-sheng-xia-de-shu-zi-lcof/solution/huan-ge-jiao-du-ju-li-jie-jue-yue-se-fu-huan-by-as/
class Solution {
public:
    // 迭代版
    int lastRemaining(int n, int m) {
        if ( n < 1 || m < 1 )
            return -1;

        int last = 0;  // n == 0
        for ( int i = 2; i <= n; ++i )
            last = ( last + m ) % i;

        return last;
    }
    // 递归版 
    int lastRemaining_2(int n, int m) {
        return func( n, m );
    }

    int func( int n, int m ) {
        if ( n == 1 )
            return 0;

        return ( func( n - 1, m ) + m ) % n;
    }
};

int main()
{
    int n = 5, m = 3;

    Solution solve;
    cout << solve.lastRemaining( n, m );


	return 0;
}
