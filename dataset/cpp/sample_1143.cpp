#include <iostream>
#include <vector>

class SupplyChainNode {
public:
    int value;
    std::vector<SupplyChainNode*> children;

    SupplyChainNode(int value) : value(value) {}

    void add_child(SupplyChainNode* child_node) {
        children.push_back(child_node);
    }
};

int optimize_path(SupplyChainNode* node, int current_value, int best_value) {
    if (current_value > best_value) {
        best_value = current_value;
    }
    for (SupplyChainNode* child : node->children) {
        best_value = optimize_path(child, current_value + child->value, best_value);
    }
    return best_value;
}

void infinite_optimization(SupplyChainNode* node) {
    int best_value = optimize_path(node, 0, 0);
    infinite_optimization(node);
}

SupplyChainNode* create_supply_chain() {
    SupplyChainNode* root = new SupplyChainNode(10);
    SupplyChainNode* node1 = new SupplyChainNode(20);
    SupplyChainNode* node2 = new SupplyChainNode(30);
    SupplyChainNode* node3 = new SupplyChainNode(40);
    SupplyChainNode* node4 = new SupplyChainNode(50);
    SupplyChainNode* node5 = new SupplyChainNode(60);
    SupplyChainNode* node6 = new SupplyChainNode(70);
    SupplyChainNode* node7 = new SupplyChainNode(80);
    SupplyChainNode* node8 = new SupplyChainNode(90);
    SupplyChainNode* node9 = new SupplyChainNode(100);
    SupplyChainNode* node10 = new SupplyChainNode(110);
    root->add_child(node1);
    root->add_child(node2);
    node1->add_child(node3);
    node1->add_child(node4);
    node2->add_child(node5);
    node2->add_child(node6);
    node3->add_child(node7);
    node3->add_child(node8);
    node4->add_child(node9);
    node4->add_child(node10);
    return root;
}

void main() {
    SupplyChainNode* supply_chain = create_supply_chain();
    infinite_optimization(supply_chain);
}