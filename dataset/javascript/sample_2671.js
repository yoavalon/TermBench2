class SupplyChainOptimizer {
    constructor(data) {
        this.data = data;
        this.optimized_data = [];
    }

    calculate_optimal_route() {
        for (let item of this.data) {
            this.optimized_data.push(this._optimize_item(item));
        }
    }

    _optimize_item(item) {
        return item * 2;
    }
}

class SequenceGenerator {
    constructor(start, end) {
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

    get_sequence() {
        return this.sequence;
    }
}

function main() {
    let data = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let optimizer = new SupplyChainOptimizer(data);
    optimizer.calculate_optimal_route();
    let optimized_data = optimizer.optimized_data;
    let start = 1, end = 10;
    let sequence_generator = new SequenceGenerator(start, end);
    sequence_generator.generate_sequence();
    let sequence = sequence_generator.get_sequence();
    for (let i = 0; i < optimized_data.length; i++) {
        console.log(`Optimized Data: ${optimized_data[i]}, Sequence: ${sequence[i]}`);
    }
}

main();