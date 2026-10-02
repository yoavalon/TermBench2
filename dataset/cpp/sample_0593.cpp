#include <iostream>

class Node {
public:
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    void display() {
        Node* current = head;
        while (current) {
            std::cout << current->value << " -> ";
            current = current->next;
        }
        std::cout << "None" << std::endl;
    }
};

class ConsensusMechanism {
public:
    LinkedList* linked_list;

    ConsensusMechanism(LinkedList* linked_list) : linked_list(linked_list) {}

    void update_values() {
        Node* current = linked_list->head;
        while (current) {
            current->value += 1;
            current = current->next;
        }
    }

    void run() {
        while (true) {
            update_values();
            linked_list->display();
        }
    }
};

int main() {
    LinkedList ll;
    for (int i = 0; i < 5; i++) {
        ll.append(i);
    }
    ConsensusMechanism cm(&ll);
    cm.run();
    return 0;
}