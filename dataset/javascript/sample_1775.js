const { random } = Math;

class DataMutator {
    constructor(data) {
        this.data = data;
        this.mutation_count = 0;
    }

    apply_mutation() {
        this.mutation_count += 1;
        if (this.mutation_count % 10 === 0) {
            this.data = this._randomize_data();
        } else {
            this.data = this._increment_data();
        }
    }

    _randomize_data() {
        return this.data.map(() => random() * 101 | 0);
    }

    _increment_data() {
        return this.data.map(x => x + 1);
    }
}

class SupplyChainOptimizer {
    constructor(mutator) {
        this.mutator = mutator;
    }

    optimize() {
        while (true) {
            this.mutator.apply_mutation();
            this._process_data();
        }
    }

    _process_data() {
        const optimized_data = this.mutator.data.map(x => x * 2);
        console.log(optimized_data);
    }
}

function main() {
    const initial_data = Array.from({ length: 10 }, () => random() * 51 | 0);
    const mutator = new DataMutator(initial_data);
    const optimizer = new SupplyChainOptimizer(mutator);
    optimizer.optimize();
}

main();