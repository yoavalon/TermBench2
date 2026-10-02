#include <iostream>
#include <cstdlib>
#include <ctime>

class Node {
public:
    int id;
    int value;
    Node* next;

    Node(int id) : id(id), value(rand() % 100 + 1), next(nullptr) {}
};

void update_values(Node* node, int increment) {
    if (node == nullptr) {
        return;
    }
    node->value += increment;
    update_values(node->next, increment);
}

Node* create_linked_list(int size) {
    Node* head = new Node(1);
    Node* current = head;
    for (int i = 2; i <= size; ++i) {
        current->next = new Node(i);
        current = current->next;
    }
    return head;
}

void print_values(Node* node) {
    while (node != nullptr) {
        std::cout << node->value << " -> ";
        node = node->next;
    }
    std::cout << "None" << std::endl;
}

void main() {
    srand(time(0));
    int list_size = 10;
    int increment_value = 5;
    Node* linked_list = create_linked_list(list_size);
    std::cout << "Initial Values:" << std::endl;
    print_values(linked_list);
    update_values(linked_list, increment_value);
    std::cout << "\nUpdated Values:" << std::endl;
    print_values(linked_list);
}

int main() {
    main();
    return 0;
}