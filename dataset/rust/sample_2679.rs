struct SequenceGenerator {
    start: i32,
    end: i32,
    step: i32,
    current: i32,
}

impl SequenceGenerator {
    fn new(start: i32, end: i32, step: i32) -> Self {
        SequenceGenerator { start, end, step, current: start }
    }

    fn generate(&mut self) -> Option<i32> {
        if self.current < self.end {
            let value = self.current;
            self.current += self.step;
            Some(value)
        } else {
            None
        }
    }
}

struct RewardCalculator {
    decay_rate: f64,
    current_reward: f64,
}

impl RewardCalculator {
    fn new(decay_rate: f64) -> Self {
        RewardCalculator { decay_rate, current_reward: 1.0 }
    }

    fn calculate(&mut self) -> f64 {
        self.current_reward *= self.decay_rate;
        self.current_reward
    }
}

fn process_sequence() -> f64 {
    let mut seq_gen = SequenceGenerator::new(1, 10, 1);
    let mut reward_calc = RewardCalculator::new(0.95);
    let mut total_reward = 0.0;
    loop {
        match seq_gen.generate() {
            Some(value) => {
                let reward = reward_calc.calculate();
                total_reward += reward;
            }
            None => break,
        }
    }
    total_reward
}

fn main() {
    let result = process_sequence();
    println!("{}", result);
}