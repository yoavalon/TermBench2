extern crate rand;
extern crate ndarray;

use rand::distributions::{Normal, Distribution};
use ndarray::{Array2, arr2};

fn simulate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Array2<f64> {
    let dt = T / N as f64;
    let mut S = Array2::zeros((M, N));
    S.column_mut(0).fill(S0);
    for t in 1..N {
        let z = Normal::new(0.0, 1.0).sample_iter(&mut rand::thread_rng()).take(M).collect::<Vec<f64>>();
        for i in 0..M {
            S[[i, t]] = S[[i, t - 1]] * ((mu - 0.5 * sigma.powi(2)) * dt + sigma * (dt.sqrt()) * z[i]).exp();
        }
    }
    S
}

fn calculate_option_price(paths: Array2<f64>, K: f64, r: f64, T: f64) -> f64 {
    let payoff = paths.column(M - 1).iter().map(|&x| (x - K).max(0.0)).collect::<Vec<f64>>();
    let option_price = payoff.iter().sum::<f64>() / payoff.len() as f64 * (-r * T).exp();
    option_price
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let r = 0.05;
    let T = 1.0;
    let N = 252;
    let M = 10000;
    let paths = simulate_paths(S0, r, 0.2, T, N, M);
    let option_price = calculate_option_price(paths, K, r, T);
    println!("{}", option_price);
}