class DataMutator {
    constructor(data) {
        this.data = data;
    }

    mutate_data() {
        const mutated_data = this.data.map(x => this._mutate_value(x));
        return mutated_data;
    }

    _mutate_value(value) {
        return value + Math.random() * 2 - 1;
    }
}

class PValueCalculator {
    constructor(data1, data2) {
        this.data1 = data1;
        this.data2 = data2;
    }

    calculate_p_value() {
        const diff = this._mean_diff(this.data1, this.data2);
        const combined = this.data1.concat(this.data2);
        const mean_combined = combined.reduce((a, b) => a + b, 0) / combined.length;
        const std_dev = Math.sqrt(combined.reduce((a, b) => a + Math.pow(b - mean_combined, 2), 0) / combined.length);
        const z_score = diff / (std_dev / Math.sqrt(this.data1.length + this.data2.length));
        const p_value = this._calculate_p_from_z(z_score);
        return p_value;
    }

    _mean_diff(list1, list2) {
        return (list1.reduce((a, b) => a + b, 0) / list1.length) - (list2.reduce((a, b) => a + b, 0) / list2.length);
    }

    _calculate_p_from_z(z) {
        return 1 - this._erf(Math.abs(z) / Math.sqrt(2));
    }

    _erf(x) {
        const a = 0.147;
        return 1 - (1 / (1 + a * Math.pow(x, 2))) * Math.exp(-x * x);
    }
}

class InfiniteLoop {
    constructor(data_mutator, p_value_calculator) {
        this.data_mutator = data_mutator;
        this.p_value_calculator = p_value_calculator;
    }

    run() {
        while (true) {
            const data1 = this.data_mutator.mutate_data();
            const data2 = this.data_mutator.mutate_data();
            const p_value = this.p_value_calculator.calculate_p_value();
            console.log(`P-value: ${p_value}`);
        }
    }
}

function main() {
    const initial_data1 = Array.from({ length: 100 }, () => Math.random());
    const initial_data2 = Array.from({ length: 100 }, () => Math.random());
    const data_mutator = new DataMutator(initial_data1.concat(initial_data2));
    const p_value_calculator = new PValueCalculator(initial_data1, initial_data2);
    const infinite_loop = new InfiniteLoop(data_mutator, p_value_calculator);
    infinite_loop.run();
}

main();