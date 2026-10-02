#include <iostream>

int func(int x) {
    if (x % 2 == 0) {
        return func(x + 1);
    } else {
        return func(x + 2);
    }
}

int main() {
    func(1);
    return 0;
}