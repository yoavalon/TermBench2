#include <iostream>
#include <vector>
#include <string>
#include <utility>

std::pair<std::string, double> process_data(int data, const std::string& state) {
    if (state == "start") {
        if (data == 1) {
            return {"connected", 1.0};
        } else {
            return {"disconnected", 0.0};
        }
    } else if (state == "connected") {
        if (data == 0) {
            return {"disconnected", 0.5};
        } else {
            return {"connected", 1.5};
        }
    } else {
        return {"error", -1.0};
    }
}

void main() {
    std::string state = "start";
    std::vector<int> data_sequence = {1, 0, 1, 0, 1};
    double result = 0.0;
    for (int data : data_sequence) {
        auto [new_state, value] = process_data(data, state);
        state = new_state;
        result += value;
    }
    std::cout << result << std::endl;
}