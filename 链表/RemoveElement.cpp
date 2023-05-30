#include <iostream>
#include "ListNode.hpp"

class removeElements {
public:

    // 使用原来链表直接操作
    ListNode* Solution1(ListNode* head, int val) {
        
        // 删除头结点
        while (head != NULL && head->val == val) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }

        // 删除非头结点
        // 此时头结点一定不是目标值
        ListNode* cur = head;
        while (cur != NULL && cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }
        return head;
    }

    // 使用虚拟头结点
    ListNode* Solution2(ListNode* head, int val) {
        ListNode* virNode = new ListNode(0);
        virNode->next = head;
        ListNode* cur = virNode;

        while(cur->next != NULL) {
            if (cur->next->val == val) {
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
            }
            else {
                cur = cur->next;
            }
        }

        head = virNode->next;
        delete virNode;
        return head;
    }
};