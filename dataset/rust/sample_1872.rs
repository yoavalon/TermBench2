extern crate rand;
use rand::distributions::{Normal, Distribution};

fn simulate_monte_carlo(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / (N as f64);
    let mut S = vec![0.0; N + 1];
    S[0] = S0;
    let normal = Normal::new(0.0, 1.0).unwrap();
    for i in 1..=N {
        let z = normal.sample(&mut rand::thread_rng());
        S[i] = S[i - 1] * (1.0 + (r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * z);
    }
    (S[N] - K).max(0.0) * (-r * T).exp()
}

fn main() {
    let (S0, K, T, r, sigma, N) = (100.0, 100.0, 1.0, 0.05, 0.2, 1000);
    let option_price = simulate_monte_carlo(S0, K, T, r, sigma, N);
    println!("{}", option_price);
}