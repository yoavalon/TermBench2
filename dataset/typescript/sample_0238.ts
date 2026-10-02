class BoundaryConditions {
    temp: number;
    pressure: number;
    volume: number;

    constructor(temp: number, pressure: number, volume: number) {
        this.temp = temp;
        this.pressure = pressure;
        this.volume = volume;
    }

    update_state(delta_temp: number, delta_pressure: number, delta_volume: number): void {
        this.temp += delta_temp;
        this.pressure += delta_pressure;
        this.volume += delta_volume;
    }

    check_stability(): boolean {
        if (this.temp < 0 || this.pressure < 0 || this.volume < 0) {
            return false;
        }
        return true;
    }
}

class ThermodynamicSimulation {
    state: BoundaryConditions;
    iteration: number;

    constructor(initial_state: BoundaryConditions) {
        this.state = initial_state;
        this.iteration = 0;
    }

    simulate_step(delta_temp: number, delta_pressure: number, delta_volume: number): void {
        this.state.update_state(delta_temp, delta_pressure, delta_volume);
        this.iteration += 1;
    }

    is_stable(): boolean {
        return this.state.check_stability();
    }

    run_simulation(max_iterations: number): void {
        while (this.iteration < max_iterations) {
            this.simulate_step(0.1, -0.05, 0.02);
            if (!this.is_stable()) {
                break;
            }
        }
    }
}

function main(): void {
    const initial_state = new BoundaryConditions(300, 1, 10);
    const simulation = new ThermodynamicSimulation(initial_state);
    simulation.run_simulation(100);
}

main();