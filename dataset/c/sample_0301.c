#include <stdio.h>

void func(int a, int b) {
    while (1) {
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