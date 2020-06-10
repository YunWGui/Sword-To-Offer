/*
题目：
	18.2 删除链表中重复的节点  P122
描述：
	在一个排序的链表中，如何删除重复的节点？
	(a) 1 -> 2 -> 3 -> 3 -> 4 -> 4 -> 5
	(b) 1 -> 2 -> 5
地址：
	acwing: https://www.acwing.com/problem/content/27/
	牛客: https://www.nowcoder.com/practice/fc533c45b73a41b0b44ccba763f866ef
*/

#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) { }
};


// 方法二：
class Solution_2 {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode* newHead = new ListNode(0);  // 创建「哨兵节点」
        newHead->next = head;
        ListNode* curNode = newHead;
        
        while ( curNode ) {
            ListNode* nextNode = curNode->next;
            // 删除「重复」节点
            while ( nextNode && nextNode->next && nextNode->val == nextNode->next->val ) {
                ListNode* nextNextNode = nextNode->next;
                while ( nextNextNode && nextNode->val == nextNextNode->val )
                    nextNextNode = nextNextNode->next;
                nextNode = nextNextNode;
            }
            curNode->next = nextNode;
            curNode = curNode->next;
        }
        
        return newHead->next;
    }
};


// 方法一：
void DeleteDuplication(ListNode** pHead){
	if(pHead == nullptr || *pHead == nullptr)
		return;

	ListNode* pPreNode = nullptr;  // pPreNode: 当前节点的前一个节点
	ListNode* pNode = *pHead;  // pNode: 当前节点
	while(pNode != nullptr){
		ListNode* pNext = pNode->next;  // pNext: 当前节点的下一个节点
		bool isDelete = false;
		if(pNext != nullptr && pNext->val == pNode->val)
			isDelete = true;

		if( !isDelete ){
			pPreNode = pNode;
			pNode = pNode->next;
		} else {
			int value = pNode->val;  // value: 记录当前重复节点的值
			ListNode* pToBeDel = pNode;
			while(pToBeDel != nullptr && pToBeDel->val == value){
				pNext = pToBeDel->next;

				delete pToBeDel;
				pToBeDel = nullptr;

				pToBeDel = pNext;
			}
			if(pPreNode == nullptr)
				*pHead = pNext;
			else
				pPreNode->next = pNext;
			pNode = pNext;
		}
	}
}

int main()
{


	return 0;
}
