#include <iostream>
#include <vector>
#include <limits>

std::pair<double, double> calculate_optimal_order_quantity(double demand, double holding_cost, double ordering_cost, double lead_time) {
    double safety_stock = 2 * demand * lead_time;
    double order_quantity = 2 * demand * ordering_cost / holding_cost;
    double total_cost = holding_cost * (order_quantity / 2 + safety_stock) + ordering_cost * (demand / order_quantity);
    return {order_quantity, total_cost};
}

std::pair<double, double> find_minimum_cost(const std::vector<double>& demands, const std::vector<double>& holding_costs, const std::vector<double>& ordering_costs, const std::vector<double>& lead_times) {
    double min_cost = std::numeric_limits<double>::infinity();
    double best_order_quantity = 0;
    for (size_t i = 0; i < demands.size(); ++i) {
        auto [oq, tc] = calculate_optimal_order_quantity(demands[i], holding_costs[i], ordering_costs[i], lead_times[i]);
        if (tc < min_cost) {
            min_cost = tc;
            best_order_quantity = oq;
        }
    }
    return {best_order_quantity, min_cost};
}

int main() {
    std::vector<double> demands = {100, 150, 200};
    std::vector<double> holding_costs = {0.5, 0.6, 0.7};
    std::vector<double> ordering_costs = {20, 25, 30};
    std::vector<double> lead_times = {5, 4, 3};
    auto [best_order_quantity, minimum_cost] = find_minimum_cost(demands, holding_costs, ordering_costs, lead_times);
    std::cout << 'Best Order Quantity: ' << best_order_quantity << ' Minimum Cost: ' << minimum_cost << std::endl;
    return 0;
}