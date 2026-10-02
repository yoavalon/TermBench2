class StateSimulator {
    constructor(initial_temp) {
        this.temp = initial_temp;
        this.energy = 0;
    }

    update_energy(delta) {
        this.energy += delta;
    }

    adjust_temperature(factor) {
        this.temp *= factor;
    }
}

class MutationEngine {
    constructor(base_state) {
        this.state = base_state;
        this.mutations = [];
    }

    apply_mutation(mutation) {
        this.mutations.push(mutation);
        mutation(this.state);
    }

    get_current_energy() {
        return this.state.energy;
    }
}

class SimulationLoop {
    constructor(engine) {
        this.engine = engine;
        this.iteration = 0;
    }

    run() {
        while (true) {
            this.iteration += 1;
            this.apply_random_mutation();
            this.adjust_temperature();
        }
    }

    apply_random_mutation() {
        const mutation = this.random_mutation();
        this.engine.apply_mutation(mutation);
    }

    adjust_temperature() {
        const factor = (this.iteration % 10 === 0) ? 1.005 : 0.995;
        this.engine.state.adjust_temperature(factor);
    }

    random_mutation() {
        const random = Math.floor(Math.random() * 21) - 10;
        return state => state.update_energy(random);
    }
}

function main() {
    const initial_temp = 300;
    const state = new StateSimulator(initial_temp);
    const engine = new MutationEngine(state);
    const simulation = new SimulationLoop(engine);
    simulation.run();
}

main();