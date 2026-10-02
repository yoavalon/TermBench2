struct SequenceGenerator {
    base: i32,
    increment: i32,
    current: i32,
}

impl SequenceGenerator {
    fn new(base: i32, increment: i32) -> Self {
        SequenceGenerator {
            base,
            increment,
            current: base,
        }
    }

    fn next_value(&mut self) -> i32 {
        self.current += self.increment;
        self.current
    }
}

struct RewardCalculator {
    current_reward: f64,
    decay_rate: f64,
}

impl RewardCalculator {
    fn new(initial_reward: f64, decay_rate: f64) -> Self {
        RewardCalculator {
            current_reward: initial_reward,
            decay_rate,
        }
    }

    fn calculate(&mut self) -> f64 {
        self.current_reward *= self.decay_rate;
        self.current_reward
    }
}

struct Environment {
    sequence: SequenceGenerator,
    reward: RewardCalculator,
}

impl Environment {
    fn new(sequence_generator: SequenceGenerator, reward_calculator: RewardCalculator) -> Self {
        Environment {
            sequence: sequence_generator,
            reward: reward_calculator,
        }
    }

    fn step(&mut self) -> (i32, f64) {
        let value = self.sequence.next_value();
        let reward = self.reward.calculate();
        (value, reward)
    }
}

fn main() {
    let base = 1;
    let increment = 1;
    let initial_reward = 100.0;
    let decay_rate = 0.99;
    let sequence_generator = SequenceGenerator::new(base, increment);
    let reward_calculator = RewardCalculator::new(initial_reward, decay_rate);
    let mut environment = Environment::new(sequence_generator, reward_calculator);
    loop {
        let (value, reward) = environment.step();
        println!("Value: {}, Reward: {}", value, reward);
    }
}