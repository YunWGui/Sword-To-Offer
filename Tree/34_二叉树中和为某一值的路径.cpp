/*
地址：
    牛客 : https://www.nowcoder.com/practice/b736e784e3e34731af99065031301bca
    acwing : https://www.acwing.com/problem/content/45/
题目：
    二叉树中和为某一值的路径  P182
描述：
    输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。
    从树的「根节点」开始往下一直到「叶节点」所经过的节点形成一条路径。
备注：
    同 LeetCode-113 题
    https://leetcode-cn.com/problems/path-sum-ii/
*/


#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

// 方法一：回溯法
class Solution {
public:
    vector<vector<int>> findPath(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> path;
        int currentSum = 0;

        if ( root != nullptr )
            _findPath(root, sum, path, currentSum, res);

        return res;
    }

	// 如果是「叶节点」，并且路径上节点值的和等于输入的值，则打印出这条路径
    void _findPath(TreeNode* root, int sum, vector<int>& path, int currentSum,
				   vector<vector<int>>& res) {
        currentSum += root->val;
        path.push_back(root->val);

        bool isLeafNode = (root->left == nullptr) && (root->right == nullptr);  // 是叶节点
        if ( currentSum == sum && isLeafNode ) {
            res.push_back(path);
        }
        
		// 如果不是叶节点，则搜索有它的子节点
        if ( root->left != nullptr )
            _findPath(root->left, sum, path, currentSum, res);

        if ( root->right != nullptr )
            _findPath(root->right, sum, path, currentSum, res);
		
        // 在返回父节点之前，在路径上删除当前节点
        path.pop_back();
    }
};


int main()
{


	return 0;
}
