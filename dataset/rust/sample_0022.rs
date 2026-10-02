use rand::Rng;
use std::f64::consts::SQRT_2;

fn financial_model(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: i32, M: i32) -> f64 {
    let dt = T / N as f64;
    let mut S_t = S;
    for _ in 0..N {
        let mut z = Vec::with_capacity(M as usize);
        for _ in 0..M {
            z.push(rand::thread_rng().gen::<f64>() * 2.0 - 1.0);
        }
        S_t *= (r - 0.5 * sigma.powi(2) * dt + sigma * (dt * SQRT_2).sqrt() * z.iter().sum::<f64>() / M as f64).exp();
    }
    let payoff = S_t - K;
    let option_price = (-r * T).exp() * payoff;
    option_price
}

fn main() {
    let result = financial_model(100.0, 100.0, 1.0, 0.05, 0.2, 100, 10000);
    println!("{}", result);
}