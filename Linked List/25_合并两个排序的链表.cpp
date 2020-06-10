/*
题目：
	25. 合并两个排序的链表，P145
地址：
	acwing : https://www.acwing.com/problem/content/34/
	牛客 : https://www.nowcoder.com/practice/d8b6b4358f774294a89de2a6ac4d9337
描述：
	输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
备注：
	同 Leetcode-21 题，
	地址：https://leetcode-cn.com/problems/merge-two-sorted-lists/
*/


#include <iostream>
using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

// 解法一：递归
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )
            return l2;
        if ( l2 == nullptr )
            return l1;

        ListNode* pMergedHead = nullptr;

        if ( l1->val < l2->val ) {
            pMergedHead = l1;
            pMergedHead->next = merge( l1->next, l2 );
        } else {
            pMergedHead = l2;
            pMergedHead->next = merge( l1, l2->next );
        }

        return pMergedHead;
    }
};

// 解法二：蛮力法
class Solution_2 {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if ( l1 == nullptr )
            return l2;
        if ( l2 == nullptr )
            return l1;

        ListNode* head = new ListNode(0);
        ListNode* tail = head;

        while ( l1 && l2 ) {
            if ( l1->val < l2->val ) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        if ( l1 == nullptr )
            tail->next = l2;
        if ( l2 == nullptr )
            tail->next = l1;

        ListNode* res = head;
        res = head->next;
        head->next = nullptr;
        delete head;

        return res;
    }
};

int main()
{


	return 0;
}
