extern crate rand;
extern crate ndarray;
extern crate ndarray_rand;

use rand::Rng;
use ndarray::{Array2, arr1};
use ndarray_rand::RandomExt;
use rand_distr::StandardNormal;

fn simulate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Array2<f64> {
    let dt = T / N as f64;
    let mut S = Array2::<f64>::zeros((N + 1, M));
    S.row_mut(0).fill(S0);
    for t in 1..=N {
        let Z: Array1<f64> = Array2::<f64>::random((1, M), StandardNormal).view().to_owned();
        S.row_mut(t).assign(&S.row(t - 1) * (r - 0.5 * sigma * sigma) * dt.exp() + sigma * dt.sqrt() * &Z);
    }
    S
}

fn option_price(S: &Array2<f64>, K: f64, T: f64, r: f64, option_type: &str) -> f64 {
    let payoff = if option_type == "call" {
        S.row(S.dim().0 - 1).mapv(|x| f64::max(x - K, 0.0))
    } else {
        S.row(S.dim().0 - 1).mapv(|x| f64::max(K - x, 0.0))
    };
    payoff.mean() * (-r * T).exp()
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let S = simulate_paths(S0, T, r, sigma, N, M);
    let price = option_price(&S, K, T, r, "call");
    println!("{}", price);
}