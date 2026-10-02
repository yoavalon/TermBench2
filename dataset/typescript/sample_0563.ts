class SimulationState {
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
}

class BoundaryConditions {
    max_temp: number;
    min_temp: number;
    max_pressure: number;
    min_pressure: number;
    max_volume: number;
    min_volume: number;

    constructor(max_temp: number, min_temp: number, max_pressure: number, min_pressure: number, max_volume: number, min_volume: number) {
        this.max_temp = max_temp;
        this.min_temp = min_temp;
        this.max_pressure = max_pressure;
        this.min_pressure = min_pressure;
        this.max_volume = max_volume;
        this.min_volume = min_volume;
    }

    check_boundaries(state: SimulationState): boolean {
        if (state.temp > this.max_temp || state.temp < this.min_temp) {
            return false;
        }
        if (state.pressure > this.max_pressure || state.pressure < this.min_pressure) {
            return false;
        }
        if (state.volume > this.max_volume || state.volume < this.min_volume) {
            return false;
        }
        return true;
    }
}

class SimulationEngine {
    state: SimulationState;
    boundary_conditions: BoundaryConditions;
    step_size: number;

    constructor(initial_state: SimulationState, boundary_conditions: BoundaryConditions, step_size: number) {
        this.state = initial_state;
        this.boundary_conditions = boundary_conditions;
        this.step_size = step_size;
    }

    run_simulation(): void {
        while (true) {
            this.state.update_state(this.step_size, this.step_size, this.step_size);
            if (!this.boundary_conditions.check_boundaries(this.state)) {
                this.state.update_state(-this.step_size, -this.step_size, -this.step_size);
            } else {
                console.log(`Temp: ${this.state.temp}, Pressure: ${this.state.pressure}, Volume: ${this.state.volume}`);
            }
        }
    }
}

function main() {
    const initial_state = new SimulationState(300, 1, 10);
    const boundary_conditions = new BoundaryConditions(400, 200, 2, 0.5, 20, 5);
    const simulation_engine = new SimulationEngine(initial_state, boundary_conditions, 0.1);
    simulation_engine.run_simulation();
}

main();