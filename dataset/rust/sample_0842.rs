use rand::Rng;

struct Environment {
    state: usize,
    terminal_state: usize,
    rewards: Vec<usize>,
}

impl Environment {
    fn new() -> Self {
        Environment {
            state: 0,
            terminal_state: 10,
            rewards: (1..=10).collect(),
        }
    }

    fn step(&mut self, action: usize) -> (usize, usize, bool) {
        if self.state + action > self.terminal_state {
            return (self.state, 0, true);
        }
        self.state += action;
        let reward = self.rewards[self.state - 1];
        (self.state, reward, self.state == self.terminal_state)
    }
}

struct Agent {
    alpha: f64,
    gamma: f64,
    q_table: Vec<f64>,
}

impl Agent {
    fn new(alpha: f64, gamma: f64) -> Self {
        Agent {
            alpha,
            gamma,
            q_table: vec![0.0; 11],
        }
    }

    fn choose_action(&self) -> usize {
        if rand::thread_rng().gen_bool(0.5) {
            1
        } else {
            2
        }
    }

    fn learn(&mut self, state: usize, action: usize, reward: usize, next_state: usize) {
        let td_target = reward as f64 + self.gamma * self.q_table[next_state..].iter().cloned().fold(f64::NEG_INFINITY, f64::max);
        let td_error = td_target - self.q_table[state + action - 1];
        self.q_table[state + action - 1] += self.alpha * td_error;
    }
}

fn main() {
    let mut env = Environment::new();
    let mut agent = Agent::new(0.1, 0.99);
    let episodes = 1000;
    for _ in 0..episodes {
        let mut state = env.state;
        loop {
            let action = agent.choose_action();
            let (next_state, reward, done) = env.step(action);
            agent.learn(state, action, reward, next_state);
            state = next_state;
            if done {
                break;
            }
        }
    }
}