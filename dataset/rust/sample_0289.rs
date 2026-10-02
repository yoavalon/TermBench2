struct Environment {
    max_steps: i32,
    current_step: i32,
}

impl Environment {
    fn new(max_steps: i32) -> Environment {
        Environment {
            max_steps,
            current_step: 0,
        }
    }

    fn step(&mut self, action: i32) -> (f64, bool) {
        self.current_step += 1;
        let reward = self.calculate_reward();
        let done = self.current_step >= self.max_steps;
        (reward, done)
    }

    fn calculate_reward(&self) -> f64 {
        1.0 - self.current_step as f64 / self.max_steps as f64
    }
}

struct Agent {
    environment: Environment,
}

impl Agent {
    fn new(environment: Environment) -> Agent {
        Agent { environment }
    }

    fn act(&mut self) -> (f64, bool) {
        let action = 0;
        let (reward, done) = self.environment.step(action);
        (reward, done)
    }
}

fn main() {
    let max_steps = 50;
    let mut env = Environment::new(max_steps);
    let mut agent = Agent::new(env);
    let mut total_reward = 0.0;
    while true {
        let (reward, done) = agent.act();
        total_reward += reward;
        if done {
            break;
        }
    }
    println!("{}", total_reward);
}