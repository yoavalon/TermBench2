struct SequenceGenerator {
    start: i32,
    end: i32,
    step: i32,
    current: i32,
}

impl SequenceGenerator {
    fn new(start: i32, end: i32, step: i32) -> Self {
        SequenceGenerator {
            start,
            end,
            step,
            current: start,
        }
    }

    fn generate(&mut self) -> Vec<i32> {
        let mut result = Vec::new();
        while self.current < self.end {
            result.push(self.current);
            self.current += self.step;
        }
        result
    }
}

struct RewardCalculator {
    initial_reward: f64,
    decay_rate: f64,
    current_reward: f64,
}

impl RewardCalculator {
    fn new(initial_reward: f64, decay_rate: f64) -> Self {
        RewardCalculator {
            initial_reward,
            decay_rate,
            current_reward: initial_reward,
        }
    }

    fn calculate(&mut self, step: i32) -> f64 {
        self.current_reward = self.initial_reward * self.decay_rate.powi(step);
        self.current_reward
    }
}

fn simulate(sequence_generator: &mut SequenceGenerator, reward_calculator: &mut RewardCalculator, max_steps: i32) -> f64 {
    let mut steps = 0;
    let mut total_reward = 0.0;
    for value in sequence_generator.generate() {
        if steps >= max_steps {
            break;
        }
        let reward = reward_calculator.calculate(steps);
        total_reward += reward;
        steps += 1;
    }
    total_reward
}

fn main() {
    let mut seq_gen = SequenceGenerator::new(0, 10, 1);
    let mut reward_calc = RewardCalculator::new(1.0, 0.9);
    let max_steps = 5;
    let result = simulate(&mut seq_gen, &mut reward_calc, max_steps);
    println!("{}", result);
}