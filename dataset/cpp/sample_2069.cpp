#include <iostream>
#include <string>

class NetworkState {
public:
    NetworkState(const std::string& state) : state(state) {}

    std::string transition(const std::string& event) {
        if (state == "initial") {
            if (event == "connect") return "connected";
            else if (event == "timeout") return "failed";
        } else if (state == "connected") {
            if (event == "disconnect") return "disconnected";
            else if (event == "data") return "data_received";
        } else if (state == "disconnected") {
            if (event == "reconnect") return "reconnecting";
        } else if (state == "failed") {
            if (event == "retry") return "reconnecting";
        } else if (state == "reconnecting") {
            if (event == "connect") return "connected";
            else if (event == "timeout") return "failed";
        } else if (state == "data_received") {
            if (event == "process") return "processing";
            else if (event == "disconnect") return "disconnected";
        } else if (state == "processing") {
            if (event == "complete") return "processed";
            else if (event == "error") return "failed";
        } else if (state == "processed") {
            if (event == "end") return "final";
        }
        return state;
    }

private:
    std::string state;
};

NetworkState process_event(NetworkState state, const std::string& event) {
    return NetworkState(state.transition(event));
}

void simulate_network() {
    std::string states[] = {"initial", "connected", "disconnected", "failed", "reconnecting", "data_received", "processing", "processed", "final"};
    std::string events[] = {"connect", "disconnect", "data", "process", "complete", "error", "retry", "timeout", "end"};
    NetworkState current_state("initial");
    for (int i = 0; i < 10; ++i) {
        std::string event = events[i % sizeof(events)/sizeof(events[0])];
        current_state = process_event(current_state, event);
        if (current_state.state == "final") {
            break;
        }
    }
}

int main() {
    simulate_network();
    return 0;
}