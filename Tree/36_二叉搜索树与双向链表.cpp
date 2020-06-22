/*
地址：
	acwing : https://www.acwing.com/problem/content/87/
	牛客 : https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5
题目：
	36.二叉搜索树与双向链表  P191
描述：
	输入一颗二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
	要求：不能创建任何新的节点，只能调整树中节点指针的指向。
*/

#include <iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x ) : val( x ), left( nullptr ), right( nullptr ) {  }
};


// 方法一：中序遍历
// https://www.acwing.com/solution/content/7465/
class Solution {
public:
    TreeNode* preNode = NULL;  // 当前节点的前一个节点
    
    TreeNode* convert(TreeNode* root) {
        inOrder( root );
        
        while ( root && root->left )
            root = root->left;
        
        return root;
    }
    
	// 「中序」遍历
    void inOrder( TreeNode* curNode ) {
        if ( curNode == NULL )
            return;
        
        inOrder( curNode->left );  // 左
        
		// 中
        curNode->left = preNode;
        if ( preNode )
            preNode->right = curNode;
        preNode = curNode;
        
        inOrder( curNode->right );  // 右
    }
};

int main()
{
	

	return 0;
}