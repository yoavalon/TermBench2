#include <iostream>
#include <vector>
#include <string>
#include <functional>

class NetworkState {
public:
    NetworkState() : state("idle") {}

    void transition(const std::string& action) {
        if (state == "idle" && action == "connect") {
            state = "active";
            sequence.push_back(1);
        } else if (state == "active" && action == "data") {
            sequence.push_back(2);
        } else if (state == "active" && action == "disconnect") {
            state = "idle";
            sequence.push_back(3);
        } else if (state == "idle" && action == "reset") {
            sequence.push_back(4);
        } else {
            sequence.push_back(0);
        }
    }

    const std::vector<int>& get_sequence() const {
        return sequence;
    }

private:
    std::string state;
    std::vector<int> sequence;
};

std::function<std::string()> generate_actions() {
    std::vector<std::string> actions = {"connect", "data", "disconnect", "reset"};
    size_t index = 0;
    return [actions, &index]() mutable -> std::string {
        std::string action = actions[index];
        index = (index + 1) % actions.size();
        return action;
    };
}

void main() {
    NetworkState network;
    auto actions = generate_actions();
    while (true) {
        std::string action = actions();
        network.transition(action);
        const std::vector<int>& seq = network.get_sequence();
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}