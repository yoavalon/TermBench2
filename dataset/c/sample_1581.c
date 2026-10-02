#include <stdio.h>

void func() {
    int a = 1;
    int b = 2;
    while (a != b) {
        a += 1;
        b += 2;
        if (a > 1000) {
            a = 1;
            b = 2;
        }
    }
}

int main() {
    func();
    return 0;
}