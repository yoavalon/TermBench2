extern crate rand;

use rand::distributions::{Distribution, Normal};

fn simulate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let mut paths = vec![vec![S0]; M];
    let dt = T / N as f64;
    let normal = Normal::new(0.0, 1.0);
    for _ in 0..N {
        for i in 0..M {
            let z = normal.sample(&mut rand::thread_rng());
            let S = paths[i][paths[i].len() - 1] * (1.0 + mu * dt + sigma * z * dt.sqrt());
            paths[i].push(S);
        }
    }
    paths
}

fn calculate_option_price(paths: Vec<Vec<f64>>, K: f64, r: f64, T: f64) -> f64 {
    let payoff: Vec<f64> = paths.into_iter().map(|p| (p.last().unwrap() - K).max(0.0)).collect();
    let price = payoff.iter().sum::<f64>() / payoff.len() as f64 * (1.0 / (1.0 + r * T));
    price
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let r = 0.05;
    let T = 1.0;
    let N = 100;
    let M = 1000;
    let paths = simulate_paths(S0, r - 0.5 * 0.2 * 0.2, 0.2, T, N, M);
    let price = calculate_option_price(paths, K, r, T);
    println!("{}", price);
}