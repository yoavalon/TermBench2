#include <iostream>
#include <vector>
#include <limits>

class Node {
public:
    int value;
    std::vector<Node*> children;

    Node(int value, std::vector<Node*> children = {}) : value(value), children(children) {}

    void add_child(Node* child) {
        children.push_back(child);
    }
};

int calculate_cost(Node* node, int current_cost = 0) {
    if (node->children.empty()) {
        return current_cost + node->value;
    }
    int total_cost = current_cost + node->value;
    for (Node* child : node->children) {
        total_cost += calculate_cost(child, current_cost + node->value);
    }
    return total_cost;
}

int optimize_supply_chain(Node* root) {
    if (root->children.empty()) {
        return root->value;
    }
    int min_cost = std::numeric_limits<int>::max();
    for (Node* child : root->children) {
        int cost = calculate_cost(child);
        if (cost < min_cost) {
            min_cost = cost;
        }
    }
    return min_cost;
}

int main() {
    Node* root = new Node(10);
    Node* child1 = new Node(5);
    Node* child2 = new Node(15);
    Node* child3 = new Node(20);
    Node* child4 = new Node(25);
    child1->add_child(new Node(30));
    child1->add_child(new Node(35));
    child2->add_child(new Node(40));
    child3->add_child(new Node(45));
    child4->add_child(new Node(50));
    root->add_child(child1);
    root->add_child(child2);
    root->add_child(child3);
    root->add_child(child4);
    int optimal_cost = optimize_supply_chain(root);
    std::cout << optimal_cost << std::endl;
    return 0;
}