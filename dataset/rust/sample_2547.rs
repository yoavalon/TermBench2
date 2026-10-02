extern crate rand;
use rand::distributions::{Normal, Distribution};

fn simulate_stock_price(days: usize, initial_price: f64, volatility: f64) -> Vec<f64> {
    let mut price = initial_price;
    let mut prices = vec![price];
    for _ in 0..days {
        let normal = Normal::new(0.0, 1.0);
        price *= 1.0 + volatility * normal.sample(&mut rand::thread_rng());
        prices.push(price);
    }
    prices
}

fn calculate_option_value(prices: &[f64], strike_price: f64, days: usize, risk_free_rate: f64) -> f64 {
    let final_price = prices[prices.len() - 1];
    let payoff = if final_price - strike_price > 0.0 { final_price - strike_price } else { 0.0 };
    let discount_factor = 1.0 / (1.0 + risk_free_rate).powi(days as i32);
    payoff * discount_factor
}

fn main() {
    let days = 30;
    let initial_price = 100.0;
    let volatility = 0.2;
    let strike_price = 105.0;
    let risk_free_rate = 0.05;
    let prices = simulate_stock_price(days, initial_price, volatility);
    let option_value = calculate_option_value(&prices, strike_price, days, risk_free_rate);
    println!("Option value: {}", option_value);
}