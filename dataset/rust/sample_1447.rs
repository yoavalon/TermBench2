extern crate rand;
extern crate ndarray;

use rand::Rng;
use ndarray::Array2;

fn generate_paths(s0: f64, mu: f64, sigma: f64, dt: f64, T: f64, N: usize) -> Array2<f64> {
    let mut paths = Array2::<f64>::zeros((N, (T / dt) as usize + 1));
    paths.column_mut(0).fill(s0);
    for t in 1..=((T / dt) as usize) {
        let mut rng = rand::thread_rng();
        let z: Vec<f64> = (0..N).map(|_| rng.normal(0.0, 1.0)).collect();
        for i in 0..N {
            paths[[i, t]] = paths[[i, t - 1]] * ((mu - 0.5 * sigma * sigma) * dt + sigma * (dt.sqrt()) * z[i]).exp();
        }
    }
    paths
}

fn calculate_payoff(paths: &Array2<f64>, strike: f64, option_type: &str) -> Option<Array2<f64>> {
    if option_type == "call" {
        Some(paths.column(paths.ncols() - 1).map(|&x| x.max(strike - x)))
    } else if option_type == "put" {
        Some(paths.column(paths.ncols() - 1).map(|&x| x.max(strike - x)))
    } else {
        None
    }
}

fn monte_carlo_pricing(s0: f64, strike: f64, r: f64, T: f64, sigma: f64, N: usize, dt: f64, option_type: &str) -> f64 {
    let paths = generate_paths(s0, r, sigma, dt, T, N);
    let payoff = calculate_payoff(&paths, strike, option_type).unwrap();
    let discount_factor = (-r * T).exp();
    let option_price = discount_factor * payoff.mean().unwrap();
    option_price
}

fn main() {
    let s0 = 100.0;
    let strike = 100.0;
    let r = 0.05;
    let T = 1.0;
    let sigma = 0.2;
    let N = 10000;
    let dt = 0.01;
    let option_type = "call";
    let price = monte_carlo_pricing(s0, strike, r, T, sigma, N, dt, option_type);
    println!("{}", price);
}