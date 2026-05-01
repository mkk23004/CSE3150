#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "node.h"
#include <iostream>

// Phase 1: Raw Pointer Implementation
class RawLinkedList {
private:
    RawNode* head;
    RawNode* tail;
public:
    RawLinkedList() : head(nullptr), tail(nullptr) {}
    ~RawLinkedList(); // Requires manual deletion
    void push_back(int val);
    void display_forward();
};

// Phase 2: Unique Pointer Implementation
class UniqueLinkedList {
private:
    std::unique_ptr<UniqueNode> head;
    UniqueNode* tail;
public:
    UniqueLinkedList() : head(nullptr), tail(nullptr) {}
    void push_back(int val);
    void display_forward();
    // Destructor is automatic!
};

// Phase 3 & 4: Shared/Weak Pointer Implementation
class SharedLinkedList {
private:
    std::shared_ptr<SharedNode> head;
    std::shared_ptr<SharedNode> tail;
public:
    SharedLinkedList() : head(nullptr), tail(nullptr) {}
    void push_back(int val);
    void push_front(int val);
    void display_forward();
    void display_backward();
};

#endif
