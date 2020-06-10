/*
 * 题目：
 *      23. 链表中环的入口节点，P139
 * 地址：
 *      acwing : https://www.acwing.com/problem/content/86/
 *      牛客 : https://www.nowcoder.com/practice/253d2c59ec3e4bc68da16833f79a38e4
 * 解析：
 *      https://www.acwing.com/solution/acwing/content/741/
 * 描述：
 *      如果一个链表中包含环，如何找出环的入口节点？
 * 备注：
 *      同 LeetCode-142 题
 *          https://leetcode-cn.com/problems/linked-list-cycle-ii/
 */


#include <iostream>
using namespace std;

struct ListNode {
    int       val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {  }
};

// 方法一：双指针 - 快慢指针
class Solution {
public:
    ListNode *entryNodeOfLoop(ListNode *head) {
        // 链表为空或只存在一个节点
        if ( head == nullptr || head->next == nullptr )
            return nullptr;
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        while ( fast != nullptr && fast->next != nullptr ) {
            slow = slow->next;
            fast = fast->next->next;
            
            if ( slow == fast )
                break;
        }
        
        if ( fast == nullptr || fast->next == nullptr )  // 不存在环状链表
            return nullptr;
            
        slow = head;
        while ( slow != fast ) {
            slow = slow->next;
            fast = fast->next;
        }
        
        return slow;
    }
};

int main (){
    return 0;
}
