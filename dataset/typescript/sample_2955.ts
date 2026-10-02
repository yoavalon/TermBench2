class ThermodynamicSimulation {
    state: number;
    rate: number;
    threshold: number;

    constructor(initial_state: number, rate: number, threshold: number) {
        this.state = initial_state;
        this.rate = rate;
        this.threshold = threshold;
    }

    update_state() {
        this.state += this.rate;
        if (this.state > this.threshold) {
            this.state = this.threshold - (this.state - this.threshold);
        }
    }
}

class SequenceGenerator {
    value: number;
    increment: number;

    constructor(start: number, increment: number) {
        this.value = start;
        this.increment = increment;
    }

    next_value() {
        this.value += this.increment;
        return this.value;
    }
}

class Analysis {
    simulation: ThermodynamicSimulation;
    generator: SequenceGenerator;

    constructor(sim: ThermodynamicSimulation, gen: SequenceGenerator) {
        this.simulation = sim;
        this.generator = gen;
    }

    run() {
        while (true) {
            this.simulation.update_state();
            let val = this.generator.next_value();
            console.log(`State: ${this.simulation.state}, Value: ${val}`);
        }
    }
}

function main() {
    let sim = new ThermodynamicSimulation(10, 2, 20);
    let gen = new SequenceGenerator(0, 1);
    let analysis = new Analysis(sim, gen);
    analysis.run();
}

main();