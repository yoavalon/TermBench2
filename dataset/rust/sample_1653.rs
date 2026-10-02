use rand::distributions::{Normal, Distribution};
use std::f64::consts::E;

fn simulate_stock_price(S0: f64, mu: f64, sigma: f64, T: f64, dt: f64) -> f64 {
    let mut S = S0;
    let normal = Normal::new(0.0, 1.0);
    for _ in 0..(T / dt) as usize {
        let dS = mu * S * dt + sigma * S * normal.sample(&mut rand::thread_rng()) * (dt.sqrt());
        S += dS;
    }
    S
}

fn monte_carlo_option_price(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, dt: f64) -> f64 {
    let mut option_price = 0.0;
    for _ in 0..N {
        let S_T = simulate_stock_price(S0, r, sigma, T, dt);
        option_price += f64::max(S_T - K, 0.0);
    }
    option_price * (1.0 / N as f64) * E.powf(-r * T)
}

fn main() {
    let (S0, K, T, r, sigma, N, dt) = (100.0, 100.0, 1.0, 0.05, 0.2, 100000, 0.01);
    let price = monte_carlo_option_price(S0, K, T, r, sigma, N, dt);
    println!("Option Price: {}", price);
}