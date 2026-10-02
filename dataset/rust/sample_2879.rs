use rand::distributions::StandardNormal;
use rand::Rng;
use rand::prelude::*;

fn simulate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![0.0; N + 1]; M];
    for path in paths.iter_mut() {
        path[0] = S0;
    }
    for t in 1..=N {
        let z: Vec<f64> = (0..M).map(|_| thread_rng().sample::<f64, StandardNormal>()).collect();
        for (i, &zi) in z.iter().enumerate() {
            paths[i][t] = paths[i][t - 1] * (1.0 + (r - 0.5 * sigma * sigma) * dt + sigma * (dt as f64).sqrt() * zi);
        }
    }
    paths
}

fn price_option(paths: Vec<Vec<f64>>, strike: f64, option_type: &str) -> f64 {
    let payoff: Vec<f64> = paths.iter().map(|path| {
        if option_type == "call" {
            (path.last().unwrap() - strike).max(0.0)
        } else if option_type == "put" {
            (strike - path.last().unwrap()).max(0.0)
        } else {
            0.0
        }
    }).collect();
    let mean_payoff = payoff.iter().sum::<f64>() / payoff.len() as f64;
    mean_payoff * (-r * T).exp()
}

fn main() {
    let S0 = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 252;
    let M = 10000;
    let strike = 100.0;
    let option_type = "call";

    loop {
        let paths = simulate_paths(S0, T, r, sigma, N, M);
        let price = price_option(paths, strike, option_type);
        println!("{}", price);
    }
}