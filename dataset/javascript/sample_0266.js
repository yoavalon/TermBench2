class Simulation {
    constructor(state) {
        this.state = state;
    }

    update_state(change) {
        this.state += change;
    }

    is_stable() {
        return Math.abs(this.state) < 0.01;
    }
}

class BoundaryConditions {
    constructor(min_val, max_val) {
        this.min_val = min_val;
        this.max_val = max_val;
    }

    enforce_boundaries(state) {
        if (state < this.min_val) {
            return this.min_val;
        } else if (state > this.max_val) {
            return this.max_val;
        }
        return state;
    }
}

class Controller {
    constructor(simulation, boundary_conditions) {
        this.simulation = simulation;
        this.boundary_conditions = boundary_conditions;
    }

    run() {
        let change = 0.1;
        while (true) {
            this.simulation.update_state(change);
            this.simulation.state = this.boundary_conditions.enforce_boundaries(this.simulation.state);
            if (this.simulation.is_stable()) {
                break;
            }
        }
    }
}

function main() {
    let simulation = new Simulation(0.0);
    let boundary_conditions = new BoundaryConditions(-1.0, 1.0);
    let controller = new Controller(simulation, boundary_conditions);
    controller.run();
}

main();