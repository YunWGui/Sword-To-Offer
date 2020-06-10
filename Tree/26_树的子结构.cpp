/*
地址：
    牛客 : https://www.nowcoder.com/practice/6e196c44c7004d15b1610b9afca8bd88
    acwing : https://www.acwing.com/problem/content/35/
    LeetCode : https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
题目：
    26. 树的子结构  P148
描述：
    输出两棵二叉树 A 和 B， 判断 B 是不是 A 的子结构。
备注：
    类似于 LeetCode-572 另一个树的子树
    https://leetcode-cn.com/problems/subtree-of-another-tree/
*/


#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    double    val;
    TreeNode* left;
    TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 方法一：递归
/* 时间复杂度： O( nm )，空间复杂度：O( m )
*/
class Solution {
public:
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        bool res = false;

		// 此处相当于「前序」遍历
        if ( A != nullptr && B != nullptr ) {
            if ( A->val == B->val )  // 根节点值相等
                res = DoesTree1HaveTree2( A, B );

            if ( !res )  // 遍历 A 的左子树
                res = isSubStructure( A->left, B );
  
            if ( !res )  // 遍历 A 的右子树
                res = isSubStructure( A->right, B );        
        }

        return res;
    }

    bool DoesTree1HaveTree2( TreeNode* A, TreeNode* B ) {
        if ( B == nullptr )
            return true;
        if ( A == nullptr )  // 此时，B != nullptr 
            return false;
        if ( A->val != B->val )
            return false;
        
        return DoesTree1HaveTree2( A->left, B->left ) && 
               DoesTree1HaveTree2( A->right, B->right );
    }
};


int main ()
{

    return 0;
}
