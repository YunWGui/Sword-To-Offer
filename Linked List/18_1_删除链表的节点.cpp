/*
题目：
	18.1 在 O(1) 时间内删除链表节点  P119
描述：
	给定单向链表的头指针和一个节点指针，定义一个函数在 O(1) 时间内删除该节点。
地址：
	acwing: https://www.acwing.com/problem/content/85/
*/

#include <iostream>
using namespace std;

struct ListNode {
	int m_nValue;
	ListNode* m_pNext;
};


// 方法一：
void DeleteNode(ListNode** pListHead, ListNode* pToDeleted){
	if( !pListHead || !pToDeleted )
		return;
	// 要删除的节点不是尾节点
	if(pToDeleted->m_pNext != nullptr){
		ListNode* pNext = pToDeleted->m_pNext;
		pToDeleted->m_nValue = pNext->m_nValue;
		pToDeleted->m_pNext = pNext->m_pNext;

		delete pNext;
		pNext->m_pNext = nullptr;
	}
	// 链表只有一个节点，删除头节点（尾节点）
	else if (*pListHead == pToDeleted){
		delete pToDeleted;
		pToDeleted = nullptr;
		*pListHead = nullptr;
	}
	// 链表中有多个节点，删除尾节点
	else {
		ListNode* pNode = *pListHead;
		while(pNode->m_pNext != pToDeleted)
			pNode = pNode->m_pNext;
		pNode->m_pNext = nullptr;

		delete pToDeleted;
		pToDeleted = nullptr;
	}
}

int main()
{


	return 0;
}
