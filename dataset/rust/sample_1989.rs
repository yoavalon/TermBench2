use rand::distributions::Normal;
use rand::Rng;
use std::vec::Vec;

fn simulate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![0.0; M]; N + 1];
    paths[0] = vec![S0; M];
    for t in 1..=N {
        let mut rand = Normal::new(0.0, 1.0).sample_iter(&mut rand::thread_rng()).take(M).collect::<Vec<f64>>();
        paths[t] = paths[t - 1].iter().zip(rand.iter()).map(|(&s, &r)| s * (mu - 0.5 * sigma * sigma) * dt.exp() + sigma * (dt.sqrt() * r).exp()).collect();
    }
    paths
}

fn option_price(paths: Vec<Vec<f64>>, K: f64, r: f64, T: f64) -> f64 {
    let payoff = paths.last().unwrap().iter().map(|&s| s.max(K - s)).sum::<f64>() / paths.last().unwrap().len() as f64;
    payoff * (-r * T).exp()
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let r = 0.05;
    let T = 1.0;
    let N = 252;
    let M = 10000;
    let paths = simulate_paths(S0, r, 0.2, T, N, M);
    let price = option_price(paths, K, r, T);
    println!("Option Price: {:.4}", price);
}