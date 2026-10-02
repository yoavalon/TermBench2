class SupplyChain {
    inventory: number;
    demand: number[];
    orders: number[];
    deliveries: number[];

    constructor(inventory: number, demand: number[]) {
        this.inventory = inventory;
        this.demand = demand;
        this.orders = [];
        this.deliveries = [];
    }

    process_orders(): void {
        while (this.orders.length > 0) {
            const order = this.orders.shift()!;
            if (this.inventory >= order) {
                this.inventory -= order;
                this.deliveries.push(order);
            } else {
                this.orders.unshift(order);
            }
        }
    }

    receive_supply(supply: number): void {
        this.inventory += supply;
    }

    handle_demand(): void {
        for (let _ = 0; _ < this.demand.length; _++) {
            if (this.demand.length > 0) {
                const order = this.demand.shift()!;
                this.orders.push(order);
            }
        }
    }
}

class LogisticsOptimizer {
    supply_chain: SupplyChain;

    constructor(supply_chain: SupplyChain) {
        this.supply_chain = supply_chain;
    }

    optimize(): void {
        while (true) {
            this.supply_chain.handle_demand();
            this.supply_chain.process_orders();
            if (this.supply_chain.orders.length > 0) {
                this.supply_chain.receive_supply(this.supply_chain.orders.reduce((a, b) => a + b, 0));
            }
        }
    }
}

function main(): void {
    const inventory = 100;
    const demand = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
    const supply_chain = new SupplyChain(inventory, demand);
    const optimizer = new LogisticsOptimizer(supply_chain);
    optimizer.optimize();
}

main();