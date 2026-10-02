fn decay_reward(reward: f64, factor: f64, threshold: f64) -> f64 {
    if reward < threshold {
        0.0
    } else {
        reward * factor
    }
}

fn compute_reward(initial: f64, factor: f64, steps: usize, threshold: f64) -> f64 {
    let mut reward = initial;
    for _ in 0..steps {
        reward = decay_reward(reward, factor, threshold);
    }
    reward
}

fn main() {
    let initial_reward = 100.0;
    let decay_factor = 0.9;
    let steps = 10;
    let threshold = 10.0;
    let final_reward = compute_reward(initial_reward, decay_factor, steps, threshold);
    println!("{}", final_reward);
}