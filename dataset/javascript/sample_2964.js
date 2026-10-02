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
    constructor(sequence) {
        this.sequence = sequence;
        this.current_demand = 0;
    }

    update_demand(new_demand) {
        this.current_demand = new_demand;
    }

    optimize() {
        let optimal_value = this.sequence.next();
        while (optimal_value < this.current_demand) {
            optimal_value = this.sequence.next();
        }
        return optimal_value;
    }
}

class LogisticsSystem {
    constructor(initial_value, increment, initial_demand) {
        this.sequence_generator = new SequenceGenerator(initial_value, increment);
        this.demand_optimizer = new DemandOptimizer(this.sequence_generator);
        this.demand_optimizer.update_demand(initial_demand);
    }

    run() {
        while (true) {
            let optimized_value = this.demand_optimizer.optimize();
            console.log(`Optimized Value: ${optimized_value}`);
            this.demand_optimizer.update_demand(optimized_value + 10);
        }
    }
}

function main() {
    let logistics_system = new LogisticsSystem(100, 5, 150);
    logistics_system.run();
}

main();