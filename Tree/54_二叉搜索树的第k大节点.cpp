/*
地址：
    acwing : https://www.acwing.com/problem/content/description/66/
    牛客 : https://www.nowcoder.com/practice/ef068f602dde4d28aab2b210e859150a
    LeetCode : https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
题目：
    二叉搜索树的第 k 大节点  P269
描述：
    给定一棵二叉搜索树，请找出其中第 k 大的节点。
*/


#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};


class Solution {  // 需特别注意「边界条件」
public:
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if ( pRoot == NULL || k <= 0 )
            return NULL;

        vector<TreeNode*> temp;
        InOrder(pRoot, temp);

        if ( temp.size() < k )
            return NULL;

        return temp[k-1];
    }
    void InOrder(TreeNode* pRoot, vector<TreeNode*>& temp) {
        if ( pRoot == nullptr )
            return;

        InOrder(pRoot->left, temp);
        temp.push_back(pRoot);
        InOrder(pRoot->right, temp);
    }
};


// 解法二：从「中序遍历·迭代版」改进
class Solution_2 {
public:
    TreeNode* KthNode(TreeNode* root, int k) {
        stack<TreeNode*> S;
        int count = 1;

        if ( root == nullptr || k <= 0 )
            return nullptr;

        while ( true ) {
            if ( root ) {
                S.push(root);
                root = root->left;
            } else if ( !S.empty() ) {
                root = S.top();
                S.pop();

                if ( k == count )
                    return root;
                ++count;
                root = root->right;
            } else
                break;
        }

        return nullptr;
    }
};


int main()
{
	TreeNode* root = new TreeNode( 3 );
	root->left = new TreeNode( 1 );
	root->right = new TreeNode( 4 );
	root->left->right = new TreeNode( 2 );

	int k { 1 };
	Solution_2 solve;
	cout << solve.KthNode( root, k )->val << endl;

	return 0;
}
