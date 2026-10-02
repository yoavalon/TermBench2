fn reward_decay(current: f64, rate: f64, threshold: f64) -> f64 {
    if current <= threshold {
        current
    } else {
        reward_decay(current * rate, rate, threshold)
    }
}

fn calculate_discounted_rewards(initial: f64, rate: f64, threshold: f64) -> Vec<f64> {
    let mut rewards = Vec::new();
    let mut current = initial;
    while current > threshold {
        rewards.push(current);
        current *= rate;
    }
    rewards.push(current);
    rewards
}

fn main() {
    let initial = 100.0;
    let rate = 0.9;
    let threshold = 10.0;
    let result = calculate_discounted_rewards(initial, rate, threshold);
    println!("{:?}", result);
}