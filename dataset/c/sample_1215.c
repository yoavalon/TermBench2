#include <stdio.h>

int func(int a) {
    if (a == 0) {
        return 1;
    }
    return func(a - 1);
}

int main() {
    func(5);
    return 0;
}