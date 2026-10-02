use rand::Rng;

fn initialize_environment() -> (i32, f64, f64) {
    let state = rand::thread_rng().gen_range(0..100);
    let reward = 100.0;
    let decay_rate = 0.99;
    (state, reward, decay_rate)
}

fn update_state(state: i32, action: i32) -> i32 {
    if action == 0 {
        state + 1
    } else {
        state - 1
    }
}

fn calculate_reward(state: i32, reward: f64, decay_rate: f64, steps: i32) -> f64 {
    reward * decay_rate.powi(steps)
}

fn terminate_condition(state: i32) -> bool {
    state == 50
}

fn agent_action(state: i32) -> i32 {
    if state < 50 {
        0
    } else {
        1
    }
}

fn main() {
    let (mut state, mut reward, decay_rate) = initialize_environment();
    let mut steps = 0;
    while !terminate_condition(state) {
        let action = agent_action(state);
        state = update_state(state, action);
        steps += 1;
        reward = calculate_reward(state, reward, decay_rate, steps);
    }
    println!("Final State: {}, Reward: {:.2}, Steps: {}", state, reward, steps);
}