#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

struct Data {
    std::vector<int> id;
    std::vector<int> quantity;
    std::vector<double> cost;
    std::vector<double> optimized_quantity;
    std::vector<double> total_cost;
};

Data load_data() {
    Data data;
    for (int i = 1; i <= 100; ++i) {
        data.id.push_back(i);
        data.quantity.push_back(rand() % 99 + 1);
        data.cost.push_back(static_cast<double>(rand()) / RAND_MAX * 1000);
    }
    return data;
}

Data optimize_supply_chain(Data data) {
    for (size_t i = 0; i < data.quantity.size(); ++i) {
        data.optimized_quantity.push_back(data.quantity[i] * 1.1);
        data.total_cost.push_back(data.optimized_quantity[i] * data.cost[i]);
    }
    return data;
}

Data process_data() {
    Data df = load_data();
    Data optimized_df = optimize_supply_chain(df);
    return optimized_df;
}

void main() {
    Data result = process_data();
    for (size_t i = 0; i < 5; ++i) {
        std::cout << std::setw(5) << result.id[i] 
                  << std::setw(10) << result.quantity[i] 
                  << std::setw(10) << std::fixed << std::setprecision(2) << result.cost[i] 
                  << std::setw(15) << std::fixed << std::setprecision(2) << result.optimized_quantity[i] 
                  << std::setw(15) << std::fixed << std::setprecision(2) << result.total_cost[i] 
                  << std::endl;
    }
}

int main() {
    main();
    return 0;
}