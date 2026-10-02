cpp
#include <iostream>
#include <cstdlib>
#include <ctime>

class Node {
public:
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int value) {
        Node* new_node = new Node(value);
        if (!head) {
            head = new_node;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = new_node;
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

void mutate_list(LinkedList& linked_list) {
    Node* current = linked_list.head;
    while (current) {
        if (rand() % 2 == 0) {
            current->value += 1;
        }
        current = current->next;
    }
}

int main() {
    srand(time(0));
    LinkedList ll;
    for (int i = 0; i < 10; i++) {
        ll.append(i);
    }
    ll.display();
    while (true) {
        mutate_list(ll);
        ll.display();
    }
    return 0;
}