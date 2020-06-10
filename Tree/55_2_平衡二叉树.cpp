/*
题目：
	55.2 平衡二叉树  P273
描述：
	输入一棵二叉树的根节点，判断该树是不是平衡二叉树。
	如果某二叉树中任意节点的左、右子树的深度相差不超过 1，那么它就是一棵平衡二叉树。

	    	5
	    /       \
	   3         8
	 /   \     /   \
	2     4  7      10
			/      /  \
	       6      9    11
地址：
	acwing : https://www.acwing.com/problem/content/68/
	牛客 : https://www.nowcoder.com/practice/8b3b95850edb4115918ecebdf1b4d222
	LeetCode : https://leetcode-cn.com/problems/ping-heng-er-cha-shu-lcof/
备注：
	同 LeetCode-110 题
	https://leetcode-cn.com/problems/balanced-binary-tree/
*/


#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

// 方法三：树形 DP
/* 参考《程序员代码面试指南·左程云》P148 */
struct ReturnType {
    bool isB;
    int height;
    ReturnType( bool isB, int height ) : isB( isB ), height( height ) {  }
};

class Solution_3 {
public:
    bool isBalanced(TreeNode* root) {
        return process( root ).isB;
    }

    ReturnType process( TreeNode* cur ) {
        if ( cur == nullptr )
            return ReturnType( true, 0 );
        
        ReturnType leftData = process( cur->left );
        ReturnType rightData = process( cur->right );

        int height = max( leftData.height, rightData.height ) + 1;
        bool isB = leftData.isB && rightData.isB && abs( leftData.height - rightData.height ) <= 1;

        return ReturnType( isB, height );
    }
};


// 方法一：后序遍历思想
/*
使用后序遍历的方式遍历二叉树的每个节点，那么在遍历到一个节点之前，我们就已经遍历了它的
左右子树。只要在每个节点的时候记录它的深度（某一节点的深度等于它到叶节点的路径的长度）
*/
class Solution {
public:
	bool isBalanced(TreeNode* root) {
		int depth = 0;

		return _isBalanced(root, depth);
	}
	
	bool _isBalanced(TreeNode* root, int& depth) {
		if ( root == nullptr ) {
			depth = 0;
			return true;
		}

		int leftVal, rightVal;
		if (_isBalanced(root->left, leftVal) && _isBalanced(root->right, rightVal)) {
			if ( abs( leftVal - rightVal) <= 1 ) {
				depth = 1 + (leftVal > rightVal ? leftVal : rightVal);
				return true;
			}
		}
		return false;
	}
};


// 方法二：借助 55_1 题实现的函数
// 先序遍历思想：先序遍历每一个节点，并比较左右子树高度，如果有 > 1，则返回 false
class Solution_2 {
public:
    bool isBalanced(TreeNode* root) {
        if ( root == nullptr )
            return true;

        // 求当前节点左、右子树的深度
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if ( abs(left - right) > 1 )
            return false;

        return isBalanced(root->left) && isBalanced(root->right);
    }

    int maxDepth(TreeNode* root) {
        if ( root == nullptr )
            return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        return (left > right) ? (left + 1) : (right + 1);
    }
};


int main()
{
	TreeNode *head = new TreeNode(5);
	head->left = new TreeNode(3);
	head->right = new TreeNode(8);
	head->left->left = new TreeNode(2);
	head->left->right = new TreeNode(4);
	head->right->left = new TreeNode(7);
	head->right->right = new TreeNode(10);
	head->right->left->left = new TreeNode(6);
	head->right->right->left = new TreeNode(9);
	head->right->right->right = new TreeNode(11);

	Solution solve;

	cout << solve.isBalanced(head) << endl;


	return 0;
}
