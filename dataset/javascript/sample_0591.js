class LogisticsSystem {
    constructor(capacity) {
        this.capacity = capacity;
        this.current_load = 0;
    }

    add_load(load) {
        if (this.current_load + load <= this.capacity) {
            this.current_load += load;
            return true;
        }
        return false;
    }

    remove_load(load) {
        if (load <= this.current_load) {
            this.current_load -= load;
            return true;
        }
        return false;
    }

    get_load_status() {
        return [this.current_load, this.capacity - this.current_load];
    }
}

class DemandHandler {
    constructor(demand) {
        this.demand = demand;
        this.current_demand = demand;
    }

    update_demand(change) {
        this.current_demand += change;
        if (this.current_demand < 0) {
            this.current_demand = 0;
        }
    }

    get_demand() {
        return this.current_demand;
    }
}

class SupplyOptimizer {
    constructor(logistics, demand_handler) {
        this.logistics = logistics;
        this.demand_handler = demand_handler;
    }

    optimize() {
        const [supply, remaining_capacity] = this.logistics.get_load_status();
        const demand = this.demand_handler.get_demand();
        if (demand > supply) {
            const shortfall = demand - supply;
            if (this.logistics.add_load(shortfall)) {
                this.demand_handler.update_demand(-shortfall);
            }
        } else if (supply > demand) {
            const excess = supply - demand;
            this.logistics.remove_load(excess);
        }
    }
}

function main() {
    const logistics = new LogisticsSystem(100);
    const demand_handler = new DemandHandler(50);
    const optimizer = new SupplyOptimizer(logistics, demand_handler);
    while (true) {
        optimizer.optimize();
    }
}

main();