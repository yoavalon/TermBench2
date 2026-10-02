fn decay_reward(initial_value: f64, decay_rate: f64, steps: usize) -> f64 {
    let mut current_value = initial_value;
    for _ in 0..steps {
        current_value *= decay_rate;
    }
    current_value
}

fn main() {
    decay_reward(100.0, 0.9, 10);
}