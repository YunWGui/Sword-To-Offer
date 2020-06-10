/*
地址：
	acwing : https://www.acwing.com/problem/content/31/
	牛客 : https://www.nowcoder.com/practice/9023a0c988684a53960365b889ceaf5e
题目：
	8. 二叉树的下一个节点  P65
描述：
	给定一棵二叉树和其中的一个节点，如何找出「中序遍历」序列的下一个节点？
	树中的节点除了有两个分别指向左、右子节点的指针，还有一个指向父节点的指针。
参考：
 	《数据结构.邓俊辉》P129，代码 5.16
*/


#include <iostream>
using namespace std;

struct BinaryTreeNode {
    int           value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    BinaryTreeNode* parent;
    BinaryTreeNode(int data = int()) : value(data), left(nullptr), right(nullptr),
        parent(nullptr){
    }
};

// 方法一：
class Solution {
public:
    BinaryTreeNode* GetNext (BinaryTreeNode* node){
        if (node == nullptr)
            return node;                  // return nullptr;

        if (node->right != nullptr) {     // 存在右子节点
            node = node->right;
            while (node->left != nullptr) // 直到是右子树中最左侧的节点
                node = node->left;
            return node;
        }
        else {                           // 不存在右子节点
            if (node->parent == nullptr) // 且不存在父节点
                return nullptr;
            else {
                // 沿着father域一直向上找，找到第一个是其father左儿子的节点，
                // 该节点的father就是当前节点的后继。
                BinaryTreeNode* father = node->parent;
                while (father != nullptr && father->right == node) {
                    node   = father;
                    father = father->parent;
                }
                return father;
            }
        }
    }
};

// 方法二：
class Solution_2 {
public:
	BinaryTreeNode* GetNext (BinaryTreeNode* node) {
		if (node == nullptr)  // 根节点为空
			return nullptr;
		if (node->right) {  // 存在右节点
			node = node->right;
			while (node->left)
				node = node->left;
			return node;
		}
		// 省略 else 语句
		// 父节点存在且当前节点是父节点的右子节点
		while (node->parent && node->parent->right == node)
			node = node->parent;
		return node->parent;
	}

	// 基于上例改写
	BinaryTreeNode* GetNext_2 (BinaryTreeNode* node) {
		if (node == nullptr)  // 根节点为空
			return nullptr;

		BinaryTreeNode* pNext = nullptr;

		if (node->right) {  // 存在右节点
			node = node->right;
			while (node->left)
				node = node->left;
			pNext = node;
		} else {
			// 不存在「右子节点」
			// 1. 该节点是它父节点的左子节点，则它的下一个节点就是它的父节点
			// 2. 既没有右子树，且是它父节点的「右」子节点。则沿着指向父节点的指针一直
			//    向上遍历，直到找到一个是它父节点的左子节点的节点。如果这样的节点存在，
			//    那么这个节点的父节点即要找的「下一个节点」。
			while (node->parent && node->parent->right == node)
				node = node->parent;
			pNext = node->parent;
		}

		return pNext;
	}
};

int main () {

	return 0;
}
