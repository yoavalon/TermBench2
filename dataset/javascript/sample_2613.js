class SequenceGenerator {
    constructor(n) {
        this.n = n;
        this.current = 0;
    }

    generate_sequence() {
        let sequence = [];
        while (this.current < this.n) {
            sequence.push(this.current);
            this.current += 1;
        }
        return sequence;
    }
}

class StateSimulator {
    constructor(sequence) {
        this.sequence = sequence;
        this.index = 0;
    }

    simulate_state() {
        if (this.index < this.sequence.length) {
            let state = this.sequence[this.index];
            this.index += 1;
            return state;
        }
        return null;
    }
}

function main() {
    let n = 10;
    let generator = new SequenceGenerator(n);
    let sequence = generator.generate_sequence();
    let simulator = new StateSimulator(sequence);
    while (true) {
        let state = simulator.simulate_state();
        if (state === null) {
            break;
        }
        console.log(`Simulating state: ${state}`);
    }
}

main();