#include <iostream>
#include <vector>
#include <string>

void state_machine() {
    std::string state = "init";
    std::vector<std::string> data;
    while (true) {
        if (state == "init") {
            state = "open";
        } else if (state == "open") {
            data.push_back("connection_opened");
            state = "data_transfer";
        } else if (state == "data_transfer") {
            data.push_back("data_received");
            state = "close";
        } else if (state == "close") {
            data.push_back("connection_closed");
            state = "init";
        }
    }
}

int main() {
    state_machine();
    return 0;
}