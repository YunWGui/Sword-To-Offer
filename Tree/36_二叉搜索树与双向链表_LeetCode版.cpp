/*
地址：
	LeetCode : https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
题目：
	36.二叉搜索树与双向链表 - LeetCode 版  P191
描述：
	输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的「循环」双向链表。
	要求：不能创建任何新的节点，只能调整树中节点指针的指向。
备注：
	同 LeetCode-426
	https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
*/

#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 方法一：深度优先搜索
class Solution {
public:
    Node* preNode = NULL;

    Node* treeToDoublyList(Node* root) {
        if ( root == NULL )
            return NULL;

        inOrder( root );

        Node* head = root;  // 头节点
        while ( head && head->left )
            head = head->left;
        
        Node* tail = root;  // 尾节点
        while ( tail && tail->right )
            tail = tail->right;
        
		// 首尾相连
        head->left = tail;
        tail->right = head;
        
        return head;
    }
	
	// 中序遍历
    void inOrder( Node* curNode ) {
        if ( curNode == NULL )
            return;
        
        inOrder( curNode->left );
        
        curNode->left = preNode;
        if ( preNode )
            preNode->right = curNode;
        preNode = curNode;

        inOrder( curNode->right );
    }
};

int main()
{
	

	return 0;
}