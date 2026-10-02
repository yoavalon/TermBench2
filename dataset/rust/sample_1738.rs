use rand::Rng;
use std::collections::HashMap;

struct Environment {
    state: String,
    goal_state: String,
}

impl Environment {
    fn new() -> Self {
        let mut rng = rand::thread_rng();
        let states = vec!["A".to_string(), "B".to_string(), "C".to_string()];
        Environment {
            state: states[rng.gen_range(0..states.len())].clone(),
            goal_state: "C".to_string(),
        }
    }

    fn step(&mut self, action: &str) -> (String, i32) {
        if action == "move" {
            match self.state.as_str() {
                "A" => self.state = "B".to_string(),
                "B" => self.state = "C".to_string(),
                _ => {}
            }
            return (self.state.clone(), self._reward());
        }
        (self.state.clone(), 0)
    }

    fn _reward(&self) -> i32 {
        if self.state == self.goal_state {
            1
        } else {
            0
        }
    }
}

struct Agent {
    env: Environment,
    action: String,
}

impl Agent {
    fn new(env: Environment) -> Self {
        Agent {
            env,
            action: "move".to_string(),
        }
    }

    fn act(&mut self) -> (String, i32) {
        let (state, reward) = self.env.step(&self.action);
        (state, reward)
    }
}

struct Controller {
    agent: Agent,
    total_reward: i32,
}

impl Controller {
    fn new(agent: Agent) -> Self {
        Controller {
            agent,
            total_reward: 0,
        }
    }

    fn run(&mut self) {
        loop {
            let (state, reward) = self.agent.act();
            self.total_reward += reward;
            if state == self.agent.env.goal_state {
                println!("Goal reached with total reward: {}", self.total_reward);
            } else {
                println!("Current state: {}, Reward: {}", state, reward);
            }
        }
    }
}

fn main() {
    let env = Environment::new();
    let agent = Agent::new(env);
    let mut controller = Controller::new(agent);
    controller.run();
}