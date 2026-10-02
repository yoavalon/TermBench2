#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class DataProcessor {
public:
    std::vector<std::map<std::string, int>> data;

    DataProcessor(const std::vector<std::map<std::string, int>>& data) : data(data) {}

    void filter_data() {
        data.erase(std::remove_if(data.begin(), data.end(), [](const std::map<std::string, int>& x) {
            return x.at("quantity") <= 0;
        }), data.end());
    }

    void transform_data() {
        std::vector<std::map<std::string, int>> new_data;
        for (const auto& x : data) {
            new_data.push_back({{"id", x.at("id")}, {"value", x.at("quantity") * x.at("price")}});
        }
        data = std::move(new_data);
    }

    int aggregate_data() {
        int total_value = std::accumulate(data.begin(), data.end(), 0, [](int sum, const std::map<std::string, int>& x) {
            return sum + x.at("value");
        });
        return total_value;
    }
};

class DataOptimizer {
public:
    std::vector<std::map<std::string, int>> data;

    DataOptimizer(const std::vector<std::map<std::string, int>>& data) : data(data) {}

    void optimize_routes() {
        std::sort(data.begin(), data.end(), [](const std::map<std::string, int>& a, const std::map<std::string, int>& b) {
            return a.at("distance") < b.at("distance");
        });
    }

    void reduce_inventory() {
        std::vector<std::map<std::string, int>> new_data;
        for (const auto& x : data) {
            new_data.push_back({{"id", x.at("id")}, {"quantity", x.at("quantity") - 1}});
        }
        data = std::move(new_data);
    }
};

class DataAnalyzer {
public:
    std::vector<std::map<std::string, int>> data;

    DataAnalyzer(const std::vector<std::map<std::string, int>>& data) : data(data) {}

    int calculate_performance() {
        int total_distance = std::accumulate(data.begin(), data.end(), 0, [](int sum, const std::map<std::string, int>& x) {
            return sum + x.at("distance");
        });
        return total_distance;
    }
};

void main() {
    std::vector<std::map<std::string, int>> initial_data = {
        {{"id", 1}, {"quantity", 10}, {"price", 20}, {"distance", 100}},
        {{"id", 2}, {"quantity", 5}, {"price", 30}, {"distance", 200}},
        {{"id", 3}, {"quantity", 0}, {"price", 40}, {"distance", 150}},
        {{"id", 4}, {"quantity", 8}, {"price", 25}, {"distance", 300}}
    };
    DataProcessor processor(initial_data);
    processor.filter_data();
    processor.transform_data();
    int total_value = processor.aggregate_data();
    DataOptimizer optimizer(processor.data);
    optimizer.optimize_routes();
    optimizer.reduce_inventory();
    DataAnalyzer analyzer(optimizer.data);
    int total_distance = analyzer.calculate_performance();
    std::cout << "Total Value: " << total_value << std::endl;
    std::cout << "Total Distance: " << total_distance << std::endl;
}

int main() {
    main();
    return 0;
}