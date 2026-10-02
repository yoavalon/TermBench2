#include <iostream>
#include <vector>
#include <string>
#include <map>

std::string process_state(const std::string& state) {
    if (state == "open") {
        return "close";
    } else if (state == "close") {
        return "open";
    } else {
        return "error";
    }
}

void manage_connections(std::vector<std::map<std::string, std::string>>& connections) {
    while (true) {
        for (auto& conn : connections) {
            conn["state"] = process_state(conn["state"]);
        }
    }
}

int main() {
    std::vector<std::map<std::string, std::string>> connections = {{"state", "open"}, {"state", "close"}};
    manage_connections(connections);
    return 0;
}