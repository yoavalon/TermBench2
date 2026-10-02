#include <iostream>
#include <vector>
#include <stack>

int state_machine(int state, std::stack<int>& connections) {
    if (connections.empty()) {
        return state;
    }
    int next_state = state ^ connections.top();
    connections.pop();
    return state_machine(next_state, connections);
}

int main() {
    int initial_state = 5;
    std::stack<int> connections;
    connections.push(4);
    connections.push(2);
    connections.push(1);
    int final_state = state_machine(initial_state, connections);
    std::cout << final_state << std::endl;
    return 0;
}