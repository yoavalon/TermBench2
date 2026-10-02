use rand::distributions::{Distribution, Normal};
use rand::thread_rng;
use std::f64::consts::E;

fn simulate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![S0]; M];
    let normal = Normal::new(0.0, 1.0);

    for t in 1..=N {
        for i in 0..M {
            let z = normal.sample(&mut thread_rng());
            let next_price = paths[i][t - 1] * E.powf((mu - 0.5 * sigma.powi(2)) * dt + sigma * dt.sqrt() * z);
            paths[i].push(next_price);
        }
    }

    paths
}

fn calculate_payoffs(paths: Vec<Vec<f64>>, K: f64, T: f64, r: f64, type_: &str) -> Vec<f64> {
    let mut payoffs = Vec::new();

    for path in paths {
        let ST = path.last().unwrap();
        let payoff = if type_ == "call" {
            ST.max(&0.0) - K
        } else {
            K - ST.min(&0.0)
        };
        payoffs.push(payoff * E.powf(-r * T));
    }

    payoffs
}

fn monte_carlo_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, M: usize) -> f64 {
    let paths = simulate_paths(S0, r, sigma, T, 100, M);
    let payoffs = calculate_payoffs(paths, K, T, r, "call");
    payoffs.iter().sum::<f64>() / M as f64
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let M = 10000;
    let price = monte_carlo_pricing(S0, K, T, r, sigma, M);
    println!("Option Price: {:.2}", price);
}