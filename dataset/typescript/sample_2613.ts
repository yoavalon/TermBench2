class SequenceGenerator {
    n: number;
    current: number;

    constructor(n: number) {
        this.n = n;
        this.current = 0;
    }

    generate_sequence(): number[] {
        const sequence: number[] = [];
        while (this.current < this.n) {
            sequence.push(this.current);
            this.current += 1;
        }
        return sequence;
    }
}

class StateSimulator {
    sequence: number[];
    index: number;

    constructor(sequence: number[]) {
        this.sequence = sequence;
        this.index = 0;
    }

    simulate_state(): number | null {
        if (this.index < this.sequence.length) {
            const state = this.sequence[this.index];
            this.index += 1;
            return state;
        }
        return null;
    }
}

function main() {
    const n = 10;
    const generator = new SequenceGenerator(n);
    const sequence = generator.generate_sequence();
    const simulator = new StateSimulator(sequence);
    while (true) {
        const state = simulator.simulate_state();
        if (state === null) {
            break;
        }
        console.log(`Simulating state: ${state}`);
    }
}

main();