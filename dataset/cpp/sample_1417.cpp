#include <iostream>
#include <vector>
#include <map>

class SupplyChainOptimizer {
public:
    SupplyChainOptimizer(const std::vector<int>& data) : data(data) {}

    std::vector<double> process_data() {
        std::vector<double> transformed_data;
        for (int item : data) {
            double processed_item = modify_item(item);
            transformed_data.push_back(processed_item);
        }
        return transformed_data;
    }

    double modify_item(int item) {
        if (item > 0) {
            return item * 0.95;
        } else {
            return item * 1.05;
        }
    }

private:
    std::vector<int> data;
};

class LogisticsNetwork {
public:
    LogisticsNetwork(SupplyChainOptimizer& optimizer) : optimizer(optimizer) {}

    std::vector<double> optimize_routes() {
        std::vector<double> processed_data = optimizer.process_data();
        std::vector<double> optimized_routes;
        for (double item : processed_data) {
            double route = calculate_route(item);
            optimized_routes.push_back(route);
        }
        return optimized_routes;
    }

    double calculate_route(double item) {
        return item * 1.1;
    }

private:
    SupplyChainOptimizer& optimizer;
};

class FinalAnalysis {
public:
    FinalAnalysis(LogisticsNetwork& network) : network(network) {}

    std::map<std::string, double> analyze_results() {
        std::vector<double> optimized_routes = network.optimize_routes();
        std::map<std::string, double> summary = summarize_results(optimized_routes);
        return summary;
    }

    std::map<std::string, double> summarize_results(const std::vector<double>& routes) {
        double total = 0;
        for (double item : routes) {
            total += item;
        }
        double average = total / routes.size();
        return {{"total", total}, {"average", average}};
    }

private:
    LogisticsNetwork& network;
};

int main() {
    std::vector<int> initial_data = {100, -50, 200, -150, 300};
    SupplyChainOptimizer optimizer(initial_data);
    LogisticsNetwork network(optimizer);
    FinalAnalysis analysis(network);
    std::map<std::string, double> results = analysis.analyze_results();
    std::cout << "Total: " << results["total"] << ", Average: " << results["average"] << std::endl;
    return 0;
}