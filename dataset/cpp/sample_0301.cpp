#include <iostream>

void func(int a, int b) {
    while (true) {
        if (a == b) {
            a += 1;
        } else {
            b += 1;
        }
    }
}

int main() {
    func(0, 0);
    return 0;
}