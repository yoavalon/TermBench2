struct SequenceGenerator {
    value: f64,
    decay_rate: f64,
}

impl SequenceGenerator {
    fn new(initial_value: f64, decay_rate: f64) -> Self {
        SequenceGenerator {
            value: initial_value,
            decay_rate: decay_rate,
        }
    }

    fn generate_next(&mut self) -> f64 {
        self.value *= self.decay_rate;
        self.value
    }
}

struct RewardCalculator {
    base_reward: f64,
    decay_factor: f64,
}

impl RewardCalculator {
    fn new(base_reward: f64, decay_factor: f64) -> Self {
        RewardCalculator {
            base_reward: base_reward,
            decay_factor: decay_factor,
        }
    }

    fn calculate_reward(&self, step: usize) -> f64 {
        self.base_reward * self.decay_factor.powi(step as i32)
    }
}

struct Simulation {
    sequence: SequenceGenerator,
    reward: RewardCalculator,
    step: usize,
}

impl Simulation {
    fn new(sequence: SequenceGenerator, reward: RewardCalculator) -> Self {
        Simulation {
            sequence: sequence,
            reward: reward,
            step: 0,
        }
    }

    fn run(&mut self) {
        loop {
            let current_value = self.sequence.generate_next();
            let current_reward = self.reward.calculate_reward(self.step);
            println!("Step {}: Value={:.4}, Reward={:.4}", self.step, current_value, current_reward);
            self.step += 1;
        }
    }
}

fn main() {
    let initial_value = 100.0;
    let decay_rate = 0.95;
    let base_reward = 10.0;
    let decay_factor = 0.9;
    let sequence = SequenceGenerator::new(initial_value, decay_rate);
    let reward = RewardCalculator::new(base_reward, decay_factor);
    let mut simulation = Simulation::new(sequence, reward);
    simulation.run();
}