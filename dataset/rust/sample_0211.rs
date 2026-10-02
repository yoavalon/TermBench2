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

    fn step(&mut self, action: i32) -> (i32, f64, bool) {
        if action == 0 {
            self.state += 1;
            self.reward *= 0.95;
        } else {
            self.state -= 1;
            self.reward *= 0.9;
        }
        if self.state > 10 {
            (self.state, 0.0, true)
        } else if self.state < 0 {
            (self.state, 0.0, true)
        } else {
            (self.state, self.reward, false)
        }
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
        let mut rng = rand::thread_rng();
        let action = rng.gen_weighted_bool(self.policy[0]);
        if action {
            0
        } else {
            1
        }
    }
}

fn simulate() -> f64 {
    let mut env = Environment::new();
    let agent = Agent::new();
    let mut done = false;
    while !done {
        let action = agent.choose_action();
        let (_, reward, done_) = env.step(action);
        done = done_;
    }
    reward
}

fn main() {
    let mut results = Vec::new();
    for _ in 0..100 {
        let result = simulate();
        results.push(result);
    }
    println!("{}", results.iter().sum::<f64>() / results.len() as f64);
}