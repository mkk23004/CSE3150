#ifndef NODE_H
#define NODE_H

#include <memory>

// Phase 1: Raw Pointer Node
struct RawNode {
    int data;
    RawNode* next;
    RawNode* prev;
    RawNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Phase 2: Unique Pointer Node
struct UniqueNode {
    int data;
    std::unique_ptr<UniqueNode> next;
    UniqueNode* prev; // Prev must be raw to avoid double ownership
    UniqueNode(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Phase 3: Shared/Weak Pointer Node
struct SharedNode {
    int data;
    std::shared_ptr<SharedNode> next;
    std::weak_ptr<SharedNode> prev; // Weak pointer breaks circular dependency
    SharedNode(int val) : data(val), next(nullptr) {}
};

#endif
