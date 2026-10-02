#include <iostream>
#include <functional>

std::function<int()> generate_sequence(int a, int d) {
    return [a, d]() mutable -> int {
        int current = a;
        a += d;
        return current;
    };
}

std::function<int()> optimize_inventory(std::function<int()>& seq, int demand) {
    int stock = 0;
    return [&seq, &stock, demand]() mutable -> int {
        int supply = seq();
        stock += supply;
        if (stock < demand) {
            return 0;
        } else {
            stock -= demand;
            return stock;
        }
    };
}

void main() {
    auto seq = generate_sequence(10, 5);
    int demand = 15;
    for (int i = 0; ; ++i) {
        int stock = optimize_inventory(seq, demand)();
        std::cout << "Period " << i + 1 << ": Stock " << stock << std::endl;
    }
}