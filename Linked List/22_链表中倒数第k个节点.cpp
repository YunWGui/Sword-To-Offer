/*
题目：
	22. 链表中倒数第 K 个节点，P134
地址：
	acwing : https://www.acwing.com/problem/content/32/
	牛客 : https://www.nowcoder.com/practice/529d3ae5a407492994ad2a246518148a
描述：
	输入一个链表，输出该链表中倒数第 K 个节点。
	为了符合大多数人的习惯，本题从 1 开始计数，即链表的尾节点是倒数第 1 个节点。
	例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表
的倒数第 3 个节点是值为 4 的节点。
*/


#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 解法三：双指针
class Solution_3 {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        if (pListHead == NULL || k <= 0)
            return NULL;

        ListNode* first = pListHead;
        ListNode* second = pListHead;
        int count = 0;

        while ( first->next ) {  // 考虑到「求倒数第一个节点」，
                                 // 故不能使用 first != nullptr 作为判断条件
            ++count;
            first = first->next;
            if (count >= k)
                second = second->next;
        }
        if (count < k-1)
            return NULL;
            
        return second;
    }
};

// 方法一：
class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int record = 0;
        for (auto p = pListHead; p; p = p->next)
            ++record;
        
        if (k > record)
            return NULL;

        ListNode* p = pListHead;
        for (int i = 0; i < record - k; ++i)
            p = p->next;
        
        return p;
    }
};

// 方法二：使用「栈」
class Solution_2 {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
		if (pListHead == NULL || k <= 0)
			return NULL;

		stack<ListNode*> S;
        ListNode* first = pListHead;
        int record = 0;

        while(first) {
            S.push(first);  // 入栈
            first = first->next;
            ++record;
        }

        if (k > record)
            return NULL;
        while (k > 1) {
            S.pop();  // 出栈
            --k;
        }
        return S.top();

    }
};


int main()
{


	return 0;
}
