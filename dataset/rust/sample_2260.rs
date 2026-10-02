extern crate rand;

use rand::Rng;

fn reward_decay(state: f64, alpha: f64) -> f64 {
    state * alpha
}

fn update_state(state: f64, action: i32, reward: f64) -> f64 {
    state + action as f64 * reward
}

fn simulate_system(initial_state: f64, alpha: f64, action_sequence: Vec<i32>) {
    let mut state = initial_state;
    loop {
        for &action in action_sequence.iter() {
            let reward = reward_decay(state, alpha);
            state = update_state(state, action, reward);
        }
    }
}

fn main() {
    let initial_state = rand::thread_rng().gen::<f64>();
    let alpha = 0.99;
    let action_sequence: Vec<i32> = (0..100).map(|_| rand::thread_rng().gen_range(0, 2)).collect();
    simulate_system(initial_state, alpha, action_sequence);
}