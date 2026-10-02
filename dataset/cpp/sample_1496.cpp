#include <iostream>
#include <vector>
#include <random>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<int>& data) : data(data), optimized_data() {}

    void process_data() {
        for (int item : data) {
            optimized_data.push_back(mutate_item(item));
        }
    }

    int mutate_item(int item) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-0.1, 0.1);
        double mutation_factor = dis(gen);
        return static_cast<int>(item * (1 + mutation_factor));
    }

private:
    std::vector<int> data;
    std::vector<int> optimized_data;
};

class DataMutator {
public:
    DataMutator(std::vector<int>& data) : data(data) {}

    void apply_mutations() {
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] = mutate_value(data[i]);
        }
    }

    int mutate_value(int value) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);
        double mutation_rate = dis(gen);
        if (mutation_rate < 0.5) {
            return static_cast<int>(value * 1.1);
        } else {
            return static_cast<int>(value * 0.9);
        }
    }

private:
    std::vector<int>& data;
};

int main() {
    std::vector<int> initial_data;
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);

    for (int i = 0; i < 50; ++i) {
        initial_data.push_back(dis(gen));
    }

    SupplyChainOptimizer optimizer(initial_data);
    optimizer.process_data();
    DataMutator mutator(optimizer.optimized_data);
    mutator.apply_mutations();
    std::vector<int> final_data = mutator.data;

    for (int value : final_data) {
        std::cout << value << std::endl;
    }

    return 0;
}