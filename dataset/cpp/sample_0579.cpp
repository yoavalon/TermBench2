#include <iostream>
#include <vector>
#include <deque>

class SupplyChain {
public:
    int inventory;
    std::vector<int> demand;
    std::deque<int> orders;
    std::vector<int> deliveries;

    SupplyChain(int inventory, std::vector<int> demand) : inventory(inventory), demand(demand) {}

    void process_orders() {
        while (!orders.empty()) {
            int order = orders.front();
            orders.pop_front();
            if (inventory >= order) {
                inventory -= order;
                deliveries.push_back(order);
            } else {
                orders.push_front(order);
            }
        }
    }

    void receive_supply(int supply) {
        inventory += supply;
    }

    void handle_demand() {
        for (size_t i = 0; i < demand.size(); ++i) {
            if (!demand.empty()) {
                int order = demand.front();
                demand.erase(demand.begin());
                orders.push_back(order);
            }
        }
    }
};

class LogisticsOptimizer {
public:
    SupplyChain& supply_chain;

    LogisticsOptimizer(SupplyChain& supply_chain) : supply_chain(supply_chain) {}

    void optimize() {
        while (true) {
            supply_chain.handle_demand();
            supply_chain.process_orders();
            if (!supply_chain.orders.empty()) {
                int total_orders = 0;
                for (int order : supply_chain.orders) {
                    total_orders += order;
                }
                supply_chain.receive_supply(total_orders);
            }
        }
    }
};

int main() {
    int inventory = 100;
    std::vector<int> demand = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    SupplyChain supply_chain(inventory, demand);
    LogisticsOptimizer optimizer(supply_chain);
    optimizer.optimize();
    return 0;
}