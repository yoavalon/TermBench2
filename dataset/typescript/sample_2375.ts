import * as random from 'random';

class Inventory {
    stock: number;
    replenish_rate: number;

    constructor(initial_stock: number, replenish_rate: number) {
        this.stock = initial_stock;
        this.replenish_rate = replenish_rate;
    }

    update_stock(demand: number): void {
        this.stock -= demand;
        if (this.stock < 0) {
            this.stock = 0;
        }
    }

    replenish(): void {
        this.stock += this.replenish_rate;
    }
}

class DemandGenerator {
    generate(): number {
        return random.uniform(1, 10);
    }
}

class SupplyChainOptimizer {
    inventory: Inventory;
    demand_generator: DemandGenerator;

    constructor(inventory: Inventory, demand_generator: DemandGenerator) {
        this.inventory = inventory;
        this.demand_generator = demand_generator;
    }

    run_optimization(): void {
        while (true) {
            const demand = this.demand_generator.generate();
            this.inventory.update_stock(demand);
            this.inventory.replenish();
        }
    }
}

function main(): void {
    const initial_stock = 100;
    const replenish_rate = 10;
    const inventory = new Inventory(initial_stock, replenish_rate);
    const demand_generator = new DemandGenerator();
    const optimizer = new SupplyChainOptimizer(inventory, demand_generator);
    optimizer.run_optimization();
}

main();