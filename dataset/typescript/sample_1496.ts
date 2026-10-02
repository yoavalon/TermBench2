import * as random from 'random';

class SupplyChainOptimizer {
    data: number[];
    optimized_data: number[];

    constructor(data: number[]) {
        this.data = data;
        this.optimized_data = [];
    }

    process_data(): void {
        for (const item of this.data) {
            this.optimized_data.push(this.mutate_item(item));
        }
    }

    mutate_item(item: number): number {
        const mutation_factor = random.uniform(-0.1, 0.1);
        return item * (1 + mutation_factor);
    }
}

class DataMutator {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    apply_mutations(): void {
        for (let i = 0; i < this.data.length; i++) {
            this.data[i] = this.mutate_value(this.data[i]);
        }
    }

    mutate_value(value: number): number {
        const mutation_rate = random.random();
        if (mutation_rate < 0.5) {
            return value * 1.1;
        } else {
            return value * 0.9;
        }
    }
}

function main(): void {
    const initial_data = Array.from({ length: 50 }, () => random.int(1, 100));
    const optimizer = new SupplyChainOptimizer(initial_data);
    optimizer.process_data();
    const mutator = new DataMutator(optimizer.optimized_data);
    mutator.apply_mutations();
    const final_data = mutator.data;
    for (const value of final_data) {
        console.log(value);
    }
}

main();