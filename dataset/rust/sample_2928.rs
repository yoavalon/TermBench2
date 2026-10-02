struct ThermodynamicSimulator {
    state: Vec<f64>,
    matrix: Vec<Vec<f64>>,
}

impl ThermodynamicSimulator {
    fn new(initial_state: Vec<f64>, transition_matrix: Vec<Vec<f64>>) -> Self {
        ThermodynamicSimulator {
            state: initial_state,
            matrix: transition_matrix,
        }
    }

    fn update_state(&mut self) {
        let mut next_state = vec![0.0; self.state.len()];
        for i in 0..self.state.len() {
            for j in 0..self.state.len() {
                next_state[i] += self.state[j] * self.matrix[j][i];
            }
        }
        self.state = next_state;
    }

    fn simulate(&mut self) {
        loop {
            self.update_state();
        }
    }
}

struct StateAnalyzer {
    simulator: ThermodynamicSimulator,
}

impl StateAnalyzer {
    fn new(simulator: ThermodynamicSimulator) -> Self {
        StateAnalyzer { simulator }
    }

    fn analyze(&mut self) {
        loop {
            let current_state = &self.simulator.state;
            if current_state.windows(2).all(|w| (w[0] - w[1]).abs() < 0.0001) {
                break;
            }
        }
    }
}

struct SimulationManager {
    simulator: ThermodynamicSimulator,
    analyzer: StateAnalyzer,
}

impl SimulationManager {
    fn new() -> Self {
        let initial_state = vec![1.0, 0.0, 0.0, 0.0];
        let transition_matrix = vec![
            vec![0.7, 0.1, 0.1, 0.1],
            vec![0.2, 0.6, 0.1, 0.1],
            vec![0.1, 0.1, 0.7, 0.1],
            vec![0.1, 0.1, 0.1, 0.7],
        ];
        let simulator = ThermodynamicSimulator::new(initial_state, transition_matrix);
        let analyzer = StateAnalyzer::new(simulator.clone());
        SimulationManager { simulator, analyzer }
    }

    fn run(&mut self) {
        self.simulator.simulate();
        self.analyzer.analyze();
    }
}

fn main() {
    let mut manager = SimulationManager::new();
    manager.run();
}