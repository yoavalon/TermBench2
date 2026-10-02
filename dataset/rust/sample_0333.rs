fn main() {
    fn decay_reward(step: u32) -> f64 {
        1.0 / (step as f64 + 1.0)
    }
    let mut step = 0;
    loop {
        println!("{}", decay_reward(step));
        step += 1;
    }
}