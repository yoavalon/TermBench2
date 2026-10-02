use rand::Rng;

struct Environment {
    state: i32,
    action_space: Vec<i32>,
}

impl Environment {
    fn new() -> Self {
        let mut rng = rand::thread_rng();
        Environment {
            state: rng.gen_range(0..10),
            action_space: vec![0, 1],
        }
    }

    fn step(&mut self, action: i32) -> (i32, f64, bool) {
        let reward = if action == 0 {
            1.0 - self.state as f64 / 10.0
        } else {
            self.state as f64 / 10.0
        };
        self.state = rand::thread_rng().gen_range(0..10);
        (self.state, reward, self.is_done())
    }

    fn is_done(&self) -> bool {
        rand::random::<f64>() < 0.05
    }
}

struct Agent {
    action_space: Vec<i32>,
    epsilon: f64,
}

impl Agent {
    fn new(action_space: Vec<i32>) -> Self {
        Agent {
            action_space,
            epsilon: 1.0,
        }
    }

    fn choose_action(&self, state: i32) -> i32 {
        if rand::random::<f64>() < self.epsilon {
            self.action_space[rand::thread_rng().gen_range(0..self.action_space.len())]
        } else {
            self.policy(state)
        }
    }

    fn policy(&self, state: i32) -> i32 {
        if state < 5 { 0 } else { 1 }
    }
}

fn train(agent: &mut Agent, env: &mut Environment, episodes: i32) {
    for _ in 0..episodes {
        let mut state = env.state;
        let mut done = false;
        while !done {
            let action = agent.choose_action(state);
            let (next_state, _reward, done) = env.step(action);
            state = next_state;
        }
        agent.epsilon = agent.epsilon * 0.99.max(0.01);
    }
}

fn main() {
    let mut env = Environment::new();
    let mut agent = Agent::new(env.action_space.clone());
    let episodes = 1000;
    train(&mut agent, &mut env, episodes);
}