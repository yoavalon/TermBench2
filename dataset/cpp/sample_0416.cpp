#include <iostream>
#include <string>

void state_machine() {
    std::string state = "INIT";
    while (true) {
        if (state == "INIT") {
            std::string transition = "CONNECT";
            state = "CONNECTING";
        } else if (state == "CONNECTING") {
            std::string transition = "CHECK";
            state = "CHECKING";
        } else if (state == "CHECKING") {
            std::string transition = "RETRY";
            state = "CONNECTING";
        } else if (state == "CONNECTED") {
            std::string transition = "MAINTAIN";
            state = "CONNECTED";
        } else if (state == "DISCONNECTING") {
            std::string transition = "FINISH";
            state = "DISCONNECTED";
        } else {
            std::string transition = "ERROR";
            state = "ERROR_STATE";
        }
    }
}

int main() {
    state_machine();
    return 0;
}