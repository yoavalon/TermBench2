use rand::Rng;

struct Environment {
    state: i32,
    goal: i32,
}

impl Environment {
    fn new() -> Self {
        Environment { state: 0, goal: 5 }
    }

    fn step(&mut self, action: i32) -> (i32, f64, bool) {
        if action == 1 {
            self.state += 1;
        }
        if self.state >= self.goal {
            (self.state, 1.0, true)
        } else {
            (self.state, -0.1, false)
        }
    }
}

struct Agent {
    epsilon: f64,
    alpha: f64,
    gamma: f64,
    q_table: std::collections::HashMap<i32, [f64; 2]>,
}

impl Agent {
    fn new(epsilon: f64, alpha: f64, gamma: f64) -> Self {
        Agent {
            epsilon,
            alpha,
            gamma,
            q_table: std::collections::HashMap::new(),
        }
    }

    fn select_action(&self, state: i32) -> i32 {
        let mut rng = rand::thread_rng();
        if rng.gen::<f64>() < self.epsilon {
            rng.gen_range(0..2)
        } else {
            *self.q_table.get(&state).unwrap_or(&[0.0, 0.0]).iter().enumerate().max_by(|a, b| a.1.partial_cmp(b.1).unwrap()).unwrap().0 as i32
        }
    }

    fn update_q_table(&mut self, state: i32, action: i32, reward: f64, next_state: i32, done: bool) {
        if !self.q_table.contains_key(&state) {
            self.q_table.insert(state, [0.0, 0.0]);
        }
        if !self.q_table.contains_key(&next_state) {
            self.q_table.insert(next_state, [0.0, 0.0]);
        }
        let old_value = self.q_table[&state][action as usize];
        let next_max = self.q_table[&next_state].iter().cloned().fold(f64::NEG_INFINITY, f64::max);
        let new_value = old_value + self.alpha * (reward + self.gamma * next_max - old_value);
        self.q_table.get_mut(&state).unwrap()[action as usize] = new_value;
    }
}

fn main() {
    let mut env = Environment::new();
    let mut agent = Agent::new(epsilon: 0.1, alpha: 0.5, gamma: 0.9);
    let episodes = 1000;
    for _ in 0..episodes {
        let mut state = env.state;
        let mut done = false;
        while !done {
            let action = agent.select_action(state);
            let (next_state, reward, done) = env.step(action);
            agent.update_q_table(state, action, reward, next_state, done);
            state = next_state;
        }
    }
}