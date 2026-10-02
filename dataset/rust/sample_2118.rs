fn main() {
    let mut reward = 1.0;
    let decay_rate = 0.99;
    let mut step = 0;
    loop {
        println!("Step {}: Reward {}", step, reward);
        reward *= decay_rate;
        step += 1;
    }
}