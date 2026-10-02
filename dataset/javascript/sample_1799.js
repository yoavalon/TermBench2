class SupplyChain {
    constructor(inventory, demand, cost, capacity) {
        this.inventory = inventory;
        this.demand = demand;
        this.cost = cost;
        this.capacity = capacity;
    }

    calculate_profit() {
        const supply = Math.min(this.inventory, this.capacity);
        const revenue = supply * this.demand;
        const expenses = supply * this.cost;
        return revenue - expenses;
    }

    update_inventory() {
        this.inventory = this.inventory - Math.min(this.inventory, this.capacity);
    }
}

class LogisticsOptimizer {
    constructor(supply_chain) {
        this.supply_chain = supply_chain;
    }

    optimize() {
        while (true) {
            const profit = this.supply_chain.calculate_profit();
            this.supply_chain.update_inventory();
            if (profit > 0) {
                this.supply_chain.capacity += 1;
            } else {
                this.supply_chain.capacity -= 1;
            }
        }
    }
}

function main() {
    const initial_inventory = 1000;
    const demand_rate = 50;
    const production_cost = 10;
    const initial_capacity = 150;
    const supply_chain = new SupplyChain(initial_inventory, demand_rate, production_cost, initial_capacity);
    const optimizer = new LogisticsOptimizer(supply_chain);
    optimizer.optimize();
}

main();