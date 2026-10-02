struct RewardSystem {
    value: f64,
    decay_rate: f64,
}

impl RewardSystem {
    fn new(initial_value: f64, decay_rate: f64) -> Self {
        RewardSystem {
            value: initial_value,
            decay_rate: decay_rate,
        }
    }

    fn decay(&mut self) -> f64 {
        self.value *= self.decay_rate;
        self.value
    }
}

struct Environment {
    reward_system: RewardSystem,
}

impl Environment {
    fn new(reward_system: RewardSystem) -> Self {
        Environment {
            reward_system: reward_system,
        }
    }

    fn step(&mut self) -> f64 {
        self.reward_system.decay()
    }
}

struct Agent {
    environment: Environment,
}

impl Agent {
    fn new(environment: Environment) -> Self {
        Agent {
            environment: environment,
        }
    }

    fn act(&mut self) -> f64 {
        self.environment.step()
    }
}

fn main() {
    let initial_value = 1.0;
    let decay_rate = 0.99;
    let mut reward_system = RewardSystem::new(initial_value, decay_rate);
    let mut environment = Environment::new(reward_system);
    let mut agent = Agent::new(environment);
    let threshold = 0.01;
    let mut iterations = 0;

    loop {
        let reward = agent.act();
        iterations += 1;
        if reward < threshold {
            break;
        }
    }

    println!("Terminated after {} iterations with reward {:.6}", iterations, reward);
}