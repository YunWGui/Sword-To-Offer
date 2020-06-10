/*
题目：
	7.重建二叉树  P62
描述：
	输入某二叉树的「前序遍历」和「中序遍历」的结果，请重建该二叉树。
	假设输入的前序遍历和中序遍历的结果中不含重复的数字。
	例如，输入前序遍历序列{1, 2, 4, 7, 3, 5, 6, 8}和中序遍历{4, 7, 2, 1, 5, 3, 8, 6},
	则重建如图2.6所示的二叉树并输出它的头节点。
地址：
	acwing : https://www.acwing.com/problem/content/23/
	牛客 : https://www.nowcoder.com/practice/8a19cbe657394eeaac2f6ea9b0f6fcf6?tpId=13
	LeetCode : https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
备注：
	同 LeetCode-105
	https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int     val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {
    }
};

// 方法二：深度优先搜索 - DFS
class Solution_2 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if ( preorder.empty() || inorder.empty() )
            return nullptr;

        int idx = 0;  // 下标、索引

        return dfs( preorder, inorder, 0, preorder.size() - 1, idx );
    }

    TreeNode* dfs( vector<int>& preorder, vector<int>& inorder, int left, int right, int& idx ) {
        int pivot = 0;  // 分界点
		// 在「中序遍历」中定位分界点，即：preorder[idx] == inorder[pivot] 的点
        while ( pivot <= right ) {  
            if ( preorder[idx] == inorder[pivot] )
                break;
            ++pivot;
        }

        TreeNode* curNode = new TreeNode( inorder[pivot] );
        if ( left <= pivot-1 ) {
            ++idx;
            curNode->left = dfs( preorder, inorder, left, pivot-1, idx );
        }
        if ( pivot+1 <= right ) {
            ++idx;
            curNode->right = dfs( preorder, inorder, pivot+1, right, idx );
        }

        return curNode;
    }
};


// 方法一：递归
class Solution {
public:
	TreeNode* buildTree (vector<int>& pre, vector<int>& in) {
	    if (pre.size() == 0 || in.size() == 0)
	        return NULL;

	    TreeNode *root = new TreeNode(pre[0]);  // 「前序」遍历，首元素作为根节点

		vector<int> pre_left, pre_right;  // 前序遍历左段、右段
		vector<int> in_left, in_right;  // 中序遍历左段、右段

	    size_t count_left = 0;
	    for (size_t i = 0; i < in.size(); i++) {
	        if (in[i] == pre[0])  // 在中序遍历序列中定位 i 的位置
	            break;
	        count_left++;
	    }

	    for (size_t i = 1; i < pre.size(); i++) {
	        if (i <= count_left)
	            pre_left.push_back(pre[i]);  // pre 左段加入 pre_left
	        else
	            pre_right.push_back(pre[i]);  // pre 右段加入 pre_right
	    }

	    for (size_t i = 0; i < in.size(); i++) {
	        if (i < count_left)
	            in_left.push_back(in[i]);  // in 左段加入 in_left
	        else if (i > count_left)
	            in_right.push_back(in[i]);  // in 右段加入 in_right
	    }
		// 递归
	    root->left  = buildTree(pre_left, in_left);
	    root->right = buildTree(pre_right, in_right);

	    return root;
	}

	// 用「后序遍历」的方式打印二叉树
	void PrintBinaryTreePostOrder (TreeNode* root){
	    if (root == NULL)
	        return;
		// postOrder
	    PrintBinaryTreePostOrder(root->left);
	    PrintBinaryTreePostOrder(root->right);
	    cout << root->val << " ";
	}
};


int main ()
{
	Solution solve;
    vector<int> pre { 1, 2, 4, 7, 3, 5, 6, 8 };
    vector<int> in { 4, 7, 2, 1, 5, 3, 8, 6 };
	// vector<int> pre {1, 4, 6};
	// vector<int> in {4,1, 6};

    TreeNode* root = solve.buildTree(pre, in);

    solve.PrintBinaryTreePostOrder(root);
    cout << endl;

    return 0;
}
