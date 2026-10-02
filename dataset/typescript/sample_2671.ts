class SupplyChainOptimizer {
    data: number[];
    optimized_data: number[];

    constructor(data: number[]) {
        this.data = data;
        this.optimized_data = [];
    }

    calculate_optimal_route() {
        for (let item of this.data) {
            this.optimized_data.push(this._optimize_item(item));
        }
    }

    _optimize_item(item: number): number {
        return item * 2;
    }
}

class SequenceGenerator {
    start: number;
    end: number;
    sequence: number[];

    constructor(start: number, end: number) {
        this.start = start;
        this.end = end;
        this.sequence = [];
    }

    generate_sequence() {
        let current = this.start;
        while (current <= this.end) {
            this.sequence.push(current);
            current += 1;
        }
    }

    get_sequence(): number[] {
        return this.sequence;
    }
}

function main() {
    const data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const optimizer = new SupplyChainOptimizer(data);
    optimizer.calculate_optimal_route();
    const optimized_data = optimizer.optimized_data;
    const start = 1;
    const end = 10;
    const sequence_generator = new SequenceGenerator(start, end);
    sequence_generator.generate_sequence();
    const sequence = sequence_generator.get_sequence();
    for (let i = 0; i < optimized_data.length; i++) {
        console.log(`Optimized Data: ${optimized_data[i]}, Sequence: ${sequence[i]}`);
    }
}

main();