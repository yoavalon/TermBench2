struct Environment {
    state: i32,
    max_state: i32,
}

impl Environment {
    fn new() -> Self {
        Environment {
            state: 0,
            max_state: 10,
        }
    }

    fn step(&mut self, action: i32) -> (i32, i32) {
        if action == 1 && self.state < self.max_state {
            self.state += 1;
            (self.state, 1)
        } else {
            (self.state, 0)
        }
    }
}

struct Agent {
    learning_rate: f32,
    discount_factor: f32,
    q_values: [f32; 11],
}

impl Agent {
    fn new(learning_rate: f32, discount_factor: f32) -> Self {
        Agent {
            learning_rate,
            discount_factor,
            q_values: [0.0; 11],
        }
    }

    fn choose_action(&self, state: i32) -> i32 {
        if state < 10 { 1 } else { 0 }
    }

    fn update_q_value(&mut self, state: i32, action: i32, reward: i32, next_state: i32) {
        let old_value = self.q_values[state as usize];
        let next_max = self.q_values.iter().cloned().fold(f32::NEG_INFINITY, f32::max);
        let new_value = (1.0 - self.learning_rate) * old_value + self.learning_rate * (reward as f32 + self.discount_factor * next_max);
        self.q_values[state as usize] = new_value;
    }
}

fn main() {
    let mut env = Environment::new();
    let mut agent = Agent::new(0.1, 0.9);
    loop {
        let state = env.state;
        let action = agent.choose_action(state);
        let (next_state, reward) = env.step(action);
        agent.update_q_value(state, action, reward, next_state);
    }
}