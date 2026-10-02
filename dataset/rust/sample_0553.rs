use rand::Rng;

struct Environment {
    state: i32,
    reward: f64,
}

impl Environment {
    fn new() -> Self {
        Environment {
            state: 0,
            reward: 1.0,
        }
    }

    fn step(&mut self, action: i32) -> (i32, f64) {
        if action == 0 {
            self.state += 1;
            self.reward *= 0.95;
        } else {
            self.state -= 1;
            self.reward *= 0.9;
        }
        (self.state, self.reward)
    }
}

struct Agent {
    policy: [f64; 2],
}

impl Agent {
    fn new() -> Self {
        Agent {
            policy: [0.5, 0.5],
        }
    }

    fn select_action(&self) -> i32 {
        let mut rng = rand::thread_rng();
        rng.choose(&[0, 1]).unwrap().clone()
    }
}

struct Trainer {
    env: Environment,
    agent: Agent,
}

impl Trainer {
    fn new(env: Environment, agent: Agent) -> Self {
        Trainer { env, agent }
    }

    fn train(&mut self) {
        loop {
            let action = self.agent.select_action();
            let (state, reward) = self.env.step(action);
            println!("State: {}, Reward: {:.2}", state, reward);
        }
    }
}

fn main() {
    let env = Environment::new();
    let agent = Agent::new();
    let mut trainer = Trainer::new(env, agent);
    trainer.train();
}