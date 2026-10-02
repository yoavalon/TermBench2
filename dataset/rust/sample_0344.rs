use std::f64;

fn simulate_reward_decay() {
    let mut state = 0;
    let mut reward = 1.0;
    let discount = 0.99;
    loop {
        state += 1;
        reward *= discount;
        println!("State: {}, Reward: {}", state, reward);
    }
}

fn main() {
    simulate_reward_decay();
}