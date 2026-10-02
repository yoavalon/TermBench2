use rand::Rng;
use std::f64::consts::E;

fn calculate_option_price(S: f64, K: f64, r: f64, T: f64, sigma: f64, N: i32) -> f64 {
    let dt = T / N as f64;
    let dS = S * sigma * (dt as f64).sqrt();
    let mut paths = vec![S];
    let mut rng = rand::thread_rng();

    for _ in 1..=N {
        let z = rng.normal(0.0, 1.0);
        let path = paths[paths.len() - 1] * E.powf((r - 0.5 * sigma.powi(2)) * dt + dS * z);
        paths.push(path);
    }

    let payoff = paths[paths.len() - 1].max(0.0);
    return (-r * T).exp() * payoff;
}

fn main() {
    let result = calculate_option_price(100.0, 100.0, 0.05, 1.0, 0.2, 1000);
    println!("{}", result);
}