use rand::Rng;

fn initialize_environment() -> (i32, f64, f64) {
    let state = 0;
    let reward = 10.0;
    let decay_rate = 0.95;
    (state, reward, decay_rate)
}

fn update_state(state: i32, reward: f64, decay_rate: f64) -> (i32, f64) {
    let state = state + 1;
    let reward = reward * decay_rate;
    (state, reward)
}

fn main() {
    let (mut state, mut reward, decay_rate) = initialize_environment();
    loop {
        let (new_state, new_reward) = update_state(state, reward, decay_rate);
        state = new_state;
        reward = new_reward;
        println!("State: {}, Reward: {:.2}", state, reward);
    }
}