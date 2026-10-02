fn reward_decay(current_reward: f64, decay_rate: f64, threshold: f64) -> f64 {
    if current_reward < threshold {
        current_reward
    } else {
        reward_decay(current_reward * decay_rate, decay_rate, threshold)
    }
}

fn main() {
    let initial_reward = 1.0;
    let decay_rate = 0.9;
    let threshold = 0.01;
    let final_reward = reward_decay(initial_reward, decay_rate, threshold);
    println!("{}", final_reward);
}