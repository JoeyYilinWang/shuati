#include "ListNode.hpp"
#include <stack>

class reverseList {
public:

    // 双指针法
    ListNode* Solution1(ListNode* Head) {
        ListNode* pre = NULL;
        ListNode* cur = Head;
        
        ListNode* temp;
        while (temp != NULL) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    // 递归方法，从前往后
    ListNode* reverse(ListNode* pre, ListNode* cur) {
        if (cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;

        return reverse(cur, temp);
    }
    ListNode* Solution2(ListNode* Head) {
        return reverse(NULL, Head);
    }

    // 递归方法，从后往前
    ListNode* Solution3(ListNode* Head) {
        if (Head == NULL) return NULL;
        if (Head->next == NULL) return Head;

        // 递归调用，翻转第二个节点开始之后的链表
        ListNode* last = Solution3(Head->next);
        // 翻转头结点与第二个节点的指向
        Head->next->next = Head;
        // 此时头结点为尾节点，next需要指向NULL
        Head->next = NULL;
        return last;
    }

    // 头插法
    ListNode* Solution4(ListNode* head) {
        // 创建虚头结点
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = nullptr;

        // 遍历所有节点
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* temp = cur->next;
            // 头插法
            cur->next = dummyHead->next;
            dummyHead->next = cur;
            cur = temp;
        }
        return dummyHead->next;
    }

    // 使用栈
    // 时间复杂度: O(n)
    // 空间复杂度: O(n)
    ListNode* Solution5(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;

        stack<ListNode*> stack;
        ListNode* cur = head;
        while (cur != NULL) {
            stack.push(cur);
            cur = cur->next;
        }

        // 创建虚拟头节点
        ListNode* dummyHead = new ListNode(-1);
        cur = dummyHead;
        while (!stack.empty()) {
            ListNode* node = stack.top();
            stack.pop();
            cur->next = node;
            cur = cur->next;
        }
        cur->next = NULL;
        return dummyHead->next;
    }
};