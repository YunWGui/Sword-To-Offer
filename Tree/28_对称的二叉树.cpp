/*
	地址：
		牛客：
		acwing：https://www.acwing.com/problem/content/38/
        LeetCode : https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/
	题目：
		28. 对称的二叉树
	描述：
		请实现一个函数，用来判断一棵二叉树是不是对称的。
		如果一棵二叉树和它的镜像一样，那么对称的。
    备注：
        同 LeetCode-101 题
        https://leetcode-cn.com/problems/symmetric-tree/
*/

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

// 方法一：深度优先搜索 - 递归
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
		if (root == nullptr)
			return true;

		return isMirror(root->left, root->right);
    }
	
	bool isMirror(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot1 == nullptr && pRoot2 == nullptr)  // 如果两个节点都为 nullptr
			return true;
		if (pRoot1 == nullptr || pRoot2 == nullptr)  // 其中有一个节点为 nullptr
			return false;

		// 两个节点都不为 nullptr，比较两个节点的值
		return (pRoot1->val == pRoot2->val) && isMirror(pRoot1->left, pRoot2->right)
				&& isMirror(pRoot1->right, pRoot2->left);  // 短路求值
	}
};

// 方法二：广度优先搜索 - 迭代
class Solution_2 {
public:
    bool isSymmetric(TreeNode* root) {
        if ( root == nullptr )
            return true;
        
        queue<TreeNode*> Q;
        Q.push( root->left );
        Q.push( root->right );
        
        while ( !Q.empty() ) {
            TreeNode* temp1 = Q.front(); Q.pop();
            TreeNode* temp2 = Q.front(); Q.pop();

            if ( temp1 == nullptr && temp2 == nullptr )  // 已抵达「叶子节点」
                continue;
            if ( temp1 == nullptr || temp2 == nullptr )
                return false;
            if ( temp1->val != temp2->val )
                return false;

            Q.push( temp1->left );
            Q.push( temp2->right );

            Q.push( temp1->right );
            Q.push( temp2->left );
        }

        return true;
    }
};

int main()
{


	return 0;
}
