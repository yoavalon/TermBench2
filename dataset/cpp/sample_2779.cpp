#include <iostream>

void sequence_tracker() {
    auto generate_sequence = [](int n) {
        int a = 0, b = 1;
        for (int i = 0; i < n; ++i) {
            co_yield a;
            int temp = a;
            a = b;
            b = temp + b;
        }
    };

    while (true) {
        for (int num : generate_sequence(10)) {
            std::cout << num << std::endl;
        }
    }
}

int main() {
    sequence_tracker();
    return 0;
}