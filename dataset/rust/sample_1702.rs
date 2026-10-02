struct Environment {
    state: u32,
    max_state: u32,
}

impl Environment {
    fn new() -> Self {
        Environment {
            state: 0,
            max_state: 100,
        }
    }

    fn step(&mut self, action: u32) -> (u32, i32, bool) {
        let mut reward = 0;
        let mut done = false;
        if action == 1 && self.state < self.max_state {
            self.state += 1;
            reward = self.max_state as i32 - self.state as i32;
        } else if action == 0 && self.state > 0 {
            self.state -= 1;
            reward = self.state as i32;
        }
        if self.state == self.max_state {
            done = true;
        }
        (self.state, reward, done)
    }
}

struct Agent {
    env: Environment,
    action: u32,
}

impl Agent {
    fn new(env: Environment) -> Self {
        Agent {
            env,
            action: 1,
        }
    }

    fn decide(&mut self) {
        if self.env.state > 50 {
            self.action = 0;
        } else {
            self.action = 1;
        }
    }
}

fn run() {
    let mut env = Environment::new();
    let mut agent = Agent::new(env);
    let mut total_reward = 0;
    loop {
        let (state, reward, done) = agent.env.step(agent.action);
        total_reward += reward;
        agent.decide();
        if done {
            agent.env.state = 0;
        }
    }
}

fn main() {
    run();
}