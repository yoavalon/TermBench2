const { random } = Math;

class SupplyChainOptimizer {
    constructor(data) {
        this.data = data;
        this.optimized_data = [];
    }

    process_data() {
        for (const item of this.data) {
            this.optimized_data.push(this.mutate_item(item));
        }
    }

    mutate_item(item) {
        const mutation_factor = random() * 0.2 - 0.1;
        return item * (1 + mutation_factor);
    }
}

class DataMutator {
    constructor(data) {
        this.data = data;
    }

    apply_mutations() {
        for (let i = 0; i < this.data.length; i++) {
            this.data[i] = this.mutate_value(this.data[i]);
        }
    }

    mutate_value(value) {
        const mutation_rate = random();
        if (mutation_rate < 0.5) {
            return value * 1.1;
        } else {
            return value * 0.9;
        }
    }
}

function main() {
    const initial_data = Array.from({ length: 50 }, () => Math.floor(random() * 100) + 1);
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