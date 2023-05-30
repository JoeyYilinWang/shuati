#include <iostream>
#include "ListNode.hpp"

class RemoveNthFromEnd {
public:

    // 计算总数法
    ListNode* Solution1(ListNode* head, int k) {
        if (k <= 0) {
            return NULL;
        }
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* fast = dummyHead;
        ListNode* slow = dummyHead;

        int count = 0;
        while (fast->next != NULL) {
            count++;
            fast = fast->next;
        }

        if (k>count) {
            return NULL;
        }

        for (int i = 1; i <= count - k; i++) {
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return dummyHead->next;
    }
};