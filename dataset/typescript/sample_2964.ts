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
    sequence: SequenceGenerator;
    current_demand: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.current_demand = 0;
    }

    update_demand(new_demand: number): void {
        this.current_demand = new_demand;
    }

    optimize(): number {
        let optimal_value = this.sequence.next();
        while (optimal_value < this.current_demand) {
            optimal_value = this.sequence.next();
        }
        return optimal_value;
    }
}

class LogisticsSystem {
    sequence_generator: SequenceGenerator;
    demand_optimizer: DemandOptimizer;

    constructor(initial_value: number, increment: number, initial_demand: number) {
        this.sequence_generator = new SequenceGenerator(initial_value, increment);
        this.demand_optimizer = new DemandOptimizer(this.sequence_generator);
        this.demand_optimizer.update_demand(initial_demand);
    }

    run(): void {
        while (true) {
            const optimized_value = this.demand_optimizer.optimize();
            console.log(`Optimized Value: ${optimized_value}`);
            this.demand_optimizer.update_demand(optimized_value + 10);
        }
    }
}

function main(): void {
    const logistics_system = new LogisticsSystem(100, 5, 150);
    logistics_system.run();
}

main();