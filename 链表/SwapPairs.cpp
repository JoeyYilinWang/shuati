#include <iostream>
#include "ListNode.hpp"

class swapPairs {
public:
    ListNode* Solution(ListNode* head) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        
        while (true) {
            if (cur->next == NULL) {
                break;
                return NULL;
            }
            if (cur->next->next == NULL) {
                break;
                return cur->next;
            }

            ListNode* temp1 = cur->next;
            cur->next = cur->next->next;
            ListNode* temp2 = cur->next->next;
            cur->next->next = temp1;
            cur->next->next->next = temp2;

            cur = cur->next->next;
        }
        return dummyHead->next;
    }
};