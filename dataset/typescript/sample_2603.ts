class SequenceGenerator {
    a: number;
    b: number;
    n: number;
    current: number;

    constructor(a: number, b: number, n: number) {
        this.a = a;
        this.b = b;
        this.n = n;
        this.current = a;
    }

    generate_next(): number | null {
        if (this.current < this.n) {
            this.current += this.b;
            return this.current;
        }
        return null;
    }
}

class LogisticsOptimizer {
    sequence: SequenceGenerator;
    optimized: number[];

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.optimized = [];
    }

    optimize(): number[] {
        while (true) {
            const next_value = this.sequence.generate_next();
            if (next_value === null) {
                break;
            }
            this.optimized.push(next_value);
        }
        return this.optimized;
    }
}

function main() {
    const a = 1;
    const b = 2;
    const n = 20;
    const sequence = new SequenceGenerator(a, b, n);
    const optimizer = new LogisticsOptimizer(sequence);
    const result = optimizer.optimize();
    console.log(result);
}

main();