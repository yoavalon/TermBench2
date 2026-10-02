struct Environment {
    state: i32,
    reward: f64,
    decay_rate: f64,
}

impl Environment {
    fn new() -> Environment {
        Environment {
            state: 0,
            reward: 1.0,
            decay_rate: 0.99,
        }
    }

    fn step(&mut self, action: i32) -> (i32, f64) {
        if action == 1 {
            self.state += 1;
            self.reward *= self.decay_rate;
        } else {
            self.state = 0;
            self.reward = 1.0;
        }
        (self.state, self.reward)
    }
}

struct Agent {
    action: i32,
}

impl Agent {
    fn new() -> Agent {
        Agent { action: 1 }
    }

    fn decide(&self) -> i32 {
        self.action
    }
}

struct Simulation {
    env: Environment,
    agent: Agent,
}

impl Simulation {
    fn new(env: Environment, agent: Agent) -> Simulation {
        Simulation { env, agent }
    }

    fn run(&mut self) {
        loop {
            let action = self.agent.decide();
            let (state, reward) = self.env.step(action);
            println!("State: {}, Reward: {:.4}", state, reward);
        }
    }
}

fn main() {
    let env = Environment::new();
    let agent = Agent::new();
    let mut sim = Simulation::new(env, agent);
    sim.run();
}