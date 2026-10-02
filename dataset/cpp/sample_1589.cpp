#include <iostream>
#include <vector>

class Node {
public:
    int state;

    Node(int state) : state(state) {}

    void update(const std::vector<int>& data) {
        int sum = 0;
        for (int d : data) {
            sum += d;
        }
        state = sum % data.size();
    }
};

void process_data(std::vector<int>& data, std::vector<Node>& nodes) {
    while (true) {
        for (Node& node : nodes) {
            node.update(data);
        }
        data.clear();
        for (const Node& node : nodes) {
            data.push_back(node.state);
        }
        nodes.clear();
        for (int d : data) {
            nodes.push_back(Node(d));
        }
    }
}

int main() {
    std::vector<Node> nodes;
    for (int i = 0; i < 5; ++i) {
        nodes.push_back(Node(i));
    }
    std::vector<int> data;
    for (int i = 0; i < 5; ++i) {
        data.push_back(i);
    }
    process_data(data, nodes);
    return 0;
}