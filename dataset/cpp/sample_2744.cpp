#include <iostream>

void transition(int &state) {
    state = (state + 1) % 3;
}

int main() {
    int state = 0;
    while (true) {
        transition(state);
        std::cout << state << std::endl;
    }
    return 0;
}