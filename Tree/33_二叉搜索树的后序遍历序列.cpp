/*
	地址：
		acwing : https://www.acwing.com/problem/content/44/
        LeetCode : https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/
	题目：
		33. 二叉搜索树的后序遍历序列  P179
	描述：
		输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。
		如果是则返回 true，否则返回 false。
		假设输入的数组的任意两个数字都互不相同。
*/


#include <iostream>
#include <vector>
using namespace std;

// 方法一：深度优先搜索
class Solution {
public:
    vector<int> seq;
    bool verifySequenceOfBST(vector<int> sequence) {
        seq = sequence;

        return dfs(0, seq.size() - 1);
    }

    bool dfs(int left, int right) {
        if ( left >= right )
            return true;

        int curRootVal = seq[right];  // 当前根节点的值
        int k = left;  // 分界点

        while ( k < right && seq[k] < curRootVal )  // 跳过二叉搜索树的「右子树」
            ++k;

        for ( int i = k; i < right; ++i )   // 核对二叉搜索树的左子树中是否存在小于
            if ( seq[i] < curRootVal )  // curRootVal 的值，若存在，则
                return false;  // 不是二叉搜索树，返回 false。

        return dfs(left, k - 1) && dfs(k, right - 1);  // right-1 为下一个节点curRootVal 的索引
    }
};


// 方法二：
class Solution_2 {
public:
    bool verifySequenceOfBST(vector<int> sequence) {
        if ( sequence.size() == 0 )  // 边界条件，当且仅当 length == 0 时有用
            return true;

		int length = sequence.size();
		int curRootVal = sequence[length - 1];  // 当前根节点的值
        vector<int> seq_left, seq_right;

        // 在二叉搜索树中，左子树节点的值小于根节点的值
        int i = 0;
        for ( ; i < length - 1; ++i ) {
            if ( curRootVal < sequence[i] )
                break;
            seq_left.push_back(sequence[i]);
        }

        // 在二叉搜索树中，左子树节点的值大于根节点的值
        int j = i;
        for ( ; j < length - 1; ++j ) {
            if ( sequence[j] < curRootVal )
                return false;
            seq_right.push_back(sequence[j]);
        }
        
        // 判断「左子树」是不是二叉搜索树
        bool left = true;
        if ( i > 0 )  // i == 0 : 无「左子树」
            left = verifySequenceOfBST(seq_left);

        // 判断「右子树」是不是二叉搜索树
        bool right = true;
        if ( i < length - 1 )  // i == length - 1 : 无「右子树」
            right = verifySequenceOfBST(seq_right);

        return (left && right);
    }
};


int main()
{
	vector<int> test {1, 2, 5, 4, 9, 10, 7, 3, 6, 8};
	Solution solve;

	cout << solve.verifySequenceOfBST(test) << endl;

	return 0;
}
