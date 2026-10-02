#include <iostream>

class F {
public:
    int a, b;
    F() : a(0), b(1) {}

    int next() {
        int temp = a;
        a = b;
        b = temp + b;
        return a;
    }
};

class G {
public:
    F f;
    int next() {
        return f.next() % 2;
    }
};

void main() {
    G g;
    while (true) {
        std::cout << g.next() << std::endl;
    }
}