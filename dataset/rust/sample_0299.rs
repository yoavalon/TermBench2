extern crate rand;

use rand::distributions::Normal;
use rand::prelude::*;

fn generate_paths(S0: f64, r: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let mut paths = Vec::new();
    let normal = Normal::new(0.0, 1.0).unwrap();
    for _ in 0..M {
        let mut path = vec![S0];
        let dt = T / N as f64;
        for _ in 0..N {
            let z = normal.sample(&mut thread_rng());
            let S = path[path.len() - 1] * ((r - 0.5 * sigma.powi(2)) * dt + sigma * (dt.powf(0.5) * z)).exp();
            path.push(S);
        }
        paths.push(path);
    }
    paths
}

fn payoff_function(S: f64) -> f64 {
    f64::max(S - 100.0, 0.0)
}

fn monte_carlo_pricing(paths: Vec<Vec<f64>>, payoff_function: fn(f64) -> f64) -> f64 {
    let mut total_payoff = 0.0;
    for path in paths {
        total_payoff += payoff_function(path[path.len() - 1]);
    }
    total_payoff / paths.len() as f64 * (-0.05 * 1.0).exp()
}

fn main() {
    let S0 = 100.0;
    let r = 0.05;
    let sigma = 0.2;
    let T = 1.0;
    let N = 252;
    let M = 10000;
    let paths = generate_paths(S0, r, sigma, T, N, M);
    let option_price = monte_carlo_pricing(paths, payoff_function);
    println!("Option Price: {}", option_price);
}