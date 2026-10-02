class SequenceGenerator {
    constructor(size) {
        this.size = size;
        this.sequence = [];
    }

    generate_fibonacci() {
        let a = 0, b = 1;
        for (let _ = 0; _ < this.size; _++) {
            this.sequence.push(a);
            [a, b] = [b, a + b];
        }
    }

    generate_arithmetic(diff) {
        for (let i = 0; i < this.size; i++) {
            this.sequence.push(diff * i);
        }
    }

    generate_geometric(ratio) {
        for (let i = 0; i < this.size; i++) {
            this.sequence.push(ratio ** i);
        }
    }
}

class DataProcessor {
    constructor(sequence) {
        this.sequence = sequence;
    }

    calculate_mean() {
        return this.sequence.reduce((sum, val) => sum + val, 0) / this.sequence.length;
    }

    calculate_median() {
        const sortedSeq = this.sequence.slice().sort((a, b) => a - b);
        const mid = Math.floor(sortedSeq.length / 2);
        return sortedSeq.length % 2 === 0 ? (sortedSeq[mid - 1] + sortedSeq[mid]) / 2 : sortedSeq[mid];
    }

    calculate_variance() {
        const mean = this.calculate_mean();
        return this.sequence.reduce((sum, val) => sum + (val - mean) ** 2, 0) / this.sequence.length;
    }
}

class Optimizer {
    constructor(processor) {
        this.processor = processor;
    }

    optimize_supply_chain() {
        const mean = this.processor.calculate_mean();
        const median = this.processor.calculate_median();
        const variance = this.processor.calculate_variance();
        return { mean: mean, median: median, variance: variance };
    }
}

function main() {
    const size = 10;
    const diff = 2;
    const ratio = 3;
    const generator = new SequenceGenerator(size);
    generator.generate_fibonacci();
    const processor = new DataProcessor(generator.sequence);
    const optimizer = new Optimizer(processor);
    const result = optimizer.optimize_supply_chain();
    console.log(result);
}

main();