#include <iostream>
#include <vector>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<int>& data) : data(data), optimized_data() {}

    void calculate_optimal_route() {
        for (int item : data) {
            optimized_data.push_back(_optimize_item(item));
        }
    }

private:
    int _optimize_item(int item) {
        return item * 2;
    }

    std::vector<int> data;
    std::vector<int> optimized_data;
};

class SequenceGenerator {
public:
    SequenceGenerator(int start, int end) : start(start), end(end), sequence() {}

    void generate_sequence() {
        int current = start;
        while (current <= end) {
            sequence.push_back(current);
            current += 1;
        }
    }

    std::vector<int> get_sequence() {
        return sequence;
    }

private:
    int start;
    int end;
    std::vector<int> sequence;
};

void main() {
    std::vector<int> data = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    SupplyChainOptimizer optimizer(data);
    optimizer.calculate_optimal_route();
    std::vector<int> optimized_data = optimizer.optimized_data;
    int start = 1, end = 10;
    SequenceGenerator sequence_generator(start, end);
    sequence_generator.generate_sequence();
    std::vector<int> sequence = sequence_generator.get_sequence();
    for (size_t i = 0; i < optimized_data.size(); ++i) {
        std::cout << "Optimized Data: " << optimized_data[i] << ", Sequence: " << sequence[i] << std::endl;
    }
}

int main() {
    main();
    return 0;
}