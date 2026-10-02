class Simulation {
    state: number;

    constructor(state: number) {
        this.state = state;
    }

    update_state(change: number): void {
        this.state += change;
    }

    is_stable(): boolean {
        return Math.abs(this.state) < 0.01;
    }
}

class BoundaryConditions {
    min_val: number;
    max_val: number;

    constructor(min_val: number, max_val: number) {
        this.min_val = min_val;
        this.max_val = max_val;
    }

    enforce_boundaries(state: number): number {
        if (state < this.min_val) {
            return this.min_val;
        } else if (state > this.max_val) {
            return this.max_val;
        }
        return state;
    }
}

class Controller {
    simulation: Simulation;
    boundary_conditions: BoundaryConditions;

    constructor(simulation: Simulation, boundary_conditions: BoundaryConditions) {
        this.simulation = simulation;
        this.boundary_conditions = boundary_conditions;
    }

    run(): void {
        const change = 0.1;
        while (true) {
            this.simulation.update_state(change);
            this.simulation.state = this.boundary_conditions.enforce_boundaries(this.simulation.state);
            if (this.simulation.is_stable()) {
                break;
            }
        }
    }
}

function main(): void {
    const simulation = new Simulation(0.0);
    const boundary_conditions = new BoundaryConditions(-1.0, 1.0);
    const controller = new Controller(simulation, boundary_conditions);
    controller.run();
}

main();