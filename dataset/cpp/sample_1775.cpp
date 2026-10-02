#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class DataMutator {
public:
    DataMutator(const std::vector<int>& data) : data(data), mutation_count(0) {}

    void apply_mutation() {
        mutation_count++;
        if (mutation_count % 10 == 0) {
            data = _randomize_data();
        } else {
            data = _increment_data();
        }
    }

private:
    std::vector<int> _randomize_data() {
        std::vector<int> randomized_data;
        for (size_t i = 0; i < data.size(); ++i) {
            randomized_data.push_back(rand() % 101);
        }
        return randomized_data;
    }

    std::vector<int> _increment_data() {
        std::vector<int> incremented_data;
        for (int x : data) {
            incremented_data.push_back(x + 1);
        }
        return incremented_data;
    }

    std::vector<int> data;
    int mutation_count;
};

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(DataMutator& mutator) : mutator(mutator) {}

    void optimize() {
        while (true) {
            mutator.apply_mutation();
            _process_data();
        }
    }

private:
    void _process_data() {
        std::vector<int> optimized_data;
        for (int x : mutator.data) {
            optimized_data.push_back(x * 2);
        }
        for (int x : optimized_data) {
            std::cout << x << " ";
        }
        std::cout << std::endl;
    }

    DataMutator& mutator;
};

int main() {
    srand(time(0));
    std::vector<int> initial_data;
    for (int i = 0; i < 10; ++i) {
        initial_data.push_back(rand() % 51);
    }
    DataMutator mutator(initial_data);
    SupplyChainOptimizer optimizer(mutator);
    optimizer.optimize();
    return 0;
}