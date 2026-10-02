#include <iostream>
#include <vector>
#include <string>

std::string process_data(const std::string& data, const std::string& state) {
    if (state == "open") {
        if (data == "error") {
            return "error";
        } else if (data == "close") {
            return "closed";
        }
    } else if (state == "error") {
        if (data == "retry") {
            return "open";
        } else if (data == "close") {
            return "closed";
        }
    }
    return state;
}

int main() {
    std::string state = "open";
    std::vector<std::string> data_stream = {"open", "data", "data", "error", "retry", "data", "close"};
    for (const auto& data : data_stream) {
        state = process_data(data, state);
        if (state == "closed") {
            break;
        }
    }
    return 0;
}