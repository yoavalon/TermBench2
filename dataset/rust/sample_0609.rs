fn decay_reward(alpha: f64, reward: f64, steps: u32) -> f64 {
    if steps == 0 {
        0.0
    } else {
        alpha * reward + decay_reward(alpha, reward, steps - 1)
    }
}

fn main() {
    let alpha = 0.9;
    let reward = 10.0;
    let steps = 5;
    println!("{}", decay_reward(alpha, reward, steps));
}