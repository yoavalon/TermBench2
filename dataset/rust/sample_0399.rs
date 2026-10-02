use rand::Rng;
use std::f64::consts::SQRT_2;

fn financial_model(S0: f64, K: f64, T: f64, r: f64, sigma: f64) -> f64 {
    let N = 10000;
    let dt = T / N as f64;
    let mut S = vec![vec![0.0; N + 1]; N + 1];
    S[0][0] = S0;
    for t in 1..=N {
        for i in 0..=t {
            let Z = rand::thread_rng().sample(rand_distr::StandardNormal);
            S[t][i] = S[t - 1][i - 1] * ((r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * Z).exp();
        }
    }
    S[N].iter().map(|&s| (s - K).max(0.0)).sum::<f64>() / N as f64
}

fn main() {
    println!("{}", financial_model(100.0, 100.0, 1.0, 0.05, 0.2));
}