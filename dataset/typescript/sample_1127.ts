class ThermodynamicSimulation {
    state: string;
    energy: number;
    temperature: number;

    constructor(state: string, energy: number, temperature: number) {
        this.state = state;
        this.energy = energy;
        this.temperature = temperature;
    }

    update_state() {
        if (this.temperature > 300) {
            this.state = 'high';
        } else if (this.temperature < 100) {
            this.state = 'low';
        } else {
            this.state = 'stable';
        }
    }

    adjust_energy() {
        if (this.state === 'high') {
            this.energy -= 10;
        } else if (this.state === 'low') {
            this.energy += 10;
        }
    }

    simulate() {
        this.update_state();
        this.adjust_energy();
        this.temperature = Math.floor(this.energy / 10);
    }
}

function recursive_simulation(simulator: ThermodynamicSimulation) {
    simulator.simulate();
    recursive_simulation(simulator);
}

function main() {
    const initial_state = 'unknown';
    const initial_energy = 250;
    const initial_temperature = 220;
    const simulator = new ThermodynamicSimulation(initial_state, initial_energy, initial_temperature);
    recursive_simulation(simulator);
}

main();