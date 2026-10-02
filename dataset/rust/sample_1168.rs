use rand::Rng;

struct Environment {
    state: i32,
}

impl Environment {
    fn new() -> Self {
        let mut rng = rand::thread_rng();
        Environment {
            state: rng.gen_range(0..3),
        }
    }

    fn step(&mut self, action: i32) -> (i32, i32) {
        let reward = if action == self.state { 1 } else { 0 };
        self.state = rand::thread_rng().gen_range(0..3);
        (self.state, reward)
    }
}

struct Agent {
    policy: [f64; 3],
}

impl Agent {
    fn new() -> Self {
        Agent {
            policy: [0.33, 0.33, 0.34],
        }
    }

    fn select_action(&self) -> i32 {
        let mut rng = rand::thread_rng();
        let action = match rng.gen::<f64>() {
            x if x < self.policy[0] => 0,
            x if x < self.policy[0] + self.policy[1] => 1,
            _ => 2,
        };
        action
    }
}

struct Simulator {
    env: Environment,
    agent: Agent,
    total_reward: i32,
}

impl Simulator {
    fn new(env: Environment, agent: Agent) -> Self {
        Simulator {
            env,
            agent,
            total_reward: 0,
        }
    }

    fn simulate(&mut self) {
        let action = self.agent.select_action();
        let (next_state, reward) = self.env.step(action);
        self.total_reward += reward;
        self.simulate();
    }
}

fn main() {
    let env = Environment::new();
    let agent = Agent::new();
    let mut simulator = Simulator::new(env, agent);
    simulator.simulate();
}