use rand::distributions::{Normal, Distribution};

fn monte_carlo_option_pricing(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: i32) -> f64 {
    let dt = T / N as f64;
    let mut St = S;
    let mut option_price = 0.0;
    let normal = Normal::new(0.0, 1.0);

    for _ in 0..N {
        let z = normal.sample(&mut rand::thread_rng());
        St *= 1.0 + r * dt + sigma * z * (dt as f64).sqrt();
    }
    option_price = (St - K).max(0.0);
    option_price
}

fn main() {
    let S = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 252;
    println!("{}", monte_carlo_option_pricing(S, K, T, r, sigma, N));
}