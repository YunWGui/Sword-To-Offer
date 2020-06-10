/*
地址：
    牛客 : https://www.nowcoder.com/practice/91b69814117f4e8097390d107d2efbe0
    acwing : https://www.acwing.com/problem/content/43/
    LeetCode : https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
题目：
    之字形打印二叉树
描述：
    请实现一个函数，按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层
    按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
备注：
    同 LeetCode-103
    https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int    val;
    TreeNode* left;
    TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 方法二：双端队列
class Solution_2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        deque<TreeNode*> Q;
        bool flag = true;  // true : 从左往右打印，false : 从右往左打印
        
        if ( root != nullptr )
            Q.push_back( root );
        
        while ( !Q.empty() ) {
            int n = Q.size();
            TreeNode* x;
            vector<int> temp;

            while ( 0 < n ) {
                if ( flag ) {  // 前取后放：从左向右打印，所以从前边取，后边放入
                    x = Q.front();
                    Q.pop_front();
                    
                    if ( x->left ) 
                        Q.push_back( x->left );  // 下一层顺序放至队尾
                    if ( x->right )
                        Q.push_back( x->right );
                } 
                else {  // 后取前放：从右向左打印，从后边取，前边放入
                    x = Q.back();
                    Q.pop_back();

                    if ( x->right )
                        Q.push_front( x->right );  // 下一层逆序存放至队首
                    if ( x->left )
                        Q.push_front( x->left );
                }
                temp.push_back( x->val );
                --n;                
            }
            flag = !flag;
            res.push_back( temp );
        }

        return res;
    }
};

// 方法一：栈
class Solution {
public:
    vector<vector<int>> printFromTopToBottom(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> temp;
        stack<TreeNode*> levels[2];  // 辅助栈
        int current = 0;
        int next = 1;

        if ( root != nullptr )  // 根节点非空
            levels[current].push(root);

        while ( !levels[current].empty() || !levels[next].empty() ) {
            TreeNode* x = levels[current].top();
            levels[current].pop();
            temp.push_back(x->val);

            if ( current == 0 ) {
                if ( x->left )
                    levels[next].push(x->left);
                if ( x->right )
                    levels[next].push(x->right);
            } else {
                if ( x->right )
                    levels[next].push(x->right);
                if ( x->left )
                    levels[next].push(x->left);
            }

            if ( levels[current].empty() ) {
                res.push_back(temp);
                temp.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        return res;
    }
};

int main()
{


	return 0;
}
