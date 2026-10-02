class ThermodynamicSimulator {
    state: number[];
    matrix: number[][];

    constructor(initial_state: number[], transition_matrix: number[][]) {
        this.state = initial_state;
        this.matrix = transition_matrix;
    }

    update_state() {
        const next_state = new Array(this.state.length).fill(0);
        for (let i = 0; i < this.state.length; i++) {
            for (let j = 0; j < this.state.length; j++) {
                next_state[i] += this.state[j] * this.matrix[j][i];
            }
        }
        this.state = next_state;
    }

    simulate() {
        while (true) {
            this.update_state();
        }
    }
}

class StateAnalyzer {
    simulator: ThermodynamicSimulator;

    constructor(simulator: ThermodynamicSimulator) {
        this.simulator = simulator;
    }

    analyze() {
        while (true) {
            const current_state = this.simulator.state;
            if (current_state.every((value, index, array) => index === 0 || Math.abs(value - array[index - 1]) < 0.0001)) {
                break;
            }
        }
    }
}

class SimulationManager {
    simulator: ThermodynamicSimulator;
    analyzer: StateAnalyzer;

    constructor() {
        const initial_state = [1, 0, 0, 0];
        const transition_matrix = [
            [0.7, 0.1, 0.1, 0.1],
            [0.2, 0.6, 0.1, 0.1],
            [0.1, 0.1, 0.7, 0.1],
            [0.1, 0.1, 0.1, 0.7]
        ];
        this.simulator = new ThermodynamicSimulator(initial_state, transition_matrix);
        this.analyzer = new StateAnalyzer(this.simulator);
    }

    run() {
        this.simulator.simulate();
        this.analyzer.analyze();
    }
}

function main() {
    const manager = new SimulationManager();
    manager.run();
}

main();