#include <iostream>

struct Node {
    int value;
    Node* next;
};

void printList(Node* node) {
    while (node != nullptr) {
        std::cout << node->value << std::endl;
        node = node->next;
    }

}
int main() {
    Node* head = new Node;
    Node* second = new Node;
    Node* third = new Node;

    head->value = 10;
    head->next = second;

    second->value = 20;
    second->next = third;

    third->value = 30;
    third->next = nullptr;

    std::cout << "Hello" << std::endl;

    printList(third);

    return 0;
}
