/*
地址：
	acwing : https://www.acwing.com/problem/content/62/
	LeetCode : https://leetcode-cn.com/problems/liang-ge-lian-biao-de-di-yi-ge-gong-gong-jie-dian-lcof/
题目：
    52 两个链表的第一个公共节点
描述：
    输入两个链表，找出它们的第一个公共节点。
备注：
	同 LeetCode-160 题
	https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next() {}
};


#include <iostream>
#include <stack>
using namespace std;

/*
解法三：双指针法
headA : A B C D E F
headB : G X E F
	A B C D E F, G X E F
	G X E F, A B C D E F
*/
class Solution_3 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ( !headA || !headB )
            return nullptr;

        ListNode* curA = headA;
        ListNode* curB = headB;

        while ( curA != curB ) {
            if ( !curA )
                curA = headB;
            else
                curA = curA->next;

            if ( !curB )
                curB = headA;
            else
                curB = curB->next;
        }

        return curA;
    }
};

// 解法一：
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;

        while ( curA ) {
            ++lenA;
            curA = curA->next;
        }
        while ( curB ) {
            ++lenB;
            curB = curB->next;
        }

        int delta = 0;
        if ( lenA > lenB ) {  // headA 更长
            delta = lenA - lenB;
            curA = headA;
            curB = headB;
        } else {  // headB 更长
            delta = lenB - lenA;
            curA = headB;
            curB = headA;
        }

        while ( delta ) {
            curA = curA->next;
            --delta;
        }

        while ( curA ) {
            if ( curA == curB )
                return curA;
            curA = curA->next;
            curB = curB->next;
        }

        return nullptr;
    }
};

// 解法二：
class Solution_2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if ( !headA || !headB )
            return nullptr;

        stack<ListNode*> stackA;
        stack<ListNode*> stackB;
        ListNode* cur = nullptr;

        while ( headA ) {
            stackA.push( headA );
            headA = headA->next;
        }

        while ( headB ) {
            stackB.push( headB );
            headB = headB->next;
        }

        while ( stackA.size() && stackB.size() ) {
            ListNode* prtA = stackA.top();
            ListNode* prtB = stackB.top();

            if ( prtA == prtB ) {
                cur = prtA;
                stackA.pop();
                stackB.pop();
            }
            else
                break;
        }

        return cur;
    }
};


int main()
{


	return 0;
}
