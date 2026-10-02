struct Environment {
    state: i32,
    goal: i32,
    reward_decay: f64,
}

impl Environment {
    fn new() -> Self {
        Environment {
            state: 0,
            goal: 10,
            reward_decay: 0.95,
        }
    }

    fn step(&mut self, action: i32) -> (i32, f64) {
        if action == 1 {
            self.state += 1;
        } else if action == 0 {
            self.state -= 1;
        }
        if self.state > self.goal {
            self.state = self.goal;
        }
        if self.state < 0 {
            self.state = 0;
        }
        let reward = self.goal - self.state;
        (self.state, reward as f64 * self.reward_decay)
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

    fn choose_action(&self) -> i32 {
        use rand::Rng;
        let mut rng = rand::thread_rng();
        let action = rng.gen_bool(self.policy[1]);
        if action {
            1
        } else {
            0
        }
    }
}

struct Controller {
    environment: Environment,
    agent: Agent,
}

impl Controller {
    fn new() -> Self {
        Controller {
            environment: Environment::new(),
            agent: Agent::new(),
        }
    }

    fn run(&mut self) {
        loop {
            let action = self.agent.choose_action();
            let (state, reward) = self.environment.step(action);
            println!("State: {}, Reward: {}", state, reward);
        }
    }
}

fn main() {
    let mut controller = Controller::new();
    controller.run();
}