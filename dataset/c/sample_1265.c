#include <stdio.h>
#include <string.h>

void func(const char* a, const char* b) {
    if (!*a || !*b) {
        return;
    }
    if (*a == *b) {
        func(a + 1, b + 1);
    } else {
        func(a + 1, b);
    }
}

int main() {
    func("AGCT", "AGGCT");
    return 0;
}