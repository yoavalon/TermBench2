use rand::Rng;
use rand_distr::{Normal, Distribution};

fn simulate_paths(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut S = vec![vec![0.0; M]; N + 1];
    S[0].iter_mut().for_each(|s| *s = S0);
    for i in 1..=N {
        let normal = Normal::new(0.0, 1.0).unwrap();
        let Z: Vec<f64> = (0..M).map(|_| normal.sample(&mut rand::thread_rng())).collect();
        for j in 0..M {
            S[i][j] = S[i - 1][j] * ((r - 0.5 * sigma.powi(2)) * dt + sigma * dt.sqrt() * Z[j]).exp();
        }
    }
    S
}

fn option_price(paths: Vec<Vec<f64>>, K: f64, r: f64, T: f64) -> f64 {
    let payoff: Vec<f64> = paths.last().unwrap().iter().map(|&s| s - K).map(|x| x.max(0.0)).collect();
    let price = payoff.iter().sum::<f64>() / payoff.len() as f64 * (-r * T).exp();
    price
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let paths = simulate_paths(S0, K, T, r, sigma, N, M);
    let price = option_price(paths, K, r, T);
    println!("{}", price);
}