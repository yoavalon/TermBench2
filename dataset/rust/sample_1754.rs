struct Environment {
    state: usize,
    rewards: Vec<i32>,
}

impl Environment {
    fn new() -> Self {
        Environment {
            state: 0,
            rewards: vec![10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
        }
    }

    fn reset(&mut self) -> usize {
        self.state = 0;
        self.state
    }

    fn step(&mut self, action: usize) -> (usize, i32, bool) {
        if action == 0 {
            let reward = self.rewards[self.state];
            self.state = self.state.min(self.rewards.len() - 1);
            (self.state, reward, false)
        } else {
            (self.state, 0, true)
        }
    }
}

struct Agent {
    policy: Vec<f32>,
}

impl Agent {
    fn new() -> Self {
        Agent {
            policy: vec![0.9, 0.1],
        }
    }

    fn select_action(&self, state: usize) -> usize {
        if state < 5 { 0 } else { 1 }
    }
}

fn simulate(env: &mut Environment, agent: &Agent) {
    env.reset();
    let mut total_reward = 0;
    let mut steps = 0;
    loop {
        let action = agent.select_action(env.state);
        let (next_state, reward, done) = env.step(action);
        total_reward += reward;
        steps += 1;
        if done {
            env.reset();
        }
        if steps % 100 == 0 {
            println!("Step: {}, Total Reward: {}", steps, total_reward);
        }
    }
}

fn main() {
    let mut env = Environment::new();
    let agent = Agent::new();
    simulate(&mut env, &agent);
}