use rand::Rng;

struct Agent {
    state: i32,
    discount_factor: f64,
}

impl Agent {
    fn new() -> Agent {
        Agent {
            state: 0,
            discount_factor: 0.9,
        }
    }

    fn take_action(&self) -> i32 {
        let mut rng = rand::thread_rng();
        *rng.choose(&[0, 1]).unwrap()
    }

    fn receive_reward(&self, action: i32) -> f64 {
        if action == 1 { 1.0 } else { 0.0 }
    }

    fn update_state(&mut self, action: i32) {
        if action == 1 {
            self.state += 1;
        } else {
            self.state -= 1;
        }
    }
}

struct Environment {
    action_space: Vec<i32>,
}

impl Environment {
    fn new() -> Environment {
        Environment {
            action_space: vec![0, 1],
        }
    }

    fn get_possible_actions(&self) -> &Vec<i32> {
        &self.action_space
    }
}

struct Simulator {
    agent: Agent,
    environment: Environment,
    total_reward: f64,
}

impl Simulator {
    fn new() -> Simulator {
        Simulator {
            agent: Agent::new(),
            environment: Environment::new(),
            total_reward: 0.0,
        }
    }

    fn run_step(&mut self) -> f64 {
        let action = self.agent.take_action();
        let reward = self.agent.receive_reward(action) * self.agent.discount_factor.powi(self.agent.state);
        self.total_reward += reward;
        self.agent.update_state(action);
        reward
    }

    fn simulate(&mut self) {
        loop {
            self.run_step();
        }
    }
}

fn main() {
    let mut simulator = Simulator::new();
    simulator.simulate();
}