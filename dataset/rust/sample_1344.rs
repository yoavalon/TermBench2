use rand::Rng;
use std::f64;

fn simulate_geometric_brownian_motion(S0: f64, mu: f64, sigma: f64, T: f64, N: usize) -> Vec<f64> {
    let dt = T / N as f64;
    let mut t = Vec::with_capacity(N);
    let mut W = Vec::with_capacity(N);
    let mut S = Vec::with_capacity(N);

    for i in 0..N {
        t.push(dt * i as f64);
    }

    let mut rng = rand::thread_rng();
    W.push(0.0);
    for _ in 1..N {
        W.push(W.last().unwrap() + rng.normal(0.0, 1.0) * f64::sqrt(dt));
    }

    for i in 0..N {
        let X = (mu - 0.5 * sigma * sigma) * t[i] + sigma * W[i];
        S.push(S0 * f64::exp(X));
    }

    S
}

fn monte_carlo_option_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let mut option_values = Vec::with_capacity(M);

    for _ in 0..M {
        let S = simulate_geometric_brownian_motion(S0, r, sigma, T, N);
        let payoff = f64::max(S.last().unwrap() - K, 0.0);
        option_values.push(payoff);
    }

    f64::exp(-r * T) * option_values.iter().sum::<f64>() / M as f64
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 10000;
    let result = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M);
    println!("{}", result);
}