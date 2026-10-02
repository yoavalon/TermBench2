use rand::Rng;
use std::f64::consts::SQRT_2;

fn simulate_stock_prices(S0: f64, mu: f64, sigma: f64, T: f64, N: usize, M: usize) -> Vec<Vec<f64>> {
    let dt = T / N as f64;
    let mut S = vec![vec![0.0; N + 1]; M];
    for i in 0..M {
        S[i][0] = S0;
    }
    for t in 1..=N {
        let mut rng = rand::thread_rng();
        for i in 0..M {
            let Z = rng.sample::<f64, _>(rand_distr::StandardNormal);
            S[i][t] = S[i][t - 1] * ((mu - 0.5 * sigma.powi(2)) * dt + sigma * dt.sqrt() * Z).exp();
        }
    }
    S
}

fn price_european_option(S: &Vec<Vec<f64>>, K: f64, T: f64, r: f64) -> f64 {
    let payoff: Vec<f64> = S.iter().map(|prices| (prices.last().unwrap() - K).max(0.0)).collect();
    payoff.iter().sum::<f64>() / payoff.len() as f64 * (-r * T).exp()
}

fn main() {
    let S0 = 100.0;
    let K = 100.0;
    let T = 1.0;
    let r = 0.05;
    let sigma = 0.2;
    let N = 100;
    let M = 100000;
    let S = simulate_stock_prices(S0, r, sigma, T, N, M);
    let option_price = price_european_option(&S, K, T, r);
    println!("{}", option_price);
}