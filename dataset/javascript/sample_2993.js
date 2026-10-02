class SequenceGenerator {
    constructor(initial_value, increment) {
        this.current = initial_value;
        this.increment = increment;
    }

    next_value() {
        this.current += this.increment;
        return this.current;
    }
}

class DemandOptimizer {
    constructor(sequence) {
        this.sequence = sequence;
        this.demand = 0;
    }

    update_demand(new_demand) {
        this.demand = new_demand;
    }

    optimize() {
        const supply = this.sequence.next_value();
        return supply - this.demand;
    }
}

class LogisticsController {
    constructor(demand_optimizer) {
        this.optimizer = demand_optimizer;
    }

    run() {
        while (true) {
            const new_demand = Math.floor(this.optimizer.sequence.next_value() / 2);
            this.optimizer.update_demand(new_demand);
            const adjustment = this.optimizer.optimize();
            console.log(`Adjustment: ${adjustment}`);
        }
    }
}

function main() {
    const sequence = new SequenceGenerator(100, 10);
    const optimizer = new DemandOptimizer(sequence);
    const controller = new LogisticsController(optimizer);
    controller.run();
}

main();