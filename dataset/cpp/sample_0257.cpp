#include <iostream>
#include <vector>

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
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = new_node;
        }
    }

    int get_length() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};

LinkedList process_data(const std::vector<int>& data) {
    LinkedList linked_list;
    for (int item : data) {
        linked_list.append(item);
    }
    return linked_list;
}

std::string analyze_boundaries(const LinkedList& linked_list) {
    int length = linked_list.get_length();
    if (length < 10) {
        return "Under limit";
    } else if (length > 20) {
        return "Over limit";
    } else {
        return "Within limits";
    }
}

void main() {
    std::vector<int> data(15);
    for (int i = 0; i < 15; i++) {
        data[i] = i;
    }
    LinkedList processed_data = process_data(data);
    std::string result = analyze_boundaries(processed_data);
    std::cout << result << std::endl;
}

int main() {
    main();
    return 0;
}