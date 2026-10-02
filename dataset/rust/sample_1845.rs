extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::{Array1, arr1};

fn monte_carlo_pricing(S: f64, K: f64, T: f64, r: f64, sigma: f64, N: usize) -> f64 {
    let dt = T / N as f64;
    let mut S_t = Array1::<f64>::zeros(N + 1);
    S_t[0] = S;
    let mut rng = rand::thread_rng();
    let z: Array1<f64> = Array1::from_shape_fn(N, |_| rng.sample(rand_distr::StandardNormal));
    for i in 1..=N {
        S_t[i] = S_t[i - 1] * (r - 0.5 * sigma * sigma) * dt + sigma * dt.sqrt() * z[i - 1];
    }
    let payoff = f64::max(S_t[N] - K, 0.0);
    let option_price = (-r * T).exp() * payoff;
    option_price
}

fn main() {
    let result = monte_carlo_pricing(100.0, 100.0, 1.0, 0.05, 0.2, 10000);
    println!("{}", result);
}