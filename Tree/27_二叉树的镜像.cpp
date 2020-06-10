/*
地址：
	牛客：https://www.nowcoder.com/practice/564f4c26aa584921bc75623e48ca3011
	acwing：https://www.acwing.com/problem/content/37/
	LeetCode : https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
题目：
	27. 二叉树的镜像  P157
描述：
	请完成一个函数，输入一棵二叉树，该函数输出它的镜像。
备注：
	同 LeetCode-226 题
	https://leetcode-cn.com/problems/invert-binary-tree/
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

/*
	思路：
		先「前序」遍历这棵树的每个节点，如果遍历到的节点有子节点，就交换它的两个子节点。
		当交换完所有非叶节点的左、右子节点之后，就得到树的镜像。
*/

// 方法一：深度优先搜索 - 递归
class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if ( root == nullptr )
            return root;

        mirror( root );

        return root;
    }

    void mirror( TreeNode* root ) {        
        if ( root->left == nullptr && root->right == nullptr )  // 此节点为「叶子节点」
            return;
        
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        if ( root->left )
            mirror( root->left );
        
        if ( root->right )
            mirror( root->right );
    }
};


// 方法二：广度优先搜索（层次遍历） - 迭代
class Solution_2 {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        if ( !root )
            return nullptr;
        
        queue<TreeNode*> Q;
        Q.push( root );
        while ( !Q.empty() ) {
            TreeNode* temp = Q.front(); Q.pop();
            
            swap( temp->left, temp->right );

            if ( temp->left )
                Q.push( temp->left );
            if ( temp->right )
                Q.push( temp->right );
        }

        return root;
    }
};

int main()
{


	return 0;
}
