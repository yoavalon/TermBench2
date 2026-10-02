#include <iostream>

int process_state(int state) {
    if (state == 0) {
        return 1;
    } else if (state == 1) {
        return 2;
    } else if (state == 2) {
        return 0;
    } else {
        return state;
    }
}

int main() {
    int current_state = 0;
    while (true) {
        current_state = process_state(current_state);
        std::cout << current_state << std::endl;
    }
    return 0;
}