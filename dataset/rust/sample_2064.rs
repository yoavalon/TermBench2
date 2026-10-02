extern crate rand;

use rand::Rng;
use std::f64;

struct Environment {
    num_states: usize,
    num_actions: usize,
}

impl Environment {
    fn new(num_states: usize, num_actions: usize) -> Self {
        Environment {
            num_states,
            num_actions,
        }
    }

    fn step(&self, state: usize, action: usize) -> (usize, f64, bool) {
        let reward = self._compute_reward(state, action);
        let next_state = self._transition(state, action);
        let done = self._is_done(next_state);
        (next_state, reward, done)
    }

    fn _compute_reward(&self, state: usize, action: usize) -> f64 {
        -(state as f64 - action as f64).sqrt()
    }

    fn _transition(&self, state: usize, action: usize) -> usize {
        (state + action) % self.num_states
    }

    fn _is_done(&self, state: usize) -> bool {
        state == 0
    }
}

struct Agent {
    num_actions: usize,
    policy: Vec<f64>,
}

impl Agent {
    fn new(num_actions: usize) -> Self {
        let policy = vec![1.0 / num_actions as f64; num_actions];
        Agent {
            num_actions,
            policy,
        }
    }

    fn select_action(&self) -> usize {
        let mut rng = rand::thread_rng();
        let sum: f64 = self.policy.iter().sum();
        let mut cumulative = 0.0;
        for (i, &prob) in self.policy.iter().enumerate() {
            cumulative += prob / sum;
            if rng.gen::<f64>() < cumulative {
                return i;
            }
        }
        self.num_actions - 1
    }

    fn update_policy(&mut self, state: usize, action: usize, reward: f64) {
        self.policy[action] += 0.1 * (reward - self.policy.iter().sum::<f64>() / self.policy.len() as f64);
    }
}

fn main() {
    let num_states = 10;
    let num_actions = 5;
    let max_steps = 100;
    let gamma = 0.99;
    let env = Environment::new(num_states, num_actions);
    let mut agent = Agent::new(num_actions);
    let mut rng = rand::thread_rng();
    let mut state = rng.gen_range(0..num_states);

    for _ in 0..max_steps {
        let action = agent.select_action();
        let (next_state, reward, done) = env.step(state, action);
        agent.update_policy(state, action, reward);
        state = next_state;
        if done {
            break;
        }
    }
}