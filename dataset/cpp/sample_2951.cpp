#include <iostream>
#include <vector>
#include <string>
#include <iterator>

class NetworkState {
public:
    NetworkState() : state("disconnected") {}

    void transition(const std::string& event) {
        if (state == "disconnected") {
            if (event == "connect") {
                state = "connected";
                sequence.push_back(1);
            }
        } else if (state == "connected") {
            if (event == "disconnect") {
                state = "disconnected";
                sequence.push_back(0);
            } else if (event == "data_received") {
                sequence.push_back(2);
            } else if (event == "data_sent") {
                sequence.push_back(3);
            }
        }
    }

    std::vector<int> get_sequence() const {
        return sequence;
    }

private:
    std::string state;
    std::vector<int> sequence;
};

class EventGenerator {
public:
    std::string next_event() {
        static int counter = 0;
        const std::string events[] = {"connect", "data_received", "data_sent", "disconnect"};
        return events[counter++ % 4];
    }
};

void sequence_processor(NetworkState& state_machine, EventGenerator& event_stream) {
    while (true) {
        state_machine.transition(event_stream.next_event());
    }
}

int main() {
    NetworkState state_machine;
    EventGenerator event_stream;
    sequence_processor(state_machine, event_stream);
    return 0;
}