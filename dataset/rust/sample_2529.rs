use rand::distributions::{Distribution, Normal};
use rand::thread_rng;

fn simulate_price_changes(steps: usize, initial_price: f64, volatility: f64) -> Vec<f64> {
    let mut prices = vec![initial_price];
    let normal = Normal::new(0.0, volatility);
    let mut rng = thread_rng();
    for _ in 0..steps {
        let change = normal.sample(&mut rng);
        prices.push(prices[prices.len() - 1] * (change.exp()));
    }
    prices
}

fn calculate_option_value(prices: &[f64], strike: f64, r: f64, T: f64) -> f64 {
    let mut value = 0.0;
    for &price in prices {
        value += (price - strike).max(0.0) * (-r * T).exp();
    }
    value / prices.len() as f64
}

fn main() {
    let initial_price = 100.0;
    let strike = 105.0;
    let r = 0.05;
    let T = 1.0;
    let volatility = 0.2;
    let steps = 1000;
    let prices = simulate_price_changes(steps, initial_price, volatility);
    let option_value = calculate_option_value(&prices, strike, r, T);
    println!("Option Value: {}", option_value);
}