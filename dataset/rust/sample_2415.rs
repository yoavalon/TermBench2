use rand::Rng;
use std::f64::consts::SQRT_2;

fn simulate_option_price(S0: f64, K: f64, T: f64, r: f64, sigma: f64, steps: usize, trials: usize) -> f64 {
    let dt = T / steps as f64;
    let mut rng = rand::thread_rng();
    let mut S = vec![S0; trials];
    let mut payoff = 0.0;

    for _ in 0..steps {
        let dW: Vec<f64> = (0..trials).map(|_| rng.normal(0.0, dt.sqrt())).collect();
        for i in 0..trials {
            S[i] *= (r - 0.5 * sigma * sigma) * dt + sigma * dW[i];
        }
    }

    for &s in &S {
        payoff += f64::max(s - K, 0.0);
    }

    payoff / trials as f64 * (-r * T).exp()
}

fn main() {
    let result = simulate_option_price(100.0, 100.0, 1.0, 0.05, 0.2, 100, 1000);
    println!("{}", result);
}