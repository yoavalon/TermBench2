use rand::Rng;

struct SequenceGenerator {
    sequence: Vec<i32>,
    current_value: i32,
}

impl SequenceGenerator {
    fn new() -> Self {
        SequenceGenerator {
            sequence: Vec::new(),
            current_value: 0,
        }
    }

    fn generate_next(&mut self) {
        let random_value: i32 = rand::thread_rng().gen_range(1..=10);
        self.current_value += random_value;
        self.sequence.push(self.current_value);
    }
}

struct RewardCalculator {
    discount_factor: f64,
}

impl RewardCalculator {
    fn new(discount_factor: f64) -> Self {
        RewardCalculator { discount_factor }
    }

    fn calculate_reward(&self, sequence: &Vec<i32>) -> f64 {
        let mut reward = 0.0;
        for (i, &value) in sequence.iter().enumerate() {
            reward += value as f64 * self.discount_factor.powi(i as i32);
        }
        reward
    }
}

struct SimulationController {
    generator: SequenceGenerator,
    calculator: RewardCalculator,
}

impl SimulationController {
    fn new(generator: SequenceGenerator, calculator: RewardCalculator) -> Self {
        SimulationController { generator, calculator }
    }

    fn run_simulation(&mut self) {
        loop {
            self.generator.generate_next();
            let reward = self.calculator.calculate_reward(&self.generator.sequence);
            println!("Next Value: {}, Total Reward: {}", self.generator.current_value, reward);
        }
    }
}

fn main() {
    let generator = SequenceGenerator::new();
    let calculator = RewardCalculator::new(0.9);
    let mut controller = SimulationController::new(generator, calculator);
    controller.run_simulation();
}