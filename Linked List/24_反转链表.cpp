/*
题目：
	24. 反转链表，P142
地址：
	acwing : https://www.acwing.com/problem/content/33/
	牛客 : https://www.nowcoder.com/practice/75e878df47f24fdc9dc3e400ec6058ca
描述：
	定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
备注：
    同 LeetCode-206 题
    https://leetcode-cn.com/problems/reverse-linked-list/
*/

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {
    }
};

// 方法一：使用「栈」
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if ( head == nullptr || head->next == nullptr )
            return head;

        stack<ListNode*> S;
        ListNode* curNode = head;
        while ( curNode ) {
            S.push( curNode );
            curNode = curNode->next;
        }

        curNode = S.top();
        S.pop();
        ListNode* res { curNode };
        while ( !S.empty() ) {
            curNode->next = S.top();
            S.pop();
            curNode = curNode->next;
        }
        curNode->next = nullptr;
        
        return res;
    }   
};

// 方法三：递归
// 解析：https://leetcode-cn.com/problems/reverse-linked-list/solution/dong-hua-yan-shi-206-fan-zhuan-lian-biao-by-user74/
class Solution_3 {
public:
    ListNode* reverseList(ListNode* head) {
        // 递归终止条件是当前为空，或下一个节点为空
        if ( head == nullptr || head->next == nullptr )
            return head;
        // 这里的 tail 就是最后一个节点
        // 如果链表是 1->2->3->4->5，那么此时 tail = 5
        // head = 4, head->next = 5, head->next->next = nullptr
        ListNode* tail = reverseList( head->next );
        // head->next->next 就是 5->4
        head->next->next = head;
        // 防止链表循环，需要将 head->next 置空
        head->next = nullptr;
        // 每层递归函数都返回 tail,也就是最后一个节点
        return tail;
    }
};


// 方法二：迭代
// 输入：        1 -> 2 -> 3 -> 4 -> 5 -> NUll
// 输出：NULL <- 1 <- 2 <- 3 <- 4 <- 5
class Solution_2 {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* prevNode = nullptr;
        ListNode* curNode = pHead;

        while ( curNode ) {
            ListNode* nextNode = curNode->next;  // 保存当前节点的下一个节点

            curNode->next = prevNode;  // 反转指针，使指针指向前一个节点

            prevNode = curNode;  // 移向下一个节点
            curNode = nextNode;  // 移向下一个节点
        }
        return prevNode;
    }
};


int main()
{


	return 0;
}
