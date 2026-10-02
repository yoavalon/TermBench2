class SequenceGenerator {
    constructor(initial_value, increment) {
        this.value = initial_value;
        this.increment = increment;
    }

    next() {
        this.value += this.increment;
        return this.value;
    }
}

class DemandOptimizer {
    constructor(generator) {
        this.generator = generator;
        this.demand = 0;
        this.supply = 0;
    }

    update_demand(demand) {
        this.demand = demand;
    }

    update_supply() {
        this.supply = this.generator.next();
    }

    calculate_deficit() {
        return this.demand - this.supply;
    }
}

class LogisticsManager {
    constructor(optimizer) {
        this.optimizer = optimizer;
    }

    run() {
        while (true) {
            const current_demand = this.optimizer.demand;
            this.optimizer.update_supply();
            const deficit = this.optimizer.calculate_deficit();
            console.log(`Demand: ${current_demand}, Supply: ${this.optimizer.supply}, Deficit: ${deficit}`);
        }
    }
}

function main() {
    const sequence = new SequenceGenerator(100, 5);
    const optimizer = new DemandOptimizer(sequence);
    const manager = new LogisticsManager(optimizer);
    optimizer.update_demand(105);
    manager.run();
}

main();