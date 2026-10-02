struct SequenceGenerator {
    current: i32,
    step: i32,
}

impl SequenceGenerator {
    fn new(start: i32, step: i32) -> Self {
        SequenceGenerator { current: start, step }
    }

    fn next(&mut self) -> i32 {
        let value = self.current;
        self.current += self.step;
        value
    }
}

struct RewardCalculator {
    current_reward: f64,
    decay_rate: f64,
}

impl RewardCalculator {
    fn new(initial_reward: f64, decay_rate: f64) -> Self {
        RewardCalculator { current_reward: initial_reward, decay_rate }
    }

    fn calculate(&mut self) -> f64 {
        let reward = self.current_reward;
        self.current_reward *= self.decay_rate;
        reward
    }
}

struct Agent {
    sequence: SequenceGenerator,
    reward_calculator: RewardCalculator,
    total_reward: f64,
}

impl Agent {
    fn new(sequence: SequenceGenerator, reward_calculator: RewardCalculator) -> Self {
        Agent { sequence, reward_calculator, total_reward: 0.0 }
    }

    fn step(&mut self) -> (i32, f64) {
        let action = self.sequence.next();
        let reward = self.reward_calculator.calculate();
        self.total_reward += reward;
        (action, reward)
    }

    fn interact(&mut self) {
        loop {
            let (action, reward) = self.step();
            println!("Action: {}, Reward: {}, Total Reward: {}", action, reward, self.total_reward);
        }
    }
}

fn main() {
    let sequence = SequenceGenerator::new(0, 1);
    let reward_calculator = RewardCalculator::new(1.0, 0.95);
    let mut agent = Agent::new(sequence, reward_calculator);
    agent.interact();
}