#include <iostream>
#include "ListNode.hpp"

using namespace std;

class detectCycle {
public:
    ListNode* solution(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // 快慢指针相遇
            if (slow == fast) {
                ListNode* index1 = fast;
                ListNode* index2 = slow;
                while (index1 != index2) {
                    index1 = index1->next;
                    index2 = index2->next;
                }

                return index2;
            }
        } 

        return NULL;
    }
};