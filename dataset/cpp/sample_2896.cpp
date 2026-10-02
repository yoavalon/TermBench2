#include <iostream>
#include <string>

std::pair<std::string, int> state_handler(const std::string& state, int data) {
    if (state == "init") {
        return {"connecting", data + 1};
    } else if (state == "connecting") {
        if (data % 2 == 0) {
            return {"connected", data + 1};
        } else {
            return {"failed", data + 1};
        }
    } else if (state == "connected") {
        return {"data_exchange", data + 1};
    } else if (state == "data_exchange") {
        return {"disconnecting", data + 1};
    } else if (state == "disconnecting") {
        return {"init", data + 1};
    } else if (state == "failed") {
        return {"retry", data + 1};
    } else if (state == "retry") {
        if (data % 3 == 0) {
            return {"connecting", data + 1};
        } else {
            return {"failed", data + 1};
        }
    }
    return {state, data}; // Default return to handle any unexpected states
}

int main() {
    std::string state = "init";
    int data = 0;
    while (true) {
        auto result = state_handler(state, data);
        state = result.first;
        data = result.second;
    }
    return 0;
}