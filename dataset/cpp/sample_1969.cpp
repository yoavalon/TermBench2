#include <iostream>
#include <vector>
#include <string>

std::string state_transition(const std::string& state, double data) {
    if (state == "start") {
        if (data > 0.5) {
            return "active";
        } else {
            return "idle";
        }
    } else if (state == "active") {
        if (data < 0.5) {
            return "idle";
        } else {
            return "closing";
        }
    } else if (state == "idle") {
        if (data > 0.5) {
            return "active";
        } else {
            return "idle";
        }
    } else if (state == "closing") {
        return "terminated";
    }
    return state;
}

std::string network_monitor(const std::vector<double>& data_points) {
    std::string state = "start";
    for (double data : data_points) {
        state = state_transition(state, data);
        if (state == "terminated") {
            break;
        }
    }
    return state;
}

int main() {
    std::vector<double> data_sequence = {0.6, 0.7, 0.4, 0.3, 0.8};
    std::string result = network_monitor(data_sequence);
    std::cout << result << std::endl;
    return 0;
}