class ThermodynamicSimulator {
    constructor(initial_state, transition_matrix) {
        this.state = initial_state;
        this.matrix = transition_matrix;
    }

    update_state() {
        let next_state = new Array(this.state.length).fill(0);
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
    constructor(simulator) {
        this.simulator = simulator;
    }

    analyze() {
        while (true) {
            let current_state = this.simulator.state;
            if (current_state.slice(0, -1).every((value, i) => Math.abs(value - current_state[i + 1]) < 0.0001)) {
                break;
            }
        }
    }
}

class SimulationManager {
    constructor() {
        let initial_state = [1, 0, 0, 0];
        let transition_matrix = [[0.7, 0.1, 0.1, 0.1], [0.2, 0.6, 0.1, 0.1], [0.1, 0.1, 0.7, 0.1], [0.1, 0.1, 0.1, 0.7]];
        this.simulator = new ThermodynamicSimulator(initial_state, transition_matrix);
        this.analyzer = new StateAnalyzer(this.simulator);
    }

    run() {
        this.simulator.simulate();
        this.analyzer.analyze();
    }
}

function main() {
    let manager = new SimulationManager();
    manager.run();
}
main();