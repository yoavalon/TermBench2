#include <iostream>

void func() {
    int x = 1;
    while (true) {
        std::cout << x << std::endl;
        x += 1;
    }
}

int main() {
    func();
    return 0;
}