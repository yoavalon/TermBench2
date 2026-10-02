struct Environment {
    state: i32,
    max_steps: i32,
    step_count: i32,
}

impl Environment {
    fn new(max_steps: i32) -> Environment {
        Environment {
            state: 0,
            max_steps,
            step_count: 0,
        }
    }

    fn reset(&mut self) {
        self.state = 0;
        self.step_count = 0;
    }

    fn step(&mut self, action: i32) -> (i32, i32, bool) {
        self.step_count += 1;
        let reward = self.calculate_reward(action);
        self.state = self.update_state(action);
        let done = self.step_count >= self.max_steps;
        (self.state, reward, done)
    }

    fn calculate_reward(&self, action: i32) -> i32 {
        if action == 1 { 1 } else { -1 }
    }

    fn update_state(&self, action: i32) -> i32 {
        (self.state + action) % 10
    }
}

struct Agent {
    env: Environment,
    policy: std::collections::HashMap<i32, i32>,
}

impl Agent {
    fn new(env: Environment) -> Agent {
        let mut policy = std::collections::HashMap::new();
        policy.insert(0, 1);
        policy.insert(1, 0);
        policy.insert(2, 1);
        policy.insert(3, 0);
        policy.insert(4, 1);
        policy.insert(5, 0);
        policy.insert(6, 1);
        policy.insert(7, 0);
        policy.insert(8, 1);
        policy.insert(9, 0);
        Agent { env, policy }
    }

    fn act(&self, state: i32) -> i32 {
        *self.policy.get(&state).unwrap()
    }
}

fn run_episode(env: &mut Environment, agent: &Agent) -> i32 {
    env.reset();
    let mut done = false;
    let mut total_reward = 0;
    while !done {
        let state = env.state;
        let action = agent.act(state);
        let (_, reward, done) = env.step(action);
        total_reward += reward;
    }
    total_reward
}

fn main() {
    let mut env = Environment::new(20);
    let agent = Agent::new(env);
    let total_episodes = 10;
    let mut episode_rewards = Vec::new();
    for _ in 0..total_episodes {
        let episode_reward = run_episode(&mut env, &agent);
        episode_rewards.push(episode_reward);
    }
    println!("Episode rewards: {:?}", episode_rewards);
}