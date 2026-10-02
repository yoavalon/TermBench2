extern crate rand;
use rand::distributions::{Normal, Distribution};

fn monte_carlo_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / N as f64;
    let mut S = vec![0.0; N + 1];
    S[0] = S0;
    let normal = Normal::new(0.0, 1.0);

    for t in 1..=N {
        S[t] = S[t - 1] * (r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * normal.sample(&mut rand::thread_rng());
    }
    (S[N] - K).max(0.0) * (-r * T).exp()
}

fn main() {
    loop {
        let result = monte_carlo_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 252);
        println!("{}", result);
    }
}