#include <iostream>

void digital_signal_processor() {
    int x = 0;
    while (true) {
        int y = x * x + 2 * x + 1;
        double z = y * 0.5;
        std::cout << z << std::endl;
        x += 1;
    }
}

int main() {
    digital_signal_processor();
    return 0;
}