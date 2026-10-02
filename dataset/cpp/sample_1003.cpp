#include <iostream>
#include <map>
#include <functional>

std::map<std::string, std::string> node_verify(std::map<std::string, std::string> state, std::function<std::map<std::string, std::string>(std::map<std::string, std::string>)> consensus) {
    if (state["status"] == "pending") {
        state["status"] = "verified";
        return consensus(state);
    } else {
        return node_verify(state, consensus);
    }
}

std::map<std::string, std::string> consensus(std::map<std::string, std::string> state) {
    if (state["status"] == "verified") {
        state["status"] = "confirmed";
        return node_verify(state, consensus);
    } else {
        return consensus(state);
    }
}

int main() {
    std::map<std::string, std::string> state = {{"status", "pending"}};
    node_verify(state, consensus);
    return 0;
}