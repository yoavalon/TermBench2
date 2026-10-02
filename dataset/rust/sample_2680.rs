use rand::distributions::{Distribution, Normal};
use rand::thread_rng;

fn generate_prices(num_days: usize, initial_price: f64, volatility: f64) -> Vec<f64> {
    let mut prices = vec![initial_price];
    for _ in 0..(num_days - 1) {
        let change = Normal::new(0.0, volatility).sample(&mut thread_rng());
        let new_price = prices.last().unwrap() * (1.0 + change);
        prices.push(new_price);
    }
    prices
}

fn calculate_payoffs(prices: &[f64], strike_price: f64, call_or_put: &str) -> Vec<f64> {
    prices.iter().map(|&price| {
        if call_or_put == "call" {
            f64::max(price - strike_price, 0.0)
        } else {
            f64::max(strike_price - price, 0.0)
        }
    }).collect()
}

fn monte_carlo_pricing(num_simulations: usize, num_days: usize, initial_price: f64, strike_price: f64, volatility: f64, call_or_put: &str, risk_free_rate: f64, time_to_maturity: f64) -> f64 {
    let mut total_payoff = 0.0;
    for _ in 0..num_simulations {
        let prices = generate_prices(num_days, initial_price, volatility);
        let payoffs = calculate_payoffs(&prices, strike_price, call_or_put);
        let discounted_payoff = payoffs.iter().sum::<f64>() / payoffs.len() as f64 * (1.0 + risk_free_rate).powf(-time_to_maturity);
        total_payoff += discounted_payoff;
    }
    total_payoff / num_simulations as f64
}

fn main() {
    let num_simulations = 1000;
    let num_days = 365;
    let initial_price = 100.0;
    let strike_price = 100.0;
    let volatility = 0.2;
    let call_or_put = "call";
    let risk_free_rate = 0.05;
    let time_to_maturity = 1.0;
    let option_price = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity);
    println!("Option price: {}", option_price);
}