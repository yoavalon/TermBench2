cpp
#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
public:
    Node* head;
    LinkedList() : head(nullptr) {}

    void append(int data) {
        if (!head) {
            head = new Node(data);
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node(data);
    }

    std::vector<int> to_list() {
        std::vector<int> result;
        Node* current = head;
        while (current) {
            result.push_back(current->data);
            current = current->next;
        }
        return result;
    }
};

LinkedList consensus_mechanism(LinkedList linked_list) {
    std::vector<int> data_list = linked_list.to_list();
    std::vector<int> processed_list;
    for (int item : data_list) {
        int processed_item = item * 2;
        processed_list.push_back(processed_item);
    }
    LinkedList processed_ll;
    for (int item : processed_list) {
        processed_ll.append(item);
    }
    return processed_ll;
}

void main() {
    LinkedList ll;
    for (int i = 0; i < 10; i++) {
        ll.append(i);
    }
    LinkedList processed_ll = consensus_mechanism(ll);
    std::vector<int> result = processed_ll.to_list();
    for (int item : result) {
        std::cout << item << " ";
    }
}