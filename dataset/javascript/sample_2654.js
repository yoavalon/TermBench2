class SequenceSimulator {
    constructor(a, b, n) {
        this.a = a;
        this.b = b;
        this.n = n;
        this.sequence = [];
    }

    generate_sequence() {
        for (let i = 0; i < this.n; i++) {
            let value = this.a + i * this.b;
            this.sequence.push(value);
        }
    }

    calculate_thermodynamic_states() {
        let states = [];
        for (let value of this.sequence) {
            let state = Math.exp(-value);
            states.push(state);
        }
        return states;
    }
}

class DataAnalyzer {
    constructor(data) {
        this.data = data;
    }

    average() {
        return this.data.reduce((sum, value) => sum + value, 0) / this.data.length;
    }

    max_value() {
        return Math.max(...this.data);
    }

    min_value() {
        return Math.min(...this.data);
    }
}

function main() {
    let a = 0;
    let b = 0.1;
    let n = 100;
    let simulator = new SequenceSimulator(a, b, n);
    simulator.generate_sequence();
    let states = simulator.calculate_thermodynamic_states();
    let analyzer = new DataAnalyzer(states);
    console.log('Average State:', analyzer.average());
    console.log('Max State:', analyzer.max_value());
    console.log('Min State:', analyzer.min_value());
}

main();