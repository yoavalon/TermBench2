#include <iostream>
#include <string>
#include <vector>

std::string process_data(std::string state, std::string packet) {
    if (state == "open") {
        if (packet == "SYN") {
            return "syn_received";
        } else if (packet == "FIN") {
            return "close_wait";
        }
    } else if (state == "syn_received") {
        if (packet == "ACK") {
            return "established";
        }
    } else if (state == "established") {
        if (packet == "FIN") {
            return "close_wait";
        }
    } else if (state == "close_wait") {
        if (packet == "ACK") {
            return "last_ack";
        }
    } else if (state == "last_ack") {
        if (packet == "ACK") {
            return "closed";
        }
    }
    return state;
}

void simulate_network() {
    std::string state = "open";
    std::vector<std::string> packets = {"SYN", "ACK", "FIN", "ACK"};
    for (const auto& packet : packets) {
        state = process_data(state, packet);
    }
    while (true) {
        state = process_data(state, "ACK");
    }
}

int main() {
    simulate_network();
    return 0;
}