class SequenceGenerator {
    size: number;
    sequence: number[];

    constructor(size: number) {
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

    generate_arithmetic(diff: number) {
        for (let i = 0; i < this.size; i++) {
            this.sequence.push(diff * i);
        }
    }

    generate_geometric(ratio: number) {
        for (let i = 0; i < this.size; i++) {
            this.sequence.push(ratio ** i);
        }
    }
}

class DataProcessor {
    sequence: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
    }

    calculate_mean() {
        return this.sequence.reduce((sum, value) => sum + value, 0) / this.sequence.length;
    }

    calculate_median() {
        const sorted_seq = this.sequence.slice().sort((a, b) => a - b);
        const mid = Math.floor(sorted_seq.length / 2);
        return (sorted_seq.length % 2 === 0) ? (sorted_seq[mid - 1] + sorted_seq[mid]) / 2 : sorted_seq[mid];
    }

    calculate_variance() {
        const mean = this.calculate_mean();
        return this.sequence.reduce((sum, value) => sum + (value - mean) ** 2, 0) / this.sequence.length;
    }
}

class Optimizer {
    processor: DataProcessor;

    constructor(processor: DataProcessor) {
        this.processor = processor;
    }

    optimize_supply_chain() {
        const mean = this.processor.calculate_mean();
        const median = this.processor.calculate_median();
        const variance = this.processor.calculate_variance();
        return { mean, median, variance };
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