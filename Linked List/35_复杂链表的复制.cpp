/*
地址：
    acwing : https://www.acwing.com/problem/content/89/
    牛客 : https://www.nowcoder.com/practice/f836b2c43afc4b35ad6adc41ec941dba
题目：
    35. 复杂链表的复制，P187
描述：
    请实现函数 ComplexListNode* Clone( ComplexListNode* pHead ), 复制一个复杂链表。
    在复杂链表中，每个节点除了有一个 m_pNext 指针指向下一个节点，还有一个 m_pSibling
指针指向链表中的任意节点或者 nullptr。

备注：
    同 LeetCode-138 题
    https://leetcode-cn.com/problems/copy-list-with-random-pointer/
*/

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next, *random;
    ListNode(int x) : val(x), next(NULL), random(NULL) {}
};

class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        CloneNodes( head );
        ConnectSiblingNodes( head );

        return ReconnectNodes( head );
    }

    void CloneNodes(ListNode* head) {
        ListNode* pNode = head;

        while ( pNode ) {
            ListNode* pCloned = new ListNode(0);
            // 复制节点
            pCloned->val = pNode->val;
            pCloned->next = pNode->next;
            pCloned->random = nullptr;

            // 将复制的节点链接在原节点后面
            pNode->next = pCloned;
            pNode = pCloned->next;
        }
    }

    void ConnectSiblingNodes(ListNode* head) {
        ListNode* pNode = head;

        while ( pNode ) {
            ListNode* pCloned = pNode->next;  // pCloned 是 pNode 的下一个节点

            if ( pNode->random ) {
                pCloned->random = pNode->random->next;
            }
            pNode = pCloned->next;
        }
    }

    ListNode* ReconnectNodes(ListNode* head) {
        ListNode* pNode = head;
        ListNode* pClonedHead = nullptr;
        ListNode* pClonedNode = nullptr;

        if ( pNode ) {
            pClonedHead = pClonedNode = pNode->next;
            pNode->next = pClonedNode->next;
            pNode = pNode->next;  // 原节点从 A -> B
        }
        while ( pNode ) {
            pClonedNode->next = pNode->next;
            pClonedNode = pClonedNode->next;

            pNode->next = pClonedNode->next;
            pNode = pNode->next;
        }

        return pClonedHead;
    }
};


int main()
{


    return 0;
}
