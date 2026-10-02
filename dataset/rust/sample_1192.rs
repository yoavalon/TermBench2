struct Agent {
    state: i32,
    action: i32,
}

impl Agent {
    fn new(state: i32, action: i32) -> Self {
        Agent { state, action }
    }

    fn update_state(&mut self, new_state: i32) {
        self.state = new_state;
    }

    fn choose_action(&self) -> i32 {
        self.action
    }
}

struct Environment {
    state: i32,
    reward_function: fn(i32) -> f64,
}

impl Environment {
    fn new(initial_state: i32, reward_function: fn(i32) -> f64) -> Self {
        Environment {
            state: initial_state,
            reward_function,
        }
    }

    fn step(&mut self, action: i32) -> (i32, f64) {
        let new_state = self.state + 1;
        let reward = (self.reward_function)(new_state);
        self.state = new_state;
        (new_state, reward)
    }
}

struct Controller {
    agent: Agent,
    environment: Environment,
}

impl Controller {
    fn new(agent: Agent, environment: Environment) -> Self {
        Controller { agent, environment }
    }

    fn execute(&mut self) {
        loop {
            let action = self.agent.choose_action();
            let (new_state, reward) = self.environment.step(action);
            self.agent.update_state(new_state);
        }
    }
}

fn reward_decay(state: i32) -> f64 {
    1.0 / (state as f64 + 1.0)
}

fn main() {
    let initial_state = 0;
    let action = 0;
    let agent = Agent::new(initial_state, action);
    let environment = Environment::new(initial_state, reward_decay);
    let mut controller = Controller::new(agent, environment);
    controller.execute();
}