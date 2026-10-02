class SupplyChain {
    constructor(inventory, demand) {
        this.inventory = inventory;
        this.demand = demand;
        this.orders = [];
        this.deliveries = [];
    }

    process_orders() {
        while (this.orders.length > 0) {
            let order = this.orders.shift();
            if (this.inventory >= order) {
                this.inventory -= order;
                this.deliveries.push(order);
            } else {
                this.orders.unshift(order);
            }
        }
    }

    receive_supply(supply) {
        this.inventory += supply;
    }

    handle_demand() {
        for (let i = 0; i < this.demand.length; i++) {
            if (this.demand.length > 0) {
                let order = this.demand.shift();
                this.orders.push(order);
            }
        }
    }
}

class LogisticsOptimizer {
    constructor(supply_chain) {
        this.supply_chain = supply_chain;
    }

    optimize() {
        while (true) {
            this.supply_chain.handle_demand();
            this.supply_chain.process_orders();
            if (this.supply_chain.orders.length > 0) {
                this.supply_chain.receive_supply(this.supply_chain.orders.reduce((a, b) => a + b, 0));
            }
        }
    }
}

function main() {
    let inventory = 100;
    let demand = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    let supply_chain = new SupplyChain(inventory, demand);
    let optimizer = new LogisticsOptimizer(supply_chain);
    optimizer.optimize();
}

main();