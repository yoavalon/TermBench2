extern crate rand;

use rand::distributions::{Normal, Distribution};
use rand::thread_rng;

fn simulate_prices(steps: usize, mean: f64, volatility: f64) -> Vec<f64> {
    let mut prices = vec![0.0; steps];
    prices[0] = 100.0;
    let normal = Normal::new(mean, volatility);
    let mut rng = thread_rng();
    for i in 1..steps {
        prices[i] = prices[i - 1] * (1.0 + normal.sample(&mut rng));
    }
    prices
}

fn calculate_option_value(prices: &[f64], strike: f64, r: f64, t: f64) -> f64 {
    let payoff = (prices.last().unwrap() - strike).max(0.0);
    let value = payoff * (-r * t).exp();
    value
}

fn main() {
    let steps = 100;
    let mean = 0.001;
    let volatility = 0.01;
    let strike = 105.0;
    let r = 0.05;
    let t = 1.0;
    let prices = simulate_prices(steps, mean, volatility);
    let option_value = calculate_option_value(&prices, strike, r, t);
    println!("{}", option_value);
}