fn reward_decay(reward: f64, discount: f64, threshold: f64) -> f64 {
    if reward < threshold {
        reward
    } else {
        reward_decay(reward * discount, discount, threshold)
    }
}

fn main() {
    let result = reward_decay(100.0, 0.9, 10.0);
    println!("{}", result);
}