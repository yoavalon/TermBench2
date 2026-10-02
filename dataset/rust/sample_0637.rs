fn decay_reward(base: f64, factor: f64, threshold: f64, value: f64) -> f64 {
    if value * factor < threshold {
        value
    } else {
        decay_reward(base, factor, threshold, value * factor)
    }
}

fn main() {
    decay_reward(0.9, 0.95, 0.1, 1.0);
}