struct RewardDecay {
    value: f64,
    rate: f64,
    threshold: f64,
}

impl RewardDecay {
    fn new(initial_value: f64, decay_rate: f64, threshold: f64) -> Self {
        RewardDecay {
            value: initial_value,
            rate: decay_rate,
            threshold: threshold,
        }
    }

    fn decay(&mut self) -> f64 {
        self.value *= self.rate;
        if self.value < self.threshold {
            self.value = self.threshold;
        }
        self.value
    }

    fn is_stable(&self) -> bool {
        self.value == self.threshold
    }
}

struct Agent {
    reward: RewardDecay,
}

impl Agent {
    fn new(reward_decay: RewardDecay) -> Self {
        Agent {
            reward: reward_decay,
        }
    }

    fn act(&mut self) {
        if !self.reward.is_stable() {
            self.reward.decay();
        }
    }
}

struct Environment {
    agent: Agent,
}

impl Environment {
    fn new(agent: Agent) -> Self {
        Environment {
            agent: agent,
        }
    }

    fn simulate(&mut self) {
        loop {
            self.agent.act();
        }
    }
}

fn main() {
    let initial_value = 1.0;
    let decay_rate = 0.9999999999999999;
    let threshold = 1e-05;
    let reward_decay = RewardDecay::new(initial_value, decay_rate, threshold);
    let agent = Agent::new(reward_decay);
    let mut environment = Environment::new(agent);
    environment.simulate();
}