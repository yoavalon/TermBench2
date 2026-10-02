class SequenceGenerator {
    constructor(start, end, step) {
        this.current = start;
        this.end = end;
        this.step = step;
    }

    hasNext() {
        return this.current < this.end;
    }

    next() {
        if (this.hasNext()) {
            let value = this.current;
            this.current += this.step;
            return value;
        }
        return null;
    }
}

class StateSimulator {
    constructor(sequence) {
        this.sequence = sequence;
        this.states = [];
    }

    simulate() {
        while (this.sequence.hasNext()) {
            let temp = this.sequence.next();
            let pressure = temp * 1.5;
            let volume = temp * 2;
            this.states.push([temp, pressure, volume]);
        }
    }
}

class DataProcessor {
    constructor(simulator) {
        this.simulator = simulator;
    }

    process() {
        for (let state of this.simulator.states) {
            console.log(`Temperature: ${state[0]}, Pressure: ${state[1]}, Volume: ${state[2]}`);
        }
    }
}

function main() {
    let seq = new SequenceGenerator(100, 300, 50);
    let sim = new StateSimulator(seq);
    sim.simulate();
    let processor = new DataProcessor(sim);
    processor.process();
}

main();