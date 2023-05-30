#include <iostream>

using namespace std;

struct ListNode {
    int val; 
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:
    ListNode* _dummyHead = new ListNode(0);
    int _size = 0;


    // 获取索引为index的值
    int get(int index);
    bool addAtHead(int val);
    bool addAtTail(int val);
    bool addAtIndex(int index, int val);
    bool deleteAtIndex(int index);
};



int MyLinkedList::get(int index) {
    if (index > (_size - 1) || index < 0) {
        return -1;
    }

    ListNode* cur = _dummyHead;
    
    int count = 0;
    while (count <= index) {
        cur = cur->next;
        ++count;
    }
    return cur->val;
}

bool MyLinkedList::addAtHead(int val) {
    ListNode* newNode = new ListNode(val);
    newNode->next = _dummyHead->next;
    _dummyHead->next = newNode;
    _size++;

    return true;
}

bool MyLinkedList::addAtTail(int val) {
    ListNode* cur = _dummyHead;

    // 定位到链表最后一个元素
    while (cur->next != NULL) {
        cur = cur->next;
    }

    ListNode* newNode = new ListNode(val);
    cur->next = newNode;
    _size++;

    return true;
}

bool MyLinkedList::addAtIndex(int index, int val) {
    if (index > _size) {
        return false;
    }

    if (index <= 0) {
        addAtHead(val);
        return true;
    }

    if (index == _size) {
        addAtTail(val);
        return true;
    }

    int count = 0;
    
    ListNode* cur = _dummyHead;
    while (count < index) {
        cur = cur->next; // 定位到要插入index元素的前一个元素
    }
    ListNode* newNode = new ListNode(val);
    newNode->next = cur->next;
    cur->next = newNode;
    _size++;
    return true;
}

bool MyLinkedList::deleteAtIndex(int index) {
    if (index < 0 || index >= _size) 
        return false;
    int count = 0;

    ListNode* cur = _dummyHead;
    while (count < index) {
        cur = cur->next;
    }

    ListNode* temp = cur->next;
    cur->next = cur->next->next;
    delete temp;
    
    _size--;
    return true;
}