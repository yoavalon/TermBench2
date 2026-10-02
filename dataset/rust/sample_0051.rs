use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn simulate_price(option_type: &str, S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let dt = T / N as f64;
    let dS = S0 * (r * dt + sigma * dt.sqrt());
    let mut prices = vec![S0];
    for _ in 1..=N {
        let mut rng = thread_rng();
        let gauss: f64 = Normal::new(0.0, 1.0).unwrap().sample(&mut rng);
        let S = prices[prices.len() - 1] + dS * gauss;
        prices.push(S);
    }
    let payoff = if option_type == "call" {
        f64::max(0.0, prices[prices.len() - 1] - K)
    } else {
        f64::max(0.0, K - prices[prices.len() - 1])
    };
    payoff
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 252;
    let M = 1000;
    let results: Vec<f64> = (0..M).map(|_| simulate_price("call", S0, K, T, r, sigma, N, M)).collect();
    let average_price = results.iter().sum::<f64>() / M as f64;
    println!("{}", average_price);
}