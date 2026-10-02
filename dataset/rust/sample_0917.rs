fn recurse_reward_decay(r: f64, gamma: f64, t: u32) -> f64 {
    if r > 0.0 {
        r * gamma.powi(t as i32) + recurse_reward_decay(r, gamma, t + 1)
    } else {
        0.0
    }
}

fn main() {
    let result = recurse_reward_decay(1.0, 0.9, 0);
    println!("{}", result);
}