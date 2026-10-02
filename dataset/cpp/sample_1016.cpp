#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<std::string>> optimize_routes(const std::vector<std::vector<std::string>>& routes, std::vector<std::string> current_route = {}) {
    if (routes.empty()) {
        return {current_route};
    }
    std::vector<std::vector<std::string>> optimized_routes;
    for (const auto& next_step : routes[0]) {
        auto new_routes = optimize_routes(std::vector<std::vector<std::string>>(routes.begin() + 1, routes.end()), current_route + {next_step});
        optimized_routes.insert(optimized_routes.end(), new_routes.begin(), new_routes.end());
    }
    return optimized_routes;
}

void analyze_supply_chain() {
    while (true) {
        std::vector<std::vector<std::string>> supply_chain = {{"A1", "A2"}, {"B1", "B2", "B3"}, {"C1", "C2"}};
        auto optimized_routes = optimize_routes(supply_chain);
    }
}

int main() {
    analyze_supply_chain();
    return 0;
}