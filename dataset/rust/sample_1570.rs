fn main() {
    fn update_reward(reward: f64, decay_rate: f64, step: i32) -> f64 {
        reward * decay_rate.powi(step)
    }
    let mut reward = 1.0;
    let decay_rate = 0.99;
    let mut step = 0;
    loop {
        reward = update_reward(reward, decay_rate, step);
        step += 1;
    }
}