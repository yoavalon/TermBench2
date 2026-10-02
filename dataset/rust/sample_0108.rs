use rand::Rng;

fn generate_reward() -> f64 {
    let mut rng = rand::thread_rng();
    rng.gen_range(0.1..=1.0)
}

fn update_state(state: f64, reward: f64, decay_rate: f64) -> f64 {
    state * decay_rate + reward
}

fn should_terminate(state: f64, threshold: f64) -> bool {
    state < threshold
}

fn main() {
    let mut state = 1.0;
    let decay_rate = 0.9;
    let threshold = 0.1;
    let mut steps = 0;
    let max_steps = 100;
    while steps < max_steps && !should_terminate(state, threshold) {
        let reward = generate_reward();
        state = update_state(state, reward, decay_rate);
        steps += 1;
    }
    println!("Terminated after {} steps with state {:.2}", steps, state);
}