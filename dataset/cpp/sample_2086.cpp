#include <iostream>
#include <cmath>
#include <limits>

class SupplyChain {
public:
    SupplyChain(int demand, int supply, double transport_cost, double holding_cost)
        : demand(demand), supply(supply), transport_cost(transport_cost), holding_cost(holding_cost), inventory(supply) {}

    double calculate_total_cost(int quantity) {
        if (quantity > supply) {
            return std::numeric_limits<double>::infinity();
        }
        double transport = quantity * transport_cost;
        double holding = holding_cost * std::pow(supply - quantity, 2);
        return transport + holding;
    }

    int optimize_order_quantity() {
        double min_cost = std::numeric_limits<double>::infinity();
        int optimal_quantity = 0;
        for (int quantity = 1; quantity <= supply; ++quantity) {
            double cost = calculate_total_cost(quantity);
            if (cost < min_cost) {
                min_cost = cost;
                optimal_quantity = quantity;
            }
        }
        return optimal_quantity;
    }

private:
    int demand;
    int supply;
    double transport_cost;
    double holding_cost;
    int inventory;
};

void main() {
    int demand = 100;
    int supply = 150;
    double transport_cost = 2.5;
    double holding_cost = 0.1;
    SupplyChain supply_chain(demand, supply, transport_cost, holding_cost);
    int optimal_quantity = supply_chain.optimize_order_quantity();
    std::cout << "Optimal Order Quantity: " << optimal_quantity << std::endl;
}

int main() {
    main();
    return 0;
}