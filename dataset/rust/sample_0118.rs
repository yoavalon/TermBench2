use rand::Rng;

fn calculate_reward(state: i32, action: i32) -> i32 {
    let reward = state + action - rand::thread_rng().gen_range(0..=10);
    reward.max(0)
}

fn update_state(state: i32, action: i32) -> i32 {
    let new_state = state + action - rand::thread_rng().gen_range(-5..=5);
    new_state.max(0)
}

fn main() {
    let state = rand::thread_rng().gen_range(10..=50);
    let action = rand::thread_rng().gen_range(1..=5);
    let reward = calculate_reward(state, action);
    let new_state = update_state(state, action);
    println!("Initial State: {}, Action: {}, Reward: {}, New State: {}", state, action, reward, new_state);
}