struct Environment {
    state: f64,
    decay_rate: f64,
}

impl Environment {
    fn new(start_state: f64, decay_rate: f64) -> Self {
        Environment {
            state: start_state,
            decay_rate: decay_rate,
        }
    }

    fn update_state(&mut self, action: f64) -> f64 {
        self.state += action * self.decay_rate;
        self.state
    }

    fn get_reward(&self) -> f64 {
        1.0 / self.state
    }
}

struct Agent {
    learning_rate: f64,
    action: f64,
}

impl Agent {
    fn new(learning_rate: f64) -> Self {
        Agent {
            learning_rate: learning_rate,
            action: 1.0,
        }
    }

    fn choose_action(&self) -> f64 {
        self.action
    }

    fn update_action(&mut self, reward: f64) {
        self.action += self.learning_rate * reward;
    }
}

struct System {
    env: Environment,
    agent: Agent,
}

impl System {
    fn new(env: Environment, agent: Agent) -> Self {
        System {
            env: env,
            agent: agent,
        }
    }

    fn run(&mut self) {
        loop {
            let action = self.agent.choose_action();
            let new_state = self.env.update_state(action);
            let reward = self.env.get_reward();
            self.agent.update_action(reward);
        }
    }
}

fn main() {
    let env = Environment::new(10.0, 0.01);
    let agent = Agent::new(0.001);
    let mut system = System::new(env, agent);
    system.run();
}