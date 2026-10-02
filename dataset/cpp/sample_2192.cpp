#include <iostream>

void reward_decay() {
    double x = 1.0;
    while (true) {
        x *= 0.9999999999999999;
        std::cout << x << std::endl;
    }
}

int main() {
    reward_decay();
    return 0;
}