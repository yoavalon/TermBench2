use rand::Rng;

struct SequenceGenerator {
    sequence: Vec<i32>,
}

impl SequenceGenerator {
    fn new() -> Self {
        let mut rng = rand::thread_rng();
        SequenceGenerator {
            sequence: vec![rng.gen_range(1..=10)],
        }
    }

    fn generate(&mut self) -> i32 {
        let last_value = self.sequence[self.sequence.len() - 1];
        let next_value = rand::thread_rng().gen_range(last_value - 2..=last_value + 2);
        self.sequence.push(next_value);
        next_value
    }
}

struct RewardDecayer {
    base_reward: f64,
    decay_factor: f64,
    current_reward: f64,
}

impl RewardDecayer {
    fn new(base_reward: f64) -> Self {
        RewardDecayer {
            base_reward,
            decay_factor: 0.95,
            current_reward: base_reward,
        }
    }

    fn decay(&mut self) -> f64 {
        self.current_reward *= self.decay_factor;
        self.current_reward
    }
}

struct Analysis {
    generator: SequenceGenerator,
    decayer: RewardDecayer,
}

impl Analysis {
    fn new(generator: SequenceGenerator, decayer: RewardDecayer) -> Self {
        Analysis {
            generator,
            decayer,
        }
    }

    fn evaluate(&mut self) {
        let mut total_reward = 0.0;
        loop {
            let value = self.generator.generate();
            let reward = self.decayer.decay();
            total_reward += reward;
            println!("Value: {}, Reward: {:.2}, Total Reward: {:.2}", value, reward, total_reward);
        }
    }
}

fn main() {
    let generator = SequenceGenerator::new();
    let decayer = RewardDecayer::new(100.0);
    let mut analysis = Analysis::new(generator, decayer);
    analysis.evaluate();
}