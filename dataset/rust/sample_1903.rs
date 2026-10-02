use rand::Rng;

fn simulate_option_price(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / N as f64;
    let mut S = S0;
    for _ in 0..N {
        let mut rng = rand::thread_rng();
        S *= (r - 0.5 * sigma * sigma) * dt + sigma * (dt as f64).sqrt() * rng.normal(0.0, 1.0);
    }
    return f64::max(S - K, 0.0);
}

fn monte_carlo_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, M: usize, N: usize) -> f64 {
    let mut total = 0.0;
    for _ in 0..M {
        total += simulate_option_price(S0, K, T, r, sigma, N);
    }
    return total / M as f64 * (-r * T).exp();
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let M = 1000;
    let N = 100;
    println!("{}", monte_carlo_pricing(S0, K, T, r, sigma, M, N));
}