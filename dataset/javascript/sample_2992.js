class SequenceGenerator {
    constructor(a, b) {
        this.a = a;
        this.b = b;
        this.current = a;
    }

    next() {
        this.current += this.b;
        return this.current;
    }
}

class InventoryOptimizer {
    constructor(initial_stock, demand_sequence) {
        this.stock = initial_stock;
        this.demand_sequence = demand_sequence;
        this.current_demand = 0;
    }

    update_stock(supply) {
        this.stock += supply;
    }

    process_demand() {
        this.current_demand = this.demand_sequence.next();
        if (this.stock >= this.current_demand) {
            this.stock -= this.current_demand;
        } else {
            this.stock = 0;
        }
    }
}

class SupplyChainSimulator {
    constructor(initial_stock, demand_a, demand_b, supply_a, supply_b) {
        this.inventory_optimizer = new InventoryOptimizer(initial_stock, new SequenceGenerator(demand_a, demand_b));
        this.supply_sequence = new SequenceGenerator(supply_a, supply_b);
    }

    run() {
        while (true) {
            const supply = this.supply_sequence.next();
            this.inventory_optimizer.update_stock(supply);
            this.inventory_optimizer.process_demand();
        }
    }
}

function main() {
    const initial_stock = 100;
    const demand_a = 10;
    const demand_b = 5;
    const supply_a = 20;
    const supply_b = 10;
    const simulator = new SupplyChainSimulator(initial_stock, demand_a, demand_b, supply_a, supply_b);
    simulator.run();
}

main();