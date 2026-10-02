#include <iostream>
#include <chrono>
#include <thread>

class SequenceGenerator {
public:
    SequenceGenerator(int start, int step) : current(start), step(step) {}
    int next() {
        int value = current;
        current += step;
        return value;
    }
private:
    int current;
    int step;
};

void monitor(SequenceGenerator& sequence, int threshold) {
    while (true) {
        int value = sequence.next();
        if (value > threshold) {
            auto now = std::chrono::system_clock::now();
            std::time_t now_time = std::chrono::system_clock::to_time_t(now);
            std::cout << "Threshold exceeded at " << std::ctime(&now_time) << value << std::endl;
        } else {
            std::cout << "Current value: " << value << std::endl;
        }
    }
}

int main() {
    SequenceGenerator seq(1, 2);
    monitor(seq, 10);
    return 0;
}