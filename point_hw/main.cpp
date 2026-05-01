#include "include/linked_list.h"

int main() {
    std::cout << "Testing Shared Doubly Linked List:" << std::endl;
    SharedLinkedList list;
    list.push_back(10);
    list.push_back(20);
    list.push_front(5);

    std::cout << "Forward: ";
    list.display_forward(); // Should be 5 10 20

    std::cout << "Backward: ";
    list.display_backward(); // Should be 20 10 5

    return 0;
}
