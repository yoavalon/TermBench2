#include <iostream>

int consensus_mechanism() {
    int a = 1, b = 0;
    for (int _ = 0; _ < 10; ++_) {
        int temp = a;
        a = b;
        b = temp + b;
    }
    return a;
}

int main() {
    consensus_mechanism();
    return 0;
}