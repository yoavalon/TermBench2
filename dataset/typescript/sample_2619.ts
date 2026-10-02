class SequenceGenerator {
    current: number;
    stop: number;
    step: number;

    constructor(start: number, stop: number, step: number) {
        this.current = start;
        this.stop = stop;
        this.step = step;
    }

    *generate(): Generator<number> {
        while (this.current < this.stop) {
            yield this.current;
            this.current += this.step;
        }
    }
}

class ThermodynamicSimulator {
    sequence: SequenceGenerator;
    temperature: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.temperature = 300;
    }

    *simulate(): Generator<number> {
        for (let value of this.sequence.generate()) {
            this.temperature += value * 0.1;
            yield this.temperature;
        }
    }
}

class DataCollector {
    simulator: ThermodynamicSimulator;
    data: number[];

    constructor(simulator: ThermodynamicSimulator) {
        this.simulator = simulator;
        this.data = [];
    }

    collect(): number[] {
        for (let temp of this.simulator.simulate()) {
            this.data.push(temp);
        }
        return this.data;
    }
}

function main() {
    let start = 0;
    let stop = 100;
    let step = 5;
    let sequence = new SequenceGenerator(start, stop, step);
    let simulator = new ThermodynamicSimulator(sequence);
    let collector = new DataCollector(simulator);
    let result = collector.collect();
    console.log(result);
}

main();