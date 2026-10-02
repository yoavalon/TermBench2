#include <iostream>
#include <unordered_map>
#include <vector>

bool check_connection_state(int conn) {
    std::vector<int> states = {0, 1, 2, 3, 4};
    std::unordered_map<int, int> transitions = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    int current = 0;
    for (int i = 0; i < 10; ++i) {
        current = transitions[current];
        if (current == conn) {
            return true;
        }
    }
    return false;
}

int main() {
    bool result = check_connection_state(3);
    std::cout << result << std::endl;
    return 0;
}