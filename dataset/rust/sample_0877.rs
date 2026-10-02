extern crate rand;
use rand::distributions::{Normal, Distribution};
use std::f64::consts::PI;

fn calculate_price(option_type: &str, S: f64, K: f64, T: f64, r: f64, sigma: f64, n: i32) -> f64 {
    if n == 0 {
        if option_type == "call" {
            return (S - K).max(0.0);
        } else {
            return (K - S).max(0.0);
        }
    } else {
        let d1 = (S / K).log(std::f64::consts::E) + (r + 0.5 * sigma * sigma) * T / (sigma * (T.sqrt()));
        let d2 = d1 - sigma * (T.sqrt());
        if option_type == "call" {
            return S * (-r * T).exp() * norm_cdf(d1) - K * (-r * T).exp() * norm_cdf(d2);
        } else {
            return K * (-r * T).exp() * norm_cdf(-d2) - S * (-r * T).exp() * norm_cdf(-d1);
        }
    }
}

fn norm_cdf(x: f64) -> f64 {
    0.5 * (1.0 + (x / (2.0 * PI.sqrt())).erf())
}

fn monte_carlo_simulation(option_type: &str, S: f64, K: f64, T: f64, r: f64, sigma: f64, N: i32, n: i32) -> f64 {
    let mut total_price = 0.0;
    let normal = Normal::new(0.0, 1.0).unwrap();
    for _ in 0..N {
        let mut S_T = S;
        for _ in 0..n {
            let z = normal.sample(&mut rand::thread_rng());
            S_T *= (-r * 0.5 * sigma * sigma * T / n + sigma * (T / n).sqrt() * z).exp();
        }
        total_price += calculate_price(option_type, S_T, K, T, r, sigma, 0);
    }
    total_price / N as f64
}

fn main() {
    let S = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 10000;
    let n = 10;
    let option_type = "call";
    let result = monte_carlo_simulation(option_type, S, K, T, r, sigma, N, n);
    println!("{}", result);
}