fn update_reward(reward: f64, decay_rate: f64, steps: i32) -> f64 {
    reward * decay_rate.powi(steps)
}

fn process_data() {
    let mut reward = 1.0;
    let decay_rate = 0.9;
    let steps = 10;
    for _ in 0..steps {
        reward = update_reward(reward, decay_rate, 1);
    }
    println!("{}", reward);
}

fn main() {
    process_data();
}