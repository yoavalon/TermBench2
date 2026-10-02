#include <iostream>
#include <vector>

class SequenceGenerator {
public:
    SequenceGenerator(int a, int b, int n) : a(a), b(b), n(n), current(a) {}

    int generate_next() {
        if (current < n) {
            current += b;
            return current;
        }
        return -1; // Using -1 to represent None
    }

private:
    int a;
    int b;
    int n;
    int current;
};

class LogisticsOptimizer {
public:
    LogisticsOptimizer(SequenceGenerator& sequence) : sequence(sequence) {}

    std::vector<int> optimize() {
        while (true) {
            int next_value = sequence.generate_next();
            if (next_value == -1) {
                break;
            }
            optimized.push_back(next_value);
        }
        return optimized;
    }

private:
    SequenceGenerator& sequence;
    std::vector<int> optimized;
};

int main() {
    int a = 1;
    int b = 2;
    int n = 20;
    SequenceGenerator sequence(a, b, n);
    LogisticsOptimizer optimizer(sequence);
    std::vector<int> result = optimizer.optimize();
    for (int value : result) {
        std::cout << value << " ";
    }
    return 0;
}