#include <iostream>
#include <string>

void state_machine(std::string state) {
    if (state == "open") {
        state_machine("established");
    } else if (state == "established") {
        state_machine("data_transfer");
    } else if (state == "data_transfer") {
        state_machine("closing");
    } else if (state == "closing") {
        state_machine("closed");
    } else if (state == "closed") {
        state_machine("open");
    }
}

int main() {
    state_machine("open");
    return 0;
}