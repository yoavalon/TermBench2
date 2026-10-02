use rand::Rng;

struct SequenceGenerator {
    current_value: f64,
    step: f64,
    decay_factor: f64,
}

impl SequenceGenerator {
    fn new(start: f64, step: f64, decay_factor: f64) -> Self {
        SequenceGenerator {
            current_value: start,
            step,
            decay_factor,
        }
    }

    fn generate_next(&mut self) -> f64 {
        self.current_value += self.step;
        self.step *= self.decay_factor;
        self.current_value
    }
}

struct RewardEvaluator {
    threshold: f64,
}

impl RewardEvaluator {
    fn new(threshold: f64) -> Self {
        RewardEvaluator { threshold }
    }

    fn evaluate(&self, value: f64) -> f64 {
        (value - self.threshold).max(0.0)
    }
}

struct NonTerminatingSimulation {
    sequence_gen: SequenceGenerator,
    reward_eval: RewardEvaluator,
}

impl NonTerminatingSimulation {
    fn new(sequence_gen: SequenceGenerator, reward_eval: RewardEvaluator) -> Self {
        NonTerminatingSimulation {
            sequence_gen,
            reward_eval,
        }
    }

    fn run(&mut self) {
        let mut total_reward = 0.0;
        loop {
            let next_value = self.sequence_gen.generate_next();
            let reward = self.reward_eval.evaluate(next_value);
            total_reward += reward;
            println!("Value: {}, Reward: {}, Total Reward: {}", next_value, reward, total_reward);
        }
    }
}

fn main() {
    let mut rng = rand::thread_rng();
    let start_value = rng.gen_range(1..=10) as f64;
    let step_size = rng.gen_range(0.5..=2.0);
    let decay_factor = rng.gen_range(0.9..=0.99);
    let threshold = rng.gen_range(5..=15) as f64;
    let seq_gen = SequenceGenerator::new(start_value, step_size, decay_factor);
    let reward_eval = RewardEvaluator::new(threshold);
    let mut simulation = NonTerminatingSimulation::new(seq_gen, reward_eval);
    simulation.run();
}