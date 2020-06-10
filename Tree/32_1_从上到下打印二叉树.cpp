/*
地址：
	牛客 : https://www.nowcoder.com/practice/7fe2212963db4790b57431d9ed259701
	acwing : https://www.acwing.com/problem/content/41/
	LeetCode : https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
题目：
	不分行从上到下打印二叉树
描述：
	从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
类别：
	BFS，广度优先搜索
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    double    val;
    TreeNode* left;
    TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> res;
		queue<TreeNode*> temp;

		if(root != nullptr)
			temp.push(root);

		while( !temp.empty() ) {
			TreeNode* x = temp.front();  // 引用队首节点
			temp.pop();  // 删除队首节点
			res.push_back(x->val);

			if( x->left )
				temp.push(x->left);
			if( x->right )
				temp.push(x->right);
		}

		return res;
	}
};

int main()
{



	return 0;
}
