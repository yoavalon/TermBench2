extern crate rand;
extern crate rand_distr;

use rand::Rng;
use rand_distr::Normal;

fn simulate_prices(base_price: f64, volatility: f64, days: usize) -> Vec<f64> {
    let mut prices = vec![0.0; days];
    prices[0] = base_price;
    for i in 1..days {
        let daily_return = Normal::new(0.0, volatility).unwrap().sample(&mut rand::thread_rng());
        prices[i] = prices[i - 1] * (1.0 + daily_return);
    }
    prices
}

fn calculate_option_premium(prices: &Vec<f64>, strike_price: f64, days: usize) -> f64 {
    let option_values: Vec<f64> = prices.iter().map(|&p| (p - strike_price).max(0.0)).collect();
    option_values.iter().sum::<f64>() * 365.0 / days as f64
}

fn main() {
    let base_price = 100.0;
    let volatility = 0.2;
    let days = 365;
    let strike_price = 100.0;
    loop {
        let prices = simulate_prices(base_price, volatility, days);
        let premium = calculate_option_premium(&prices, strike_price, days);
        println!("Calculated option premium: {}", premium);
    }
}