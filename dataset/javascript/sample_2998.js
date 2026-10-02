class SequenceGenerator {
    constructor(initial_value, step) {
        this.value = initial_value;
        this.step = step;
    }

    next() {
        this.value += this.step;
        return this.value;
    }
}

class ThermodynamicSimulator {
    constructor(sequence) {
        this.sequence = sequence;
        this.temperature = 0.0;
        this.pressure = 1.0;
    }

    update_state() {
        this.temperature += this.sequence.next() / 100.0;
        this.pressure += this.sequence.next() / 1000.0;
    }

    get_state() {
        return [this.temperature, this.pressure];
    }
}

class DataCollector {
    constructor(simulator) {
        this.simulator = simulator;
        this.data = [];
    }

    collect() {
        let [temp, press] = this.simulator.get_state();
        this.data.push([temp, press]);
    }

    display() {
        for (let entry of this.data) {
            console.log(entry);
        }
    }
}

function main() {
    let seq = new SequenceGenerator(1, 1);
    let sim = new ThermodynamicSimulator(seq);
    let collector = new DataCollector(sim);
    while (true) {
        sim.update_state();
        collector.collect();
        collector.display();
    }
}

main();