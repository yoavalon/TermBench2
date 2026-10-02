extern crate rand;
extern crate ndarray;

use rand::distributions::{Normal, Distribution};
use ndarray::{Array2, Array1};
use std::f64::consts::E;

fn generate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Array2<f64> {
    let dt = T / N as f64;
    let mut S = Array2::<f64>::zeros((N + 1, M));
    S.row_mut(0).fill(S0);
    let normal = Normal::new(0.0, 1.0);
    for t in 1..=N {
        let mut rng = rand::thread_rng();
        let random_values: Array1<f64> = (0..M).map(|_| normal.sample(&mut rng)).collect();
        S.row_mut(t).assign(&S.row(t - 1) * E.powf((mu - 0.5 * sigma.powi(2)) * dt + sigma * (dt as f64).sqrt() * random_values));
    }
    S
}

fn option_price(paths: Array2<f64>, K: f64, r: f64, T: f64, payoff: &dyn Fn(&Array1<f64>, f64) -> Array1<f64>) -> f64 {
    let discounted_payoffs = payoff(paths.row(N), K) * E.powf(-r * T);
    discounted_payoffs.mean().unwrap()
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let r = 0.05;
    let T = 1.0;
    let N = 252;
    let M = 10000;
    let sigma = 0.2;
    let mu = 0.1;

    let european_call = |S: &Array1<f64>, K: f64| S.map(|&x| (x - K).max(0.0));

    let paths = generate_paths(S0, mu, sigma, T, N, M);
    let call_price = option_price(paths, K, r, T, &european_call);
    println!("{}", call_price);
}