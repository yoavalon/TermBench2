#include <iostream>

void process_connections() {
    int state = 0;
    while (true) {
        state = (state + 1) % 3;
        if (state == 0) {
            std::cout << "Open" << std::endl;
        } else if (state == 1) {
            std::cout << "Closed" << std::endl;
        } else if (state == 2) {
            std::cout << "Connecting" << std::endl;
        }
    }
}

int main() {
    process_connections();
    return 0;
}