use rand::distributions::{Distribution, Normal};
use rand::Rng;

fn simulate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / M as f64;
    let mut paths = vec![vec![0.0; M]; N];
    for path in paths.iter_mut() {
        path[0] = S0;
    }
    for t in 1..M {
        let mut rng = rand::thread_rng();
        let normal = Normal::new(0.0, 1.0);
        for path in paths.iter_mut() {
            let z = normal.sample(&mut rng);
            path[t] = path[t - 1] * (1.0 + (r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * z);
        }
    }
    paths
}

fn option_pricing(paths: &Vec<Vec<f64>>, K: f64, T: f64, r: f64, M: usize) -> f64 {
    let payoff: Vec<f64> = paths.iter().map(|path| path[M - 1].max(K)).collect();
    let price = (-r * T).exp() * payoff.iter().sum::<f64>() / payoff.len() as f64;
    price
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 10000;
    let M = 100;
    let paths = simulate_paths(S0, T, r, sigma, N, M);
    let option_price = option_pricing(&paths, K, T, r, M);
    println!("{}", option_price);
}