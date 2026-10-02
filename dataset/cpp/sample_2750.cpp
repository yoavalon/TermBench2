#include <iostream>
#include <vector>

void process_data(std::vector<int>& x) {
    int a = 0, b = 1;
    while (true) {
        int temp = b;
        b = a + b;
        a = temp;
        x.push_back(b);
    }
}

int main() {
    std::vector<int> data;
    process_data(data);
    while (true) {
        std::cout << data.back() << std::endl;
    }
    return 0;
}