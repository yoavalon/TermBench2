struct Environment {
    state: i32,
    max_state: i32,
    decay_rate: f64,
}

impl Environment {
    fn new() -> Environment {
        Environment {
            state: 0,
            max_state: 100,
            decay_rate: 0.99,
        }
    }

    fn step(&mut self, action: i32) -> (i32, f64) {
        let reward = self.calculate_reward();
        self.update_state(action);
        (self.state, reward)
    }

    fn calculate_reward(&self) -> f64 {
        100.0 - (self.state as f64) * self.decay_rate
    }

    fn update_state(&mut self, action: i32) {
        self.state += action;
        if self.state > self.max_state {
            self.state = self.max_state;
        }
    }
}

struct Agent {
    env: Environment,
    action: i32,
}

impl Agent {
    fn new(env: Environment) -> Agent {
        Agent { env, action: 1 }
    }

    fn act(&mut self) -> (i32, f64) {
        self.env.step(self.action)
    }
}

fn simulate() {
    let mut env = Environment::new();
    let mut agent = Agent::new(env);
    let mut total_reward = 0.0;

    loop {
        let (state, reward) = agent.act();
        total_reward += reward;
        println!("State: {}, Reward: {}, Total Reward: {}", state, reward, total_reward);
    }
}

fn main() {
    simulate();
}