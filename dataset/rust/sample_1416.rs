use rand::Rng;

struct Environment {
    state: Vec<f64>,
}

impl Environment {
    fn new(size: usize) -> Self {
        Environment {
            state: vec![0.0; size],
        }
    }

    fn reset(&mut self) -> &mut Vec<f64> {
        self.state.iter_mut().for_each(|x| *x = 0.0);
        &mut self.state
    }

    fn step(&mut self, action: usize) -> (Vec<f64>, f64, bool) {
        let reward = rand::thread_rng().gen::<f64>();
        self.state[action] += 1.0;
        let done = self.state.iter().any(|&x| x > 10.0);
        (self.state.clone(), reward, done)
    }
}

struct Agent {
    action_space: Vec<usize>,
}

impl Agent {
    fn new(action_space: Vec<usize>) -> Self {
        Agent { action_space }
    }

    fn choose_action(&self) -> usize {
        let mut rng = rand::thread_rng();
        *rng.choose(&self.action_space).unwrap()
    }
}

fn train_agent(env: &mut Environment, agent: &Agent, episodes: usize, decay_rate: f64) -> Vec<f64> {
    let mut rewards = Vec::new();
    for episode in 0..episodes {
        env.reset();
        let mut total_reward = 0.0;
        for _ in 0..100 {
            let action = agent.choose_action();
            let (state, reward, done) = env.step(action);
            total_reward += reward;
            if done {
                break;
            }
        }
        rewards.push(total_reward);
        if episode > 0 && episode % 10 == 0 {
            rewards = rewards.iter().map(|&r| r * decay_rate).collect();
        }
    }
    rewards
}

fn main() {
    let env_size = 5;
    let action_space: Vec<usize> = (0..env_size).collect();
    let mut env = Environment::new(env_size);
    let agent = Agent::new(action_space);
    let episodes = 50;
    let decay_rate = 0.9;
    train_agent(&mut env, &agent, episodes, decay_rate);
}