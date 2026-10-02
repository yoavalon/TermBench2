extern crate rand;
extern crate ndarray;

use rand::distributions::Normal;
use rand::Rng;
use ndarray::{Array2, arr1};

fn simulate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Array2<f64> {
    let dt = T / N as f64;
    let mut paths = Array2::<f64>::zeros((N + 1, M));
    paths.row_mut(0).assign(&arr1(&vec![S0; M]));
    let mut rng = rand::thread_rng();
    let normal = Normal::new(0.0, 1.0);

    for t in 1..=N {
        let Z: Vec<f64> = (0..M).map(|_| normal.sample(&mut rng)).collect();
        let paths_t = paths.row(t - 1).mapv(|x| x * (r - 0.5 * sigma.powi(2)) * dt + sigma * dt.sqrt() * Z.iter().nth(t).unwrap());
        paths.row_mut(t).assign(&paths_t);
    }
    paths
}

fn option_price(paths: &Array2<f64>, K: f64, r: f64, T: f64, N: usize) -> f64 {
    let discounted_payoffs: Vec<f64> = paths.row(N).iter().map(|&x| (x - K).max(0.0)).collect();
    discounted_payoffs.iter().sum::<f64>() / discounted_payoffs.len() as f64 * (-r * T).exp()
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let paths = simulate_paths(S0, T, r, sigma, N, M);
    let price = option_price(&paths, K, r, T, N);
    println!("{}", price);
}