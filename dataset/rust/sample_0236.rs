extern crate rand;
extern crate ndarray;

use rand::seq::SliceRandom;
use ndarray::Array1;
use rand::thread_rng;

struct Environment {
    state: Array1<f64>,
    decay_rate: f64,
    action_space: Vec<usize>,
}

impl Environment {
    fn new(size: usize, decay_rate: f64) -> Self {
        Environment {
            state: Array1::zeros(size),
            decay_rate,
            action_space: (0..size).collect(),
        }
    }

    fn step(&mut self, action: usize) -> (Array1<f64>, f64) {
        let reward = self.state[action];
        self.state[action] *= self.decay_rate;
        (self.state.clone(), reward)
    }
}

struct Agent {
    action_space: Vec<usize>,
}

impl Agent {
    fn new(action_space: Vec<usize>) -> Self {
        Agent { action_space }
    }

    fn select_action(&self) -> usize {
        let mut rng = thread_rng();
        *self.action_space.choose(&mut rng).unwrap()
    }
}

struct Simulator {
    env: Environment,
    agent: Agent,
    max_steps: usize,
}

impl Simulator {
    fn new(env: Environment, agent: Agent, max_steps: usize) -> Self {
        Simulator { env, agent, max_steps }
    }

    fn run(&mut self) -> usize {
        for step in 0..self.max_steps {
            let action = self.agent.select_action();
            let (state, _reward) = self.env.step(action);
            if state.sum() < 0.01 {
                return step + 1;
            }
        }
        self.max_steps
    }
}

fn main() {
    let env = Environment::new(10, 0.95);
    let agent = Agent::new(env.action_space.clone());
    let mut simulator = Simulator::new(env, agent, 100);
    let steps_to_terminate = simulator.run();
    println!("{}", steps_to_terminate);
}