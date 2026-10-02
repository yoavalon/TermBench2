use rand::Rng;
use std::f64;

fn monte_carlo_pricing(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize, M: usize) -> f64 {
    let dt = T / M as f64;
    let mut S_t = vec![vec![0.0; M + 1]; N];
    for i in 0..N {
        S_t[i][0] = S;
    }
    for t in 1..=M {
        let mut rng = rand::thread_rng();
        let z: Vec<f64> = (0..N).map(|_| rng.next_gaussian()).collect();
        for i in 0..N {
            S_t[i][t] = S_t[i][t - 1] * ((r - 0.5 * sigma.powi(2)) * dt + sigma * (dt as f64).sqrt() * z[i]).exp();
        }
    }
    let payoff: f64 = S_t.iter().map(|row| row.last().unwrap().max(&0.0)).sum();
    let option_price = (-r * T).exp() * (payoff / N as f64);
    option_price
}

fn main() {
    let result = monte_carlo_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 10000, 100);
    println!("{}", result);
}