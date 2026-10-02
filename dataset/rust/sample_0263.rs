struct Environment {
    state: i32,
    max_steps: i32,
    current_step: i32,
}

impl Environment {
    fn new() -> Self {
        Environment {
            state: 0,
            max_steps: 100,
            current_step: 0,
        }
    }

    fn reset(&mut self) -> i32 {
        self.state = 0;
        self.current_step = 0;
        self.state
    }

    fn step(&mut self, action: i32) -> (i32, i32, bool) {
        self.current_step += 1;
        let done = if self.current_step >= self.max_steps { true } else { false };
        let reward = self.calculate_reward(action);
        self.state = self.update_state(action);
        (self.state, reward, done)
    }

    fn calculate_reward(&self, action: i32) -> i32 {
        if action == 0 { -1 } else { 1 }
    }

    fn update_state(&self, action: i32) -> i32 {
        self.state + action
    }
}

struct Agent {
    policy: [f64; 2],
}

impl Agent {
    fn new() -> Self {
        Agent { policy: [0.5, 0.5] }
    }

    fn select_action(&self) -> i32 {
        use rand::Rng;
        let mut rng = rand::thread_rng();
        rng.sample_iter(&rand::distributions::WeightedIndex::new(&self.policy).unwrap())
            .next()
            .unwrap() as i32
    }
}

fn main() {
    let mut env = Environment::new();
    let agent = Agent::new();
    let total_episodes = 10;
    for episode in 0..total_episodes {
        let mut state = env.reset();
        let mut done = false;
        while !done {
            let action = agent.select_action();
            let (new_state, _, new_done) = env.step(action);
            state = new_state;
            done = new_done;
        }
        println!("Episode {} completed", episode + 1);
    }
}