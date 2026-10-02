c
#include <stdio.h>

void non_terminating_recursion(int x, int y) {
    if (x > y) {
        non_terminating_recursion(y, x);
    } else {
        non_terminating_recursion(x + 1, y);
    }
}

int main() {
    non_terminating_recursion(0, 1);
    return 0;
}