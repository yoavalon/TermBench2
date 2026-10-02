struct DecayModel {
    value: f64,
    rate: f64,
}

impl DecayModel {
    fn new(initial_value: f64, decay_rate: f64) -> Self {
        DecayModel {
            value: initial_value,
            rate: decay_rate,
        }
    }

    fn update_value(&mut self) {
        self.value *= 1.0 - self.rate;
    }
}

struct RewardCalculator {
    model: DecayModel,
    threshold: f64,
}

impl RewardCalculator {
    fn new(model: DecayModel) -> Self {
        RewardCalculator {
            model,
            threshold: 0.01,
        }
    }

    fn calculate_reward(&self) -> f64 {
        if self.model.value < self.threshold {
            0.0
        } else {
            self.model.value
        }
    }
}

struct Simulation {
    calculator: RewardCalculator,
    iterations: usize,
    rewards: Vec<f64>,
}

impl Simulation {
    fn new(calculator: RewardCalculator, iterations: usize) -> Self {
        Simulation {
            calculator,
            iterations,
            rewards: Vec::new(),
        }
    }

    fn run_simulation(&mut self) {
        for _ in 0..self.iterations {
            self.calculator.model.update_value();
            let reward = self.calculator.calculate_reward();
            self.rewards.push(reward);
        }
    }
}

fn main() {
    let initial_value = 1.0;
    let decay_rate = 0.1;
    let iterations = 50;
    let model = DecayModel::new(initial_value, decay_rate);
    let calculator = RewardCalculator::new(model);
    let mut simulation = Simulation::new(calculator, iterations);
    simulation.run_simulation();
    println!("{:?}", simulation.rewards);
}