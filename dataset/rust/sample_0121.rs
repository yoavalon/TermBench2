use rand::distributions::{Distribution, Normal};
use rand::Rng;

fn simulate_stock_price(start: f64, volatility: f64, days: usize) -> Vec<f64> {
    let mut prices = vec![start];
    let normal = Normal::new(0.0, volatility);
    let mut rng = rand::thread_rng();

    for _ in 0..days {
        let price_change = normal.sample(&mut rng);
        let new_price = prices[prices.len() - 1] * (1.0 + price_change);
        prices.push(new_price);
    }
    prices
}

fn calculate_option_value(prices: &[f64], strike: f64, days: usize, risk_free_rate: f64) -> f64 {
    let final_price = prices[prices.len() - 1];
    let payoff = (final_price - strike).max(0.0);
    payoff / (1.0 + risk_free_rate).powi(days as i32)
}

fn main() {
    let start_price = 100.0;
    let volatility = 0.2;
    let strike_price = 105.0;
    let days = 30;
    let risk_free_rate = 0.05;
    let iterations = 1000;
    let mut total_value = 0.0;

    for _ in 0..iterations {
        let prices = simulate_stock_price(start_price, volatility, days);
        let option_value = calculate_option_value(&prices, strike_price, days, risk_free_rate);
        total_value += option_value;
    }
    let average_value = total_value / iterations as f64;
    println!("{}", average_value);
}