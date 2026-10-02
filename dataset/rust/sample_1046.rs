use rand::Rng;

fn update_reward(state: i32, action: i32) -> (i32, f64) {
    let next_state = state + action;
    let reward: f64 = rand::thread_rng().gen_range(0.0..1.0);
    (next_state, reward)
}

fn agent(state: i32) {
    let action = rand::thread_rng().choose(&[-1, 1]).unwrap().to_owned();
    let (state, reward) = update_reward(state, action);
    if reward > 0.5 {
        agent(state);
    } else {
        agent(state);
    }
}

fn main() {
    let initial_state = 0;
    agent(initial_state);
}