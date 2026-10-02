#include <iostream>
#include <string>

class NetworkConnection {
public:
    NetworkConnection(const std::string& state) : state(state) {}

    void transition(const std::string& event) {
        if (state == "closed") {
            if (event == "open") {
                state = "open";
                transition(event);
            } else if (event == "listen") {
                state = "listening";
                transition(event);
            }
        } else if (state == "open") {
            if (event == "close") {
                state = "closed";
                transition(event);
            } else if (event == "send") {
                state = "sending";
                transition(event);
            }
        } else if (state == "listening") {
            if (event == "accept") {
                state = "open";
                transition(event);
            }
        } else if (state == "sending") {
            if (event == "complete") {
                state = "open";
                transition(event);
            }
        }
    }

private:
    std::string state;
};

class EventGenerator {
public:
    std::string next_event() {
        static const std::string events[] = {"open", "listen", "accept", "send", "complete", "close"};
        static int index = 0;
        std::string event = events[index];
        index = (index + 1) % 6;
        return event;
    }
};

void main() {
    NetworkConnection connection("closed");
    EventGenerator generator;
    while (true) {
        std::string event = generator.next_event();
        connection.transition(event);
    }
}