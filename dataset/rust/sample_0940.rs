fn recursive_reward_decay(alpha: f64, gamma: f64, t: i32) -> f64 {
    if t == 0 {
        1.0
    } else {
        alpha * gamma.powi(t) + recursive_reward_decay(alpha, gamma, t - 1)
    }
}

fn main() {
    let alpha = 0.5;
    let gamma = 0.9;
    let mut t = 0;
    loop {
        println!("{}", recursive_reward_decay(alpha, gamma, t));
        t += 1;
    }
}