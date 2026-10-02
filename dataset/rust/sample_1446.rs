use rand::Rng;
use std::f64::consts::PI;

fn generate_paths(S0: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut paths = vec![vec![0.0; M]; N + 1];
    paths[0] = vec![S0; M];
    for t in 1..=N {
        let mut z = vec![0.0; M];
        for i in 0..M {
            z[i] = rand::thread_rng().gen::<f64>() * 2.0 - 1.0;
        }
        for i in 0..M {
            paths[t][i] = paths[t - 1][i] * ((r - 0.5 * sigma.powi(2)) * dt + sigma * (dt as f64).sqrt() * z[i]).exp();
        }
    }
    paths
}

fn calculate_payoffs(paths: &Vec<Vec<f64>>, K: f64, option_type: &str) -> Vec<f64> {
    if option_type == "call" {
        paths.last().unwrap().iter().map(|&S| (S - K).max(0.0)).collect()
    } else if option_type == "put" {
        paths.last().unwrap().iter().map(|&S| (K - S).max(0.0)).collect()
    } else {
        vec![0.0; paths[0].len()]
    }
}

fn price_option(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize, option_type: &str) -> f64 {
    let paths = generate_paths(S0, T, r, sigma, N, M);
    let payoffs = calculate_payoffs(&paths, K, option_type);
    payoffs.iter().sum::<f64>() / payoffs.len() as f64 * (-r * T).exp()
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let option_type = "call";
    let option_price = price_option(S0, K, T, r, sigma, N, M, option_type);
    println!("Option price: {:.2}", option_price);
}