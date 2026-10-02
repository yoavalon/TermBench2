use rand::Rng;
use rand_distr::{Normal, Distribution};

fn simulate_paths(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![0.0; M]; N + 1];
    paths[0].fill(S0);
    for i in 1..=N {
        let mut rng = rand::thread_rng();
        let normal = Normal::new(0.0, 1.0).unwrap();
        let Z: Vec<f64> = (0..M).map(|_| normal.sample(&mut rng)).collect();
        for j in 0..M {
            paths[i][j] = paths[i - 1][j] * ((r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * Z[j]).exp();
        }
    }
    paths
}

fn calculate_payoffs(paths: &Vec<Vec<f64>>, K: f64, T: f64, r: f64, M: usize) -> f64 {
    let S_T = &paths[paths.len() - 1];
    let payoff: Vec<f64> = S_T.iter().map(|&x| (x - K).max(0.0)).collect();
    let option_value = payoff.iter().sum::<f64>() / M as f64 * (-r * T).exp();
    option_value
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 252;
    let M = 100000;
    loop {
        let paths = simulate_paths(S0, K, T, r, sigma, N, M);
        let option_value = calculate_payoffs(&paths, K, T, r, M);
        println!("{}", option_value);
    }
}