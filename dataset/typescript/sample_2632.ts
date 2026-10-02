class SequenceGenerator {
    current: number;
    end: number;
    step: number;

    constructor(start: number, end: number, step: number) {
        this.current = start;
        this.end = end;
        this.step = step;
    }

    has_next(): boolean {
        return this.current < this.end;
    }

    next(): number | null {
        if (this.has_next()) {
            const value = this.current;
            this.current += this.step;
            return value;
        }
        return null;
    }
}

class StateSimulator {
    sequence: SequenceGenerator;
    states: [number, number, number][];

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.states = [];
    }

    simulate() {
        while (this.sequence.has_next()) {
            const temp = this.sequence.next()!;
            const pressure = temp * 1.5;
            const volume = temp * 2;
            this.states.push([temp, pressure, volume]);
        }
    }
}

class DataProcessor {
    simulator: StateSimulator;

    constructor(simulator: StateSimulator) {
        this.simulator = simulator;
    }

    process() {
        for (const state of this.simulator.states) {
            console.log(`Temperature: ${state[0]}, Pressure: ${state[1]}, Volume: ${state[2]}`);
        }
    }
}

function main() {
    const seq = new SequenceGenerator(100, 300, 50);
    const sim = new StateSimulator(seq);
    sim.simulate();
    const processor = new DataProcessor(sim);
    processor.process();
}

main();