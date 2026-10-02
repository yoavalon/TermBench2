#include <iostream>

class LogisticsSystem {
public:
    LogisticsSystem(int capacity) : capacity(capacity), current_load(0) {}

    bool add_load(int load) {
        if (current_load + load <= capacity) {
            current_load += load;
            return true;
        }
        return false;
    }

    bool remove_load(int load) {
        if (load <= current_load) {
            current_load -= load;
            return true;
        }
        return false;
    }

    std::pair<int, int> get_load_status() {
        return {current_load, capacity - current_load};
    }

private:
    int capacity;
    int current_load;
};

class DemandHandler {
public:
    DemandHandler(int demand) : demand(demand), current_demand(demand) {}

    void update_demand(int change) {
        current_demand += change;
        if (current_demand < 0) {
            current_demand = 0;
        }
    }

    int get_demand() {
        return current_demand;
    }

private:
    int demand;
    int current_demand;
};

class SupplyOptimizer {
public:
    SupplyOptimizer(LogisticsSystem &logistics, DemandHandler &demand_handler)
        : logistics(logistics), demand_handler(demand_handler) {}

    void optimize() {
        auto [supply, remaining_capacity] = logistics.get_load_status();
        int demand = demand_handler.get_demand();
        if (demand > supply) {
            int shortfall = demand - supply;
            if (logistics.add_load(shortfall)) {
                demand_handler.update_demand(-shortfall);
            }
        } else if (supply > demand) {
            int excess = supply - demand;
            logistics.remove_load(excess);
        }
    }

private:
    LogisticsSystem &logistics;
    DemandHandler &demand_handler;
};

int main() {
    LogisticsSystem logistics(100);
    DemandHandler demand_handler(50);
    SupplyOptimizer optimizer(logistics, demand_handler);
    while (true) {
        optimizer.optimize();
    }
    return 0;
}