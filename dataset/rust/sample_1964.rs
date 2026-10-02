use rand::distributions::{Normal, Distribution};
use rand::Rng;

fn simulate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![0.0; N + 1]; M];
    for path in paths.iter_mut() {
        path[0] = S0;
    }
    for t in 1..=N {
        let mut rng = rand::thread_rng();
        let normal = Normal::new(0.0, 1.0);
        for (i, path) in paths.iter_mut().enumerate() {
            let z = normal.sample(&mut rng);
            path[t] = path[t - 1] * (mu - 0.5 * sigma.powi(2) * dt + sigma * (dt.sqrt() * z)).exp();
        }
    }
    paths
}

fn option_price(paths: Vec<Vec<f64>>, K: f64, r: f64, T: f64) -> f64 {
    let payoff: Vec<f64> = paths.iter().map(|path| path.last().unwrap().max(K)).collect();
    let mean_payoff = payoff.iter().sum::<f64>() / payoff.len() as f64;
    mean_payoff * (-r * T).exp()
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
    println!("Option price: {:.2}", price);
}