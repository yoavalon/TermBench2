use rand::distributions::{Normal, Distribution};
use rand::Rng;
use std::f64::consts::E;

fn generate_paths(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let mut paths = vec![vec![S0]; M];
    let dt = T / N as f64;
    let normal = Normal::new(0.0, 1.0);
    let mut rng = rand::thread_rng();

    for i in 1..=N {
        for j in 0..M {
            let Z = normal.sample(&mut rng);
            let S = paths[j][i - 1] * E.powf((mu - 0.5 * sigma.powi(2)) * dt + sigma * (dt.powf(0.5)) * Z);
            paths[j].push(S);
        }
    }
    paths
}

fn payoff_function(S: f64, K: f64, option_type: &str) -> f64 {
    if option_type == "call" {
        f64::max(S - K, 0.0)
    } else if option_type == "put" {
        f64::max(K - S, 0.0)
    } else {
        0.0
    }
}

fn monte_carlo_pricing(paths: Vec<Vec<f64>>, K: f64, r: f64, T: f64, option_type: &str) -> f64 {
    let payoffs: Vec<f64> = paths.iter().map(|path| payoff_function(path[path.len() - 1], K, option_type)).collect();
    let present_value = (payoffs.iter().sum::<f64>() / payoffs.len() as f64) * E.powf(-r * T);
    present_value
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let r = 0.05;
    let T = 1.0;
    let N = 100;
    let M = 10000;
    let option_type = "call";
    let paths = generate_paths(S0, r, 0.2, T, N, M);
    let price = monte_carlo_pricing(paths, K, r, T, option_type);
    println!("Option price: {}", price);
}