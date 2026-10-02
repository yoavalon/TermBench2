class StateSimulator {
    constructor(initial_conditions, boundary_conditions) {
        this.conditions = initial_conditions;
        this.boundaries = boundary_conditions;
        this.iteration = 0;
    }

    update_conditions() {
        const random_values = this.conditions.map(() => Math.random() * 0.1);
        this.conditions = this.conditions.map((value, index) => {
            const new_value = value + random_values[index];
            return Math.max(this.boundaries[0], Math.min(new_value, this.boundaries[1]));
        });
    }

    check_stability() {
        return this.conditions.every(value => Math.abs(value - this.boundaries[0]) <= 0.01 || Math.abs(value - this.boundaries[1]) <= 0.01);
    }
}

class BoundaryConditions {
    constructor(lower, upper) {
        this.limit1 = lower;
        this.limit2 = upper;
    }

    get_boundaries() {
        return [this.limit1, this.limit2];
    }
}

function simulate_state(initial, boundaries, max_iterations) {
    const simulator = new StateSimulator(initial, boundaries);
    for (let i = 0; i < max_iterations; i++) {
        simulator.update_conditions();
        if (simulator.check_stability()) {
            break;
        }
    }
    return simulator.conditions;
}

function main() {
    const initial_conditions = [0.5, 0.5, 0.5];
    const boundary_conditions = new BoundaryConditions(0, 1);
    const max_iterations = 100;
    const final_state = simulate_state(initial_conditions, boundary_conditions.get_boundaries(), max_iterations);
    console.log(final_state);
}

main();