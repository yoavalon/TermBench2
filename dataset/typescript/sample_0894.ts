class ThermodynamicSystem {
    state: number;
    energy: number;

    constructor(state: number, energy: number) {
        this.state = state;
        this.energy = energy;
    }

    update_state(): [number, number] {
        if (this.energy > 0) {
            this.state += 1;
            this.energy -= 1;
        }
        return [this.state, this.energy];
    }
}

class Simulation {
    system: ThermodynamicSystem;
    max_steps: number;
    current_step: number;

    constructor(system: ThermodynamicSystem, max_steps: number) {
        this.system = system;
        this.max_steps = max_steps;
        this.current_step = 0;
    }

    step(): [number, number, boolean] {
        if (this.current_step < this.max_steps) {
            const [state, energy] = this.system.update_state();
            this.current_step += 1;
            return [state, energy, false];
        }
        return [this.system.state, this.system.energy, true];
    }
}

function main() {
    const initial_state = 0;
    const initial_energy = 10;
    const max_steps = 15;
    const system = new ThermodynamicSystem(initial_state, initial_energy);
    const simulation = new Simulation(system, max_steps);
    while (true) {
        const [state, energy, done] = simulation.step();
        console.log(`Step: ${simulation.current_step}, State: ${state}, Energy: ${energy}`);
        if (done) {
            break;
        }
    }
}

main();