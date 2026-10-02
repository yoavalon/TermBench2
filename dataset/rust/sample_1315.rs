extern crate rand;
extern crate nalgebra as na;

use rand::Rng;
use na::DMatrix;

fn generate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> DMatrix<f64> {
    let dt = T / N as f64;
    let mut paths = DMatrix::zeros(N + 1, M);
    paths.row_mut(0).fill(S0);
    for t in 1..=N {
        let mut rng = rand::thread_rng();
        let z: Vec<f64> = (0..M).map(|_| rng.sample(rand::distributions::StandardNormal)).collect();
        for i in 0..M {
            paths[(t, i)] = paths[(t - 1, i)] * ((r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * z[i]).exp();
        }
    }
    paths
}

fn option_price(paths: DMatrix<f64>, K: f64, r: f64, T: f64) -> f64 {
    let payoff: Vec<f64> = paths.row(paths.nrows() - 1).iter().map(|&x| x.max(K)).collect();
    let mean_payoff = payoff.iter().sum::<f64>() / payoff.len() as f64;
    (mean_payoff * (-r * T).exp())
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let r = 0.05;
    let sigma = 0.2;
    let T = 1.0;
    let N = 252;
    let M = 10000;
    let paths = generate_paths(S0, T, r, sigma, N, M);
    let price = option_price(paths, K, r, T);
    println!("{}", price);
}