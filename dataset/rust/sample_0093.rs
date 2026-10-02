use rand::Rng;
use rand_distr::{Distribution, Normal};

fn monte_carlo_pricing(S0: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let dt = T / M as f64;
    let mut S = vec![vec![0.0; N]; M + 1];
    S[0] = vec![S0; N];
    for t in 1..=M {
        let normal = Normal::new(0.0, 1.0).unwrap();
        let Z: Vec<f64> = (0..N).map(|_| normal.sample(&mut rand::thread_rng())).collect();
        S[t] = S[t - 1].iter().zip(Z.iter()).map(|(&st, &z)| {
            st * (r - 0.5 * sigma.powi(2) * dt).exp() + sigma * dt.sqrt() * z
        }).collect();
    }
    let payoff: Vec<f64> = S[M].iter().map(|&st| (st - K).max(0.0)).collect();
    (-r * T).exp() * payoff.iter().sum::<f64>() / N as f64
}

fn main() {
    monte_carlo_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 10000, 100);
}