use rand::Rng;
use rand_distr::{Normal, Distribution};

fn simulate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![0.0; M]; N + 1];
    paths[0].iter_mut().for_each(|x| *x = S0);
    for i in 1..=N {
        let mut rng = rand::thread_rng();
        let normal = Normal::new(0.0, 1.0).unwrap();
        let z: Vec<f64> = (0..M).map(|_| normal.sample(&mut rng)).collect();
        paths[i] = paths[i - 1].iter().zip(z.iter()).map(|(&S, &z)| S * (r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * z).collect();
    }
    paths
}

fn calculate_payoff(paths: &Vec<Vec<f64>>, K: f64, T: f64) -> Vec<f64> {
    let ST = &paths[paths.len() - 1];
    ST.iter().map(|&ST| (ST - K).max(0.0)).collect()
}

fn monte_carlo_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let paths = simulate_paths(S0, T, r, sigma, N, M);
    let payoff = calculate_payoff(&paths, K, T);
    let option_price = payoff.iter().sum::<f64>() / M as f64 * (-r * T).exp();
    option_price
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let price = monte_carlo_pricing(S0, K, T, r, sigma, N, M);
    println!("Option Price: {}", price);
}