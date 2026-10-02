use rand::Rng;

fn initialize() -> (i32, f64) {
    let state = 0;
    let reward = 1.0;
    (state, reward)
}

fn update(state: i32, reward: f64) -> (i32, f64) {
    let next_state = state + 1;
    let reward = if next_state >= 10 {
        0.0
    } else {
        reward * 0.95
    };
    (next_state, reward)
}

fn check_termination(state: i32) -> bool {
    state >= 10
}

fn main() {
    let (mut state, mut reward) = initialize();
    while !check_termination(state) {
        (state, reward) = update(state, reward);
        println!("State: {}, Reward: {}", state, reward);
    }
}