use std::vec::Vec;

struct RewardDecay {
    current_reward: f64,
    decay_rate: f64,
}

impl RewardDecay {
    fn new(initial_reward: f64, decay_rate: f64) -> Self {
        RewardDecay {
            current_reward: initial_reward,
            decay_rate: decay_rate,
        }
    }

    fn update_reward(&mut self) {
        self.current_reward *= 1.0 - self.decay_rate;
    }

    fn get_current_reward(&self) -> f64 {
        self.current_reward
    }
}

struct Agent {
    reward_decay: RewardDecay,
    action_count: usize,
}

impl Agent {
    fn new(reward_decay: RewardDecay) -> Self {
        Agent {
            reward_decay: reward_decay,
            action_count: 0,
        }
    }

    fn take_action(&mut self) {
        self.action_count += 1;
        self.reward_decay.update_reward();
    }

    fn get_reward(&self) -> f64 {
        self.reward_decay.get_current_reward()
    }
}

fn simulate_environment(agent: &mut Agent, max_actions: usize) -> Vec<f64> {
    let mut rewards = Vec::new();
    for _ in 0..max_actions {
        agent.take_action();
        rewards.push(agent.get_reward());
    }
    rewards
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.01;
    let max_actions = 1000;
    let mut reward_decay = RewardDecay::new(initial_reward, decay_rate);
    let mut agent = Agent::new(reward_decay);
    let rewards = simulate_environment(&mut agent, max_actions);
    println!("{:?}", rewards);
}