use rand::Rng;
use rand_distr::{Distribution, Normal};

fn run_model(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let dt = T / N as f64;
    let mut ST = vec![vec![0.0; N + 1]; M];
    let normal = Normal::new(0.0, 1.0).unwrap();

    for i in 0..M {
        ST[i][0] = S;
        for j in 0..N {
            let z = normal.sample(&mut rand::thread_rng());
            ST[i][j + 1] = ST[i][j] * ((r - 0.5 * sigma * sigma) * dt + sigma * (dt.sqrt() * z));
        }
    }

    for i in 0..M {
        for j in 1..=N {
            ST[i][j] += ST[i][j - 1];
        }
    }

    let mut payoff = vec![0.0; M];
    for i in 0..M {
        payoff[i] = (ST[i][N] - K).max(0.0);
    }

    let option_price = (-r * T).exp() * payoff.iter().sum::<f64>() / M as f64;
    option_price
}

fn main() {
    run_model(100.0, 100.0, 1.0, 0.05, 0.2, 252, 10000);
}