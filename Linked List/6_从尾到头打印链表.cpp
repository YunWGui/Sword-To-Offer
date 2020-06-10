/*
题目：
	6. 从尾到头打印链表  P58
描述：
	输入一个链表的头节点，从尾到头反过来打印出每个节点的值
备注：
	LeetCode-206 反转链表
	https://leetcode-cn.com/problems/reverse-linked-list/
*/


#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 方法二：「就地」反转链表，
class Solution_2 {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> res;
        if ( head == nullptr )
            return res;

        ListNode* prevNode = nullptr;  // 当前节点的上一个节点
        ListNode* curNode = head;  // 当前节点

        while ( curNode ) {  // 直到 curNode == nullptr，此时 prevNode 指向原链表的末尾
            ListNode* nextNode = curNode->next;  // 「临时存放」当前节点的下一个节点

            curNode->next = prevNode;  // curNode 指向 prevNode，故，自动断开 curNode->next
									   // 指向 nextNode 的指针
            prevNode = curNode;  // 移动
            curNode = nextNode;  // 移动
        }

        while ( prevNode ) {
            res.push_back( prevNode->val );
            prevNode = prevNode->next;
        }

        return res;
    }
};


// 方法一：常规
class Solution {
public:
    vector<int> printListReversingly(ListNode* head) {
		vector<int> res;
		while(head){
			res.push_back(head->val);
			head = head->next;
		}
		// reverse(res.begin(), res.end());
		// return res;
		return vector<int>(res.rbegin(), res.rend());
    }
};




int main()
{
	Solution solve;
	ListNode* head = new ListNode(1);
	ListNode*tail = head;
	for(int i = 2; i < 4; i++){
		tail->next = new ListNode(i);
		tail = tail->next;
	}
	ListNode* cur = head;
	while(cur != NULL){
		cout << cur->val << " ";
		cur = cur->next;
	}
	cout << endl;
	vector<int> temp;
	temp = solve.printListReversingly(head);
	// print(temp);

	return 0;
}
