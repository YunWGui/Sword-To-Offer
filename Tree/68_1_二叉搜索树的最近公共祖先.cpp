/*
题目：
    68. 「二叉搜索树」的最近公共祖先  P326
描述：
    给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
地址：
    https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
备注：
    同 LeetCode-235
    https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
*/

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {  }
};

// 方法一：迭代
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while ( root ) {
            if ( p->val < root->val && q->val < root->val )
                root = root->left;
            else if ( p->val > root->val && q->val > root->val )
                root = root->right;
            else
                break;
        }

        return root;
    }
};


// 方法二：递归
class Solution_2 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( root->val < p->val && root->val < q->val )
            return lowestCommonAncestor( root->right, p, q );
        if ( root->val > p->val && root->val > q->val )
            return lowestCommonAncestor( root->left , p, q );

        return root;
    }
};

int main()
{
    

    return 0;
}