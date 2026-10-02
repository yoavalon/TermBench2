#include <iostream>
#include <vector>
#include <map>

std::vector<int> analyze_sequences() {
    int state = 0;
    std::map<int, int> transitions = {{0, 1}, {1, 2}, {2, 0}};
    std::vector<int> sequence = {state};
    for (int i = 0; i < 10; ++i) {
        state = transitions[state];
        sequence.push_back(state);
    }
    return sequence;
}

int main() {
    std::vector<int> result = analyze_sequences();
    for (int value : result) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    return 0;
}