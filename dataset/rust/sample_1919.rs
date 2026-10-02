extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::Array2;

fn generate_paths(S0: f64, r: f64, sigma: f64, T: f64, M: usize, N: usize) -> Array2<f64> {
    let dt = T / M as f64;
    let mut paths = Array2::<f64>::zeros((M + 1, N));
    paths.row_mut(0).fill(S0);
    let mut rng = rand::thread_rng();
    for t in 1..=M {
        let z: Vec<f64> = (0..N).map(|_| rng.next_gaussian()).collect();
        paths.row_mut(t).iter_mut().zip(paths.row(t - 1).iter()).zip(z.iter()).for_each(|((path, prev), &zi)| {
            *path = *prev * (r - 0.5 * sigma.powi(2)) * dt + sigma * dt.sqrt() * zi;
        });
    }
    paths
}

fn price_option(paths: &Array2<f64>, strike: f64, T: f64, r: f64) -> f64 {
    let payoff = paths.row(paths.nrows() - 1).iter().map(|&S_T| (S_T - strike).max(0.0)).sum::<f64>() / paths.ncols() as f64;
    payoff * (-r * T).exp()
}

fn main() {
    let (S0, r, sigma, T, M, N, K) = (100.0, 0.05, 0.2, 1.0, 100, 1000, 100.0);
    let paths = generate_paths(S0, r, sigma, T, M, N);
    let option_price = price_option(&paths, K, T, r);
    println!("Option Price: {}", option_price);
}