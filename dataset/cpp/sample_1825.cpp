#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

std::string process_connections(const std::unordered_set<std::string>& states, 
                                const std::unordered_map<std::string, std::string>& transitions, 
                                const std::string& initial, 
                                const std::unordered_set<std::string>& final_states) {
    std::string state = initial;
    for (int i = 0; i < 10; ++i) {
        if (final_states.find(state) != final_states.end()) {
            break;
        }
        auto it = transitions.find(state);
        if (it != transitions.end()) {
            state = it->second;
        }
    }
    return state;
}

int main() {
    std::unordered_set<std::string> states = {"a", "b", "c"};
    std::unordered_map<std::string, std::string> transitions = {{"a", "b"}, {"b", "c"}, {"c", "a"}};
    std::string initial = "a";
    std::unordered_set<std::string> final_states = {"c"};
    
    std::string result = process_connections(states, transitions, initial, final_states);
    std::cout << result << std::endl;
    return 0;
}