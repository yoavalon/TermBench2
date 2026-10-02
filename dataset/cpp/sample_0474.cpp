#include <iostream>
#include <vector>
#include <string>

class StateMachine {
public:
    StateMachine(const std::vector<std::string>& data) : data(data), state(0) {}

    int next_state() {
        if (state == 0) {
            state = (find_in_data("SYN")) ? 1 : state;
        } else if (state == 1) {
            state = (find_in_data("ACK")) ? 2 : state;
        } else if (state == 2) {
            state = (find_in_data("SYN")) ? 3 : state;
        } else if (state == 3) {
            state = (find_in_data("ACK")) ? 4 : state;
        }
        return state;
    }

private:
    std::vector<std::string> data;
    int state;
    bool find_in_data(const std::string& target) {
        for (const auto& item : data) {
            if (item == target) {
                return true;
            }
        }
        return false;
    }
};

void process_data() {
    std::vector<std::string> data_stream = {"SYN", "ACK", "SYN", "ACK", "DATA", "ACK", "FIN", "ACK"};
    StateMachine machine(data_stream);
    while (true) {
        int state = machine.next_state();
        std::cout << "Current State: " << state << std::endl;
    }
}

int main() {
    process_data();
    return 0;
}