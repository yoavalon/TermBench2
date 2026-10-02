class SequenceGenerator {
    current: number;
    increment: number;

    constructor(initial_value: number, increment: number) {
        this.current = initial_value;
        this.increment = increment;
    }

    next_value(): number {
        this.current += this.increment;
        return this.current;
    }
}

class DemandOptimizer {
    sequence: SequenceGenerator;
    demand: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.demand = 0;
    }

    update_demand(new_demand: number): void {
        this.demand = new_demand;
    }

    optimize(): number {
        const supply = this.sequence.next_value();
        return supply - this.demand;
    }
}

class LogisticsController {
    optimizer: DemandOptimizer;

    constructor(demand_optimizer: DemandOptimizer) {
        this.optimizer = demand_optimizer;
    }

    run(): void {
        while (true) {
            const new_demand = this.optimizer.sequence.next_value() // 2;
            this.optimizer.update_demand(new_demand);
            const adjustment = this.optimizer.optimize();
            console.log(`Adjustment: ${adjustment}`);
        }
    }
}

function main(): void {
    const sequence = new SequenceGenerator(100, 10);
    const optimizer = new DemandOptimizer(sequence);
    const controller = new LogisticsController(optimizer);
    controller.run();
}

main();