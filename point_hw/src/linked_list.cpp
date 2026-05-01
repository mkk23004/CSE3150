#include "../include/linked_list.h"

// --- PHASE 1: RAW ---
RawLinkedList::~RawLinkedList() {
    RawNode* current = head;
    while (current) {
        RawNode* next = current->next;
        delete current;
        current = next;
    }
}

void RawLinkedList::push_back(int val) {
    RawNode* newNode = new RawNode(val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void RawLinkedList::display_forward() {
    RawNode* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// --- PHASE 2: UNIQUE ---
void UniqueLinkedList::push_back(int val) {
    auto newNode = std::make_unique<UniqueNode>(val);
    if (!head) {
        tail = newNode.get();
        head = std::move(newNode);
    } else {
        newNode->prev = tail;
        UniqueNode* nextPtr = newNode.get();
        tail->next = std::move(newNode);
        tail = nextPtr;
    }
}

// --- PHASE 3 & 4: SHARED/WEAK ---
void SharedLinkedList::push_back(int val) {
    auto newNode = std::make_shared<SharedNode>(val);
    if (!head) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void SharedLinkedList::push_front(int val) {
    auto newNode = std::make_shared<SharedNode>(val);
    if (!head) {
        head = tail = newNode;
    } else {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void SharedLinkedList::display_forward() {
    std::shared_ptr<SharedNode> temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void SharedLinkedList::display_backward() {
    std::shared_ptr<SharedNode> temp = tail;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->prev.lock(); // Convert weak_ptr to shared_ptr to use it
    }
    std::cout << std::endl;
}
