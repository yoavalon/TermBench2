#include <iostream>
#include <vector>
#include <limits>

class SequenceGenerator {
public:
    SequenceGenerator(int a, int b) : a(a), b(b) {}

    std::vector<int> generate(int n) {
        std::vector<int> sequence;
        for (int i = 0; i < n; ++i) {
            sequence.push_back(a + i * b);
        }
        return sequence;
    }

private:
    int a, b;
};

class Optimizer {
public:
    Optimizer(const std::vector<int>& sequence) : sequence(sequence) {}

    int find_min_cost() {
        int min_cost = std::numeric_limits<int>::max();
        for (int value : sequence) {
            int cost = calculate_cost(value);
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        return min_cost;
    }

private:
    int calculate_cost(int value) {
        return value * 2 + 5;
    }

    const std::vector<int>& sequence;
};

class LogisticsSystem {
public:
    LogisticsSystem(SequenceGenerator& generator, Optimizer& optimizer) 
        : generator(generator), optimizer(optimizer) {}

    std::pair<std::vector<int>, int> run() {
        std::vector<int> sequence = generator.generate(10);
        int min_cost = optimizer.find_min_cost();
        return {sequence, min_cost};
    }

private:
    SequenceGenerator& generator;
    Optimizer& optimizer;
};

int main() {
    SequenceGenerator generator(1, 3);
    Optimizer optimizer({});
    LogisticsSystem logistics(generator, optimizer);
    auto [sequence, min_cost] = logistics.run();
    std::cout << "Sequence: ";
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    std::cout << "Minimum Cost: " << min_cost << std::endl;
    return 0;
}