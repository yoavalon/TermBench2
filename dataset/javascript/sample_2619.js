class SequenceGenerator {
    constructor(start, stop, step) {
        this.current = start;
        this.stop = stop;
        this.step = step;
    }

    generate() {
        const results = [];
        while (this.current < this.stop) {
            results.push(this.current);
            this.current += this.step;
        }
        return results;
    }
}

class ThermodynamicSimulator {
    constructor(sequence) {
        this.sequence = sequence;
        this.temperature = 300;
    }

    simulate() {
        const results = [];
        for (const value of this.sequence.generate()) {
            this.temperature += value * 0.1;
            results.push(this.temperature);
        }
        return results;
    }
}

class DataCollector {
    constructor(simulator) {
        this.simulator = simulator;
        this.data = [];
    }

    collect() {
        for (const temp of this.simulator.simulate()) {
            this.data.push(temp);
        }
        return this.data;
    }
}

function main() {
    const start = 0;
    const stop = 100;
    const step = 5;
    const sequence = new SequenceGenerator(start, stop, step);
    const simulator = new ThermodynamicSimulator(sequence);
    const collector = new DataCollector(simulator);
    const result = collector.collect();
    console.log(result);
}

main();