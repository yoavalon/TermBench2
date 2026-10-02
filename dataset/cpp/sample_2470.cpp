#include <iostream>
#include <vector>

std::vector<int> cellular_automata(int n) {
    std::vector<int> a(n, 0);
    a[n / 2] = 1;
    for (int _ = 0; _ < 10; ++_) {
        std::vector<int> b(n, 0);
        for (int i = 1; i < n - 1; ++i) {
            b[i] = a[i - 1] ^ a[i] ^ a[i + 1];
        }
        a = b;
    }
    return a;
}

int main() {
    cellular_automata(100);
    return 0;
}