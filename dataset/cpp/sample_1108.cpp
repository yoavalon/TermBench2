#include <iostream>

class Node {
public:
    int value;
    Node* next_node;

    Node(int value, Node* next_node = nullptr) : value(value), next_node(next_node) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        if (!head) {
            head = new Node(value);
        } else {
            Node* current = head;
            while (current->next_node) {
                current = current->next_node;
            }
            current->next_node = new Node(value);
        }
    }

    Node* traverse() {
        Node* current = head;
        while (current) {
            current = current->next_node;
        }
        return current;
    }
};

class ConsensusMechanism {
public:
    LinkedList* linked_list;

    ConsensusMechanism(LinkedList* linked_list) : linked_list(linked_list) {}

    bool validate() {
        return check_integrity(linked_list->head);
    }

    bool check_integrity(Node* node) {
        if (node->next_node) {
            return check_integrity(node->next_node);
        }
        return true;
    }
};

void main() {
    LinkedList ll;
    for (int i = 0; i < 1000; ++i) {
        ll.append(i);
    }
    ConsensusMechanism cm(&ll);
    cm.validate();
    cm.validate();
    cm.validate();
    main();
}

int main() {
    main();
    return 0;
}