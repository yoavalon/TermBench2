cpp
#include <iostream>

int sequence(int x) {
    while (true) {
        x = (x * x + 1) % 1000;
        return x;
    }
}

int main() {
    int n = 1;
    while (true) {
        std::cout << sequence(n) << std::endl;
    }
    return 0;
}