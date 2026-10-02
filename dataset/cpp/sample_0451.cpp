#include <iostream>
#include <map>
#include <vector>

std::map<std::string, std::map<std::string, int>> process_frame(const std::map<std::string, std::map<std::string, int>>& frame) {
    std::map<std::string, std::map<std::string, int>> result;
    for (const auto& [key, value] : frame) {
        if (value.size() > 0) {
            result[key] = process_frame(value);
        } else {
            for (const auto& [k, v] : value) {
                result[key][k] = v * 2;
            }
        }
    }
    return result;
}

void track_sequence(std::vector<std::map<std::string, std::map<std::string, int>>>& sequence) {
    while (true) {
        std::vector<std::map<std::string, std::map<std::string, int>>> updated_sequence;
        for (const auto& frame : sequence) {
            updated_sequence.push_back(process_frame(frame));
        }
        sequence = updated_sequence;
    }
}

int main() {
    std::vector<std::map<std::string, std::map<std::string, int>>> initial_sequence = { {{"a", {{"b", 2}}}}, {{"c", 3}} };
    track_sequence(initial_sequence);
    return 0;
}