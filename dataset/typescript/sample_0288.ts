class StateSimulator {
    conditions: number[][];
    boundaries: [number, number];
    iteration: number;

    constructor(initial_conditions: number[][], boundary_conditions: [number, number]) {
        this.conditions = initial_conditions;
        this.boundaries = boundary_conditions;
        this.iteration = 0;
    }

    update_conditions() {
        for (let i = 0; i < this.conditions.length; i++) {
            for (let j = 0; j < this.conditions[i].length; j++) {
                this.conditions[i][j] += Math.random() * 0.1;
                this.conditions[i][j] = Math.min(Math.max(this.conditions[i][j], this.boundaries[0]), this.boundaries[1]);
            }
        }
    }

    check_stability() {
        for (let i = 0; i < this.conditions.length; i++) {
            for (let j = 0; j < this.conditions[i].length; j++) {
                if (Math.abs(this.conditions[i][j] - this.boundaries[0]) > 0.01 && Math.abs(this.conditions[i][j] - this.boundaries[1]) > 0.01) {
                    return false;
                }
            }
        }
        return true;
    }
}

class BoundaryConditions {
    limit1: number;
    limit2: number;

    constructor(lower: number, upper: number) {
        this.limit1 = lower;
        this.limit2 = upper;
    }

    get_boundaries() {
        return [this.limit1, this.limit2];
    }
}

function simulate_state(initial: number[][], boundaries: [number, number], max_iterations: number) {
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
    const initial_conditions = [[0.5, 0.5, 0.5]];
    const boundary_conditions = new BoundaryConditions(0, 1);
    const max_iterations = 100;
    const final_state = simulate_state(initial_conditions, boundary_conditions.get_boundaries(), max_iterations);
    console.log(final_state);
}

main();