use rand::Rng;

struct Environment {
    current: i32,
    goal: i32,
    decay_rate: f64,
    time_step: usize,
}

impl Environment {
    fn new(start: i32, goal: i32, decay_rate: f64) -> Self {
        Environment {
            current: start,
            goal: goal,
            decay_rate: decay_rate,
            time_step: 0,
        }
    }

    fn step(&mut self, action: i32) -> (i32, f64, bool) {
        self.current += action;
        self.time_step += 1;
        let reward = self.compute_reward();
        let done = self.is_done();
        (self.current, reward, done)
    }

    fn compute_reward(&self) -> f64 {
        let distance = (self.current - self.goal).abs() as f64;
        let reward = 1.0 / (distance + 1.0);
        reward * (1.0 - self.decay_rate).powi(self.time_step as i32)
    }

    fn is_done(&self) -> bool {
        self.current == self.goal || self.time_step > 1000
    }
}

struct Agent {
    action_space: rand::rngs::StdRng,
}

impl Agent {
    fn new(seed: u64) -> Self {
        Agent {
            action_space: rand::SeedableRng::seed_from_u64(seed),
        }
    }

    fn act(&mut self) -> i32 {
        self.action_space.gen_range(-1..=1)
    }
}

fn run_episode(env: &mut Environment, agent: &mut Agent) -> f64 {
    let mut observation = env.current;
    let mut total_reward = 0.0;
    let mut done = false;
    while !done {
        let action = agent.act();
        let (new_observation, reward, new_done) = env.step(action);
        observation = new_observation;
        total_reward += reward;
        done = new_done;
    }
    total_reward
}

fn main() {
    let mut env = Environment::new(0, 10, 0.01);
    let mut agent = Agent::new(42);
    let episode_reward = run_episode(&mut env, &mut agent);
    println!("Episode reward: {}", episode_reward);
}