/*
题目：
	55. 二叉树的深度  P271
描述：
	输入一棵二叉树的根节点，求该树的深度。
	从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为
树的深度。 
				       5
			       /      \
			      3        8
				/   \    /   \
				2    4  7     10
						/     /  \
				       6     9   11
地址：
	acwing : https://www.acwing.com/problem/content/67/
	牛客 ：https://www.nowcoder.com/practice/435fb86331474282a3499955f0a41e8b
	LeetCode : https://leetcode-cn.com/problems/er-cha-shu-de-shen-du-lcof/
备注：
	同 LeetCode-104 题
	https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
*/


#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

// 方法一：递归、DFS
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if ( pRoot == nullptr )
            return 0;

        int left = TreeDepth( pRoot->left );
        int right = TreeDepth( pRoot->right );

		return 1 + max( left , right );
    }
};


// 方法二：BFS，层次遍历
class Solution_2 {
public:
    int maxDepth(TreeNode* root) {
        int ans = 0;

        if ( root == nullptr )
            return ans;

        queue<TreeNode*> Q;
        Q.push( root );
        while ( !Q.empty() ) {
            int scale = Q.size();  // 「必须」单独声明
            for ( int i = 0; i < scale; ++i ) {
                TreeNode* cur = Q.front();  Q.pop();
                if ( cur->left )
                    Q.push( cur->left );
                if ( cur->right )
                    Q.push( cur->right );
            }
            ++ans;  // 每一层 +1
        }

        return ans;
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

	cout << solve.TreeDepth(head) << endl;

	return 0;
}
