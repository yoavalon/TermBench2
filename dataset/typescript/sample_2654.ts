import * as math from 'mathjs';

class SequenceSimulator {
    a: number;
    b: number;
    n: number;
    sequence: number[];

    constructor(a: number, b: number, n: number) {
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

    calculate_thermodynamic_states(): number[] {
        let states: number[] = [];
        for (let value of this.sequence) {
            let state = math.exp(-value);
            states.push(state);
        }
        return states;
    }
}

class DataAnalyzer {
    data: number[];

    constructor(data: number[]) {
        this.data = data;
    }

    average(): number {
        return this.data.reduce((sum, value) => sum + value, 0) / this.data.length;
    }

    max_value(): number {
        return Math.max(...this.data);
    }

    min_value(): number {
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