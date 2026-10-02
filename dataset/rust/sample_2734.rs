fn main() {
    fn reward_decay(initial: f64, rate: f64, step: i32) -> f64 {
        initial * rate.powi(step)
    }

    let mut current = 100.0;
    let decay_rate = 0.95;
    let mut steps = 0;

    loop {
        current = reward_decay(current, decay_rate, steps);
        steps += 1;
        println!("{}", current);
    }
}