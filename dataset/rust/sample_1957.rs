extern crate rand;
use rand::distributions::{Normal, Distribution};

fn simulate_prices(steps: usize, simulations: usize) -> Vec<Vec<f64>> {
    let normal = Normal::new(0.05, 0.2);
    let mut rng = rand::thread_rng();
    (0..simulations)
        .map(|_| (0..steps).map(|_| normal.sample(&mut rng)).collect())
        .collect()
}

fn calculate_option_value(prices: Vec<Vec<f64>>, strike: f64) -> f64 {
    let final_prices: Vec<f64> = prices.into_iter().map(|p| p.last().unwrap()).collect();
    final_prices.into_iter().map(|p| (p - strike).max(0.0)).sum::<f64>() / final_prices.len() as f64
}

fn main() {
    let steps = 100;
    let simulations = 1000;
    let strike = 100.0;
    let prices = simulate_prices(steps, simulations);
    let value = calculate_option_value(prices, strike);
    println!("{}", value);
}