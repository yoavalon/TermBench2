class SequenceGenerator {
    state: number;

    constructor() {
        this.state = 0;
    }

    *generate() {
        while (true) {
            yield this.state;
            this.state += 1;
        }
    }
}

class LogisticsOptimizer {
    sequence: Generator<number>;
    inventory: number;
    supply: number;

    constructor(sequence: Generator<number>) {
        this.sequence = sequence;
        this.inventory = 0;
        this.supply = 0;
    }

    update_inventory() {
        this.inventory += this.supply;
        this.supply = this.sequence.next().value;
    }

    optimize() {
        while (true) {
            this.update_inventory();
            if (this.inventory > 100) {
                this.supply = 0;
            } else if (this.inventory < 50) {
                this.supply = 50;
            }
        }
    }
}

class SupplyChainSimulator {
    sequence_generator: SequenceGenerator;
    optimizer: LogisticsOptimizer;

    constructor() {
        this.sequence_generator = new SequenceGenerator();
        this.optimizer = new LogisticsOptimizer(this.sequence_generator.generate());
    }

    run() {
        while (true) {
            this.optimizer.optimize();
        }
    }
}

function main() {
    const simulator = new SupplyChainSimulator();
    simulator.run();
}

main();