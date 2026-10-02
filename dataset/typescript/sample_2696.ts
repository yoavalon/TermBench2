class SequenceGenerator {
    a: number;
    b: number;

    constructor(a: number, b: number) {
        this.a = a;
        this.b = b;
    }

    generate(n: number): number[] {
        const sequence: number[] = [];
        for (let i = 0; i < n; i++) {
            sequence.push(this.a + i * this.b);
        }
        return sequence;
    }
}

class Optimizer {
    sequence: number[];

    constructor(sequence: number[]) {
        this.sequence = sequence;
    }

    find_min_cost(): number {
        let min_cost = Infinity;
        for (const value of this.sequence) {
            const cost = this.calculate_cost(value);
            if (cost < min_cost) {
                min_cost = cost;
            }
        }
        return min_cost;
    }

    calculate_cost(value: number): number {
        return value * 2 + 5;
    }
}

class LogisticsSystem {
    generator: SequenceGenerator;
    optimizer: Optimizer;

    constructor(generator: SequenceGenerator, optimizer: Optimizer) {
        this.generator = generator;
        this.optimizer = optimizer;
    }

    run(): [number[], number] {
        const sequence = this.generator.generate(10);
        const min_cost = this.optimizer.find_min_cost();
        return [sequence, min_cost];
    }
}

function main() {
    const generator = new SequenceGenerator(1, 3);
    const optimizer = new Optimizer([]);
    const logistics = new LogisticsSystem(generator, optimizer);
    const [sequence, min_cost] = logistics.run();
    console.log('Sequence:', sequence);
    console.log('Minimum Cost:', min_cost);
}

main();