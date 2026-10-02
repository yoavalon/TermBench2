use rand::Rng;
use rand_distr::{Distribution, Normal};

fn simulate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![0.0; M]; N + 1];
    paths[0].iter_mut().for_each(|x| *x = S0);
    for t in 1..=N {
        let mut rng = rand::thread_rng();
        let normal = Normal::new(0.0, 1.0).unwrap();
        let z: Vec<f64> = (0..M).map(|_| normal.sample(&mut rng)).collect();
        for m in 0..M {
            paths[t][m] = paths[t - 1][m] * ((r - 0.5 * sigma.powi(2)) * dt + sigma * dt.sqrt() * z[m]).exp();
        }
    }
    paths
}

fn payoff_function(paths: &Vec<Vec<f64>>, K: f64, option_type: &str) -> Vec<f64> {
    if option_type == "call" {
        paths.last().unwrap().iter().map(|&S| (S - K).max(0.0)).collect()
    } else if option_type == "put" {
        paths.last().unwrap().iter().map(|&S| (K - S).max(0.0)).collect()
    } else {
        vec![0.0; paths.last().unwrap().len()]
    }
}

fn price_option(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize, option_type: &str) -> f64 {
    let paths = simulate_paths(S0, T, r, sigma, N, M);
    let payoff = payoff_function(&paths, K, option_type);
    let payoff_mean: f64 = payoff.iter().sum::<f64>() / payoff.len() as f64;
    (-r * T).exp() * payoff_mean
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 252;
    let M = 10000;
    let option_type = "call";
    let option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    println!("Option Price: {}", option_price);
}