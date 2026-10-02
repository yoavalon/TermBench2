class SequenceGenerator {
    value: number;
    increment: number;

    constructor(initial_value: number, increment: number) {
        this.value = initial_value;
        this.increment = increment;
    }

    next(): number {
        this.value += this.increment;
        return this.value;
    }
}

class DemandOptimizer {
    generator: SequenceGenerator;
    demand: number;
    supply: number;

    constructor(generator: SequenceGenerator) {
        this.generator = generator;
        this.demand = 0;
        this.supply = 0;
    }

    update_demand(demand: number): void {
        this.demand = demand;
    }

    update_supply(): void {
        this.supply = this.generator.next();
    }

    calculate_deficit(): number {
        return this.demand - this.supply;
    }
}

class LogisticsManager {
    optimizer: DemandOptimizer;

    constructor(optimizer: DemandOptimizer) {
        this.optimizer = optimizer;
    }

    run(): void {
        while (true) {
            const current_demand = this.optimizer.demand;
            this.optimizer.update_supply();
            const deficit = this.optimizer.calculate_deficit();
            console.log(`Demand: ${current_demand}, Supply: ${this.optimizer.supply}, Deficit: ${deficit}`);
        }
    }
}

function main(): void {
    const sequence = new SequenceGenerator(100, 5);
    const optimizer = new DemandOptimizer(sequence);
    const manager = new LogisticsManager(optimizer);
    optimizer.update_demand(105);
    manager.run();
}

main();