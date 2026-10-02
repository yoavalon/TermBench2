extern crate rand;
use rand::Rng;

fn initialize_environment() -> i32 {
    let mut rng = rand::thread_rng();
    rng.gen_range(0..10)
}

fn update_state(state: i32, action: i32) -> i32 {
    (state + action) % 10
}

fn calculate_reward(state: i32) -> f64 {
    (state as f64).sin()
}

fn decay_reward(reward: f64, step: i32) -> f64 {
    reward * 0.9f64.powi(step)
}

fn main() {
    let state = initialize_environment();
    let mut step = 0;
    loop {
        let mut rng = rand::thread_rng();
        let action = rng.gen_range(0..3);
        let state = update_state(state, action);
        let reward = calculate_reward(state);
        let reward = decay_reward(reward, step);
        step += 1;
    }
}