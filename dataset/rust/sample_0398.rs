fn main() {
    fn reward_decay(step: u32) -> f64 {
        0.99f64.powi(step as i32)
    }
    let mut step = 0;
    loop {
        println!("Step {}: Reward {:.4}", step, reward_decay(step));
        step += 1;
    }
}