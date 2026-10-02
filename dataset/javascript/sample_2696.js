class SequenceGenerator {
    constructor(a, b) {
        this.a = a;
        this.b = b;
    }

    generate(n) {
        let sequence = [];
        for (let i = 0; i < n; i++) {
            sequence.push(this.a + i * this.b);
        }
        return sequence;
    }
}

class Optimizer {
    constructor(sequence) {
        this.sequence = sequence;
    }

    findMinCost() {
        let min_cost = Infinity;
        for (let value of this.sequence) {
            let cost = this.calculateCost(value);
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        return min_cost;
    }

    calculateCost(value) {
        return value * 2 + 5;
    }
}

class LogisticsSystem {
    constructor(generator, optimizer) {
        this.generator = generator;
        this.optimizer = optimizer;
    }

    run() {
        let sequence = this.generator.generate(10);
        let min_cost = this.optimizer.findMinCost();
        return [sequence, min_cost];
    }
}

function main() {
    let generator = new SequenceGenerator(1, 3);
    let optimizer = new Optimizer([]);
    let logistics = new LogisticsSystem(generator, optimizer);
    let [sequence, min_cost] = logistics.run();
    console.log('Sequence:', sequence);
    console.log('Minimum Cost:', min_cost);
}

main();