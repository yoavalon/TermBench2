#include <iostream>

void process_data(double x) {
    while (true) {
        x = x * 2.0;
        if (x > 10000000000.0) {
            x = x / 10000000000.0;
        }
    }
}

int main() {
    process_data(0.1);
    return 0;
}