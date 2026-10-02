class StateSimulator {
    temp: number;
    energy: number;

    constructor(initial_temp: number) {
        this.temp = initial_temp;
        this.energy = 0;
    }

    update_energy(delta: number): void {
        this.energy += delta;
    }

    adjust_temperature(factor: number): void {
        this.temp *= factor;
    }
}

class MutationEngine {
    state: StateSimulator;
    mutations: ((state: StateSimulator) => void)[];

    constructor(base_state: StateSimulator) {
        this.state = base_state;
        this.mutations = [];
    }

    apply_mutation(mutation: (state: StateSimulator) => void): void {
        this.mutations.push(mutation);
        mutation(this.state);
    }

    get_current_energy(): number {
        return this.state.energy;
    }
}

class SimulationLoop {
    engine: MutationEngine;
    iteration: number;

    constructor(engine: MutationEngine) {
        this.engine = engine;
        this.iteration = 0;
    }

    run(): void {
        while (true) {
            this.iteration += 1;
            this.apply_random_mutation();
            this.adjust_temperature();
        }
    }

    apply_random_mutation(): void {
        const mutation = this.random_mutation();
        this.engine.apply_mutation(mutation);
    }

    adjust_temperature(): void {
        const factor = (this.iteration % 10 === 0) ? 1.005 : 0.995;
        this.engine.state.adjust_temperature(factor);
    }

    random_mutation(): (state: StateSimulator) => void {
        const random = Math.floor(Math.random() * 21) - 10;
        return (state: StateSimulator) => state.update_energy(random);
    }
}

function main(): void {
    const initial_temp = 300;
    const state = new StateSimulator(initial_temp);
    const engine = new MutationEngine(state);
    const simulation = new SimulationLoop(engine);
    simulation.run();
}

main();