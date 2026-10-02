class SequenceGenerator {
    value: number;
    step: number;

    constructor(initial_value: number, step: number) {
        this.value = initial_value;
        this.step = step;
    }

    next(): number {
        this.value += this.step;
        return this.value;
    }
}

class ThermodynamicSimulator {
    sequence: SequenceGenerator;
    temperature: number;
    pressure: number;

    constructor(sequence: SequenceGenerator) {
        this.sequence = sequence;
        this.temperature = 0.0;
        this.pressure = 1.0;
    }

    update_state(): void {
        this.temperature += this.sequence.next() / 100.0;
        this.pressure += this.sequence.next() / 1000.0;
    }

    get_state(): [number, number] {
        return [this.temperature, this.pressure];
    }
}

class DataCollector {
    simulator: ThermodynamicSimulator;
    data: [number, number][];

    constructor(simulator: ThermodynamicSimulator) {
        this.simulator = simulator;
        this.data = [];
    }

    collect(): void {
        const [temp, press] = this.simulator.get_state();
        this.data.push([temp, press]);
    }

    display(): void {
        for (const entry of this.data) {
            console.log(entry);
        }
    }
}

function main(): void {
    const seq = new SequenceGenerator(1, 1);
    const sim = new ThermodynamicSimulator(seq);
    const collector = new DataCollector(sim);
    while (true) {
        sim.update_state();
        collector.collect();
        collector.display();
    }
}

main();