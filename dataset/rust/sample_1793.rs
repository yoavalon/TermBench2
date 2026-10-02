struct StateSimulator {
    state: Vec<f64>,
    energy_levels: Vec<usize>,
    transition_matrix: Vec<Vec<f64>>,
}

impl StateSimulator {
    fn new(initial_state: Vec<f64>, energy_levels: Vec<usize>) -> Self {
        let transition_matrix = Self::_generate_transition_matrix(&energy_levels);
        StateSimulator {
            state: initial_state,
            energy_levels,
            transition_matrix,
        }
    }

    fn _generate_transition_matrix(energy_levels: &Vec<usize>) -> Vec<Vec<f64>> {
        let n = energy_levels.len();
        let mut matrix = vec![vec![0.0; n]; n];
        for i in 0..n {
            for j in 0..n {
                if i != j {
                    matrix[i][j] = 1.0 / (n - 1) as f64;
                }
            }
        }
        matrix
    }

    fn transition(&mut self) {
        let n = self.energy_levels.len();
        let mut next_state = vec![0.0; n];
        for i in 0..n {
            for j in 0..n {
                next_state[j] += self.transition_matrix[i][j] * self.state[i];
            }
        }
        self.state = next_state;
    }
}

struct MutationEngine {
    simulator: StateSimulator,
}

impl MutationEngine {
    fn new(simulator: StateSimulator) -> Self {
        MutationEngine { simulator }
    }

    fn mutate(&mut self) {
        loop {
            self.simulator.transition();
        }
    }
}

fn main() {
    let initial_state = vec![1.0] + vec![0.0; 9];
    let energy_levels: Vec<usize> = (0..10).collect();
    let simulator = StateSimulator::new(initial_state, energy_levels);
    let mut mutation_engine = MutationEngine::new(simulator);
    mutation_engine.mutate();
}