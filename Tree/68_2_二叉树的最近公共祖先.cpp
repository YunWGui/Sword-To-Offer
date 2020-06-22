/*
题目：
    68.2 「二叉树」的最近公共祖先
描述：
    给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。
地址：
    https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode( int x ) : val( x ), left( nullptr ), right( nullptr ) {  }
};


// 方法一：递归
// https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/jian-dan-yi-dong-xiang-jie-ru-xia-by-yuanninesuns/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ( root == nullptr || root == p || root == q )
            return root;
        
        TreeNode* leftNode = lowestCommonAncestor( root->left, p, q );
        TreeNode* rightNode = lowestCommonAncestor( root->right, p, q );\

        if ( leftNode == nullptr )
            return rightNode;

        if ( rightNode == nullptr )
            return leftNode;
        
        return root;
    }
};

int main()
{
    

    return 0;
}