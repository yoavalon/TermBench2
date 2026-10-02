#include <iostream>

void process_data() {
    int x = 1;
    while (true) {
        x += 1;
        if (x % 2 == 0) {
            std::cout << x << std::endl;
        } else {
            std::cout << x * x << std::endl;
        }
    }
}

int main() {
    process_data();
    return 0;
}