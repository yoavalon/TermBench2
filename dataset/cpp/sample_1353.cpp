#include <iostream>
#include <vector>
#include <string>

std::string process_data(const std::vector<std::string>& data) {
    std::string state = "init";
    for (const auto& item : data) {
        if (state == "init") {
            if (item == "connect") {
                state = "connected";
            } else if (item == "disconnect") {
                state = "disconnected";
            }
        } else if (state == "connected") {
            if (item == "data") {
                state = "processing";
            } else if (item == "disconnect") {
                state = "disconnected";
            }
        } else if (state == "processing") {
            if (item == "complete") {
                state = "connected";
            } else if (item == "disconnect") {
                state = "disconnected";
            }
        } else if (state == "disconnected") {
            if (item == "connect") {
                state = "connected";
            }
        }
    }
    return state;
}

void main() {
    std::vector<std::string> data_sequence = {"connect", "data", "complete", "disconnect"};
    std::string result = process_data(data_sequence);
    std::cout << result << std::endl;
}