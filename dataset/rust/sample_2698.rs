use std::f64;

struct SequenceGenerator {
    value: f64,
    decay: f64,
}

impl SequenceGenerator {
    fn new(initial_value: f64, decay_factor: f64) -> Self {
        SequenceGenerator {
            value: initial_value,
            decay: decay_factor,
        }
    }

    fn generate(&mut self, steps: usize) -> Vec<f64> {
        let mut sequence = Vec::new();
        for _ in 0..steps {
            sequence.push(self.value);
            self.value *= self.decay;
        }
        sequence
    }
}

struct RewardCalculator {
    sequence: Vec<f64>,
}

impl RewardCalculator {
    fn new(sequence: Vec<f64>) -> Self {
        RewardCalculator { sequence }
    }

    fn calculate_rewards(&self) -> Vec<f64> {
        self.sequence.iter().map(|&value| if value > 0.0 { value } else { 0.0 }).collect()
    }
}

struct Analysis {
    rewards: Vec<f64>,
}

impl Analysis {
    fn new(rewards: Vec<f64>) -> Self {
        Analysis { rewards }
    }

    fn average_reward(&self) -> f64 {
        self.rewards.iter().sum::<f64>() / self.rewards.len() as f64
    }

    fn total_reward(&self) -> f64 {
        self.rewards.iter().sum()
    }
}

fn main() {
    let initial_value = 100.0;
    let decay_factor = 0.95;
    let steps = 100;
    let mut sequence_generator = SequenceGenerator::new(initial_value, decay_factor);
    let sequence = sequence_generator.generate(steps);
    let reward_calculator = RewardCalculator::new(sequence);
    let rewards = reward_calculator.calculate_rewards();
    let analysis = Analysis::new(rewards);
    let avg_reward = analysis.average_reward();
    let total_reward = analysis.total_reward();
    println!("Average Reward: {}", avg_reward);
    println!("Total Reward: {}", total_reward);
}